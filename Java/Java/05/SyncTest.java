//SyncTest.java

public class SyncTest {
    public static void main( String [] args ) {
        Increment inc = new Increment();   
        Thread t1 = new Thread( new ExecIncrement( inc, 'A',  1000 ) );
        Thread t2 = new Thread( new ExecIncrement( inc, '0',  3000 ) );
        Thread t3 = new Thread( new ExecIncrement( inc, 'дв',  500 ) );
        
        t1.start();
        t2.start();
        t3.start();
    }
}