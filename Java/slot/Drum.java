//Drum.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class Drum extends JPanel implements Runnable {
    protected boolean running;
    String [] drum;
    long sleeptime;
    JLabel l1, l2, l3;
    
    public Drum( String [] drum, long sleeptime ) {
        this.drum      = drum;
        this.sleeptime = sleeptime;
        
        l1 = new JLabel( drum[0] );
        l1.setFont( new Font( "SanSerif", Font.PLAIN, 70) );
        l2 = new JLabel( drum[1] );
        l2.setFont( new Font( "SanSerif", Font.PLAIN, 70) );
        l3 = new JLabel( drum[2] );
        l3.setFont( new Font( "SanSerif", Font.PLAIN, 70) );
        setLayout( new GridLayout( 3, 1, 20, 10 ) );
        add( l1 );
        add( l2 );
        add( l3 );
    }
    
    public void run() {
        for( int i = 1; running; i++ ) {
            if( i > 19 ) {
                i = 1;
            }
            
            drumRepaint( i );
           
            try {
                Thread.sleep( sleeptime );
            }
            catch( InterruptedException ie ) {
                ie.printStackTrace();
            }
        }
    }
    
    void rollStart() {
        if( running == false ) {
            running = true;
            Thread t = new Thread( this );
            t.start();
        }
    }
    
    void rollStop() {
        running = false;
    }
    
    private void drumRepaint( int i ) {
        l1.setText( drum[i-1] );
        l2.setText( drum[ i ] );
        l3.setText( drum[i+1] );
    }
}