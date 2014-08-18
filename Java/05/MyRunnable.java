//MyRunnable.java

public class MyRunnable implements Runnable {
    char mes;
    long sleeptime;

    public MyRunnable( char mes, long sleeptime ) {
        this.mes = mes;
        this.sleeptime = sleeptime;
    }

    public void run() {
        for( int i = 0; (char)((int)mes + i ) != '9'+1 && (char)((int)mes + i ) != 'Z'+1 
                 && (char)((int)mes + i ) != '¤ó'+1; i++ ) {
            try {
                System.out.println( (char)((int)mes + i ) );
            }
            catch( ArrayIndexOutOfBoundsException ia ) {
                break;
            }
            
            try {
                Thread.sleep( sleeptime );
            }
            catch( InterruptedException is ) {
                is.printStackTrace();
            }
        }
    }
}