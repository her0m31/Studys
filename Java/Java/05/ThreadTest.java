//ThreadTest.java

public class ThreadTest {
    public static void main( String [] args ) {
        
        Thread x = new MyThread(   'A', 1000 );
        Thread y = new MyThread(   '0', 1500 );
        Thread z = new MyThread(  '��',  500 );
        x.start();
        y.start();
        z.start();
        System.out.println( "Main thread is over." );
    }
}