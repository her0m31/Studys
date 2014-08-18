//ArgsSample.java

public class ArgsSample {
    public static void main(String [] args) {
        int i;

        System.out.println( "引数の個数: " + args.length );
        for( i = 0; i < args.length; i++ ) {
            System.out.println(" 引数" + i + ": " +args[i] );
        }
    }
}