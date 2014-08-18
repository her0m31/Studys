//Increment.java

public class Increment {
    synchronized void calc( char mes, long sleeptime ) {
        for( int i = 0;  (char)((int)mes + i ) != '9'+1 && (char)((int)mes + i ) != 'Z'+1 
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