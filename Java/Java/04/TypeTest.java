//TypeTest.java

class TypeA {
    String name;
    public TypeA( String n ) {
        name = n;
    }
}

class TypeB1 extends TypeA {
    public TypeB1( String n ) {
        super( n );
    }
}

class TypeB2 extends TypeA {
    public TypeB2( String n ) {
        super( n );
    }
}

public class TypeTest {
    public static void main( String [] args ) {
        boolean b1, b2, b3, b4;

        TypeA  a = new TypeA( "a" );
        TypeB1 b = new TypeB1( "b" );
        TypeA  c = new TypeB2( "c" );

        b1 = ( a instanceof TypeB1);
        b2 = ( b instanceof TypeA);  
        b3 = ( c instanceof TypeB1);    
        b4 = ( c instanceof TypeB2);

        System.out.println( b1 );
        System.out.println( b2 );
        System.out.println( b3 ); 
        System.out.println( b4 );
    }
}