//WinAdapter.java
import java.awt.event.*;

public class WinAdapter extends WindowAdapter {
    public void windowClosing( WindowEvent we ) {
        System.exit( 0 );
    }
}