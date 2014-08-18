//ActListener2.java
import javax.swing.*;
import java.awt.event.*;

public class ActListener2 implements ActionListener {
    JButton button;
    boolean fButton = true;

    ActListener2( JButton button ) {
        this.button = button;
    }

    public void actionPerformed( ActionEvent ae ) {
        if( fButton ) {
            button.setText( "Press" );
            fButton = false;
        }
        else {
            button.setText( "Button" );
            fButton = true;
        }
    }
}