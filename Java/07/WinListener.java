//WinListener.java
import java.awt.event.*;

public class WinListener implements WindowListener {
    public void windowClosing( WindowEvent we ) {
        System.out.println( 0 );
    }

    public void windowOpened( WindowEvent we ) {}
    public void windowClosed( WindowEvent we ) {}
    public void windowIconified( WindowEvent we ) {}
    public void windowDeiconified( WindowEvent we ) {}
    public void windowActivated( WindowEvent we ) {}
    public void windowDeactivated( WindowEvent we ) {}
}