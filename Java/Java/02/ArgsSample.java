//ArgsSample.java

public class ArgsSample {
    public static void main(String [] args) {
        int i;

        System.out.println( "�����θĿ�: " + args.length );
        for( i = 0; i < args.length; i++ ) {
            System.out.println(" ����" + i + ": " +args[i] );
        }
    }
}