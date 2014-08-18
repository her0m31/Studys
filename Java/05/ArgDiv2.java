// ArgDiv2.java

public class ArgDiv2 {
    public static void main( String [] args ) {
        
        try {
            int val1 = Integer.parseInt( args[0] );
        }
        catch( ArrayIndexOutOfBoundsException param1 ) {
            System.out.println( "引数無し" );
            return;
        }
        catch( NumberFormatException param2 ) {
            System.out.println( "引数が数字では無い" );
            return;
        }
        catch( Exception param3 ) {
            System.out.println( "その他の例外" );
            param3.printStackTrace();
        }
        finally {
            System.out.println( "finally内の処理1" );
        }

        try {
            int val2 = Integer.parseInt( args[1] );
        }
        catch( ArrayIndexOutOfBoundsException param4 ) {
            System.out.println( "引数無し" );
            return;
        }
        catch( NumberFormatException param5 ) {
            System.out.println( "引数が数字では無い" );
            return;
        }
        catch( Exception param7 ) {
            System.out.println( "その他の例外" );
            param7.printStackTrace();
        }
        finally {
            System.out.println( "finally内の処理2" );
        }
        
        int val1 = Integer.parseInt( args[0] );
        int val2 = Integer.parseInt( args[1] );

        try {
            System.out.println( val1 + " / " + val2 + " = " + val1/val2 );
        }
        catch( ArithmeticException param8 ){
            System.out.println( "ゼロ除算" );
            return;
        }   
            

    }
}