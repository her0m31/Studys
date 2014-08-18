//MyThread.java

public class MyThread extends Thread {
    char mes;
    long sleeptime;
    
    public MyThread( char mes, long sleeptime ) {
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
