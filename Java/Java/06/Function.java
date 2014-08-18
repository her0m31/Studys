//Function.java

public class Function {
    
    public double f( double x ) {
        return 1 - Math.pow( Math.E,  -2 * Math.pow( x, 2.0 ) ) ;
    }

    public double g( double x ) {
        return ( 1/3 * Math.pow( x, 3.0 ) ) - ( -4 * Math.pow( x, 2.0 ) ) + ( 15.0 * x ) + 3;
    }
    
    public double h( double x ) {
        return ( 2/Math.PI * Math.asin(x) ) + 2/Math.PI * x * Math.sqrt( 1 - Math.pow( x, 2 ) );
    }

    public int r( int k ) {
        int comp = (int)(Math.floor(Math.random() * k) + 1);
        for( int i = 1; i < k; i++ ) {
            int rand = (int)(Math.floor(Math.random() * k) + 1);
            
            if( comp < rand ) {
                comp = rand;
            }
        }
        return comp;
    }

    public static void main( String [] args ) {
        Function f1 = new Function();
        System.out.println( "f(-0.3) = " + f1.f( -0.3 ) );
        System.out.println( "f( 0.7) = " + f1.f(  0.7 ) );
        for(int i = 1; i < 13; i++) {
            System.out.println( "g(" + i + ")    = " + f1.g( i ) );
        }
        System.out.println( "h(-PI/8) = " + f1.h( -Math.PI/8 ) );
        System.out.println( "h( PI/4) = " + f1.h(  Math.PI/4 ) );
        System.out.println( "r(99)    = " + f1.r( 99 ) );
    }
}