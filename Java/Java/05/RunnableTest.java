//RunnableTest.java

public class RunnableTest {
    public static void main( String [] args ) {
        Runnable cmd1 = new MyRunnable(  'A', 1000 );
        Runnable cmd2 = new MyRunnable(  '0', 3000 );
        Runnable cmd3 = new MyRunnable(  'дв',  500 );

        Thread x = new Thread( cmd1 );
        Thread y = new Thread( cmd2 );
        Thread z = new Thread( cmd3 );
                
        x.start();
        y.start();
        z.start();
        System.out.println( "Main thread is over." );
    }
}