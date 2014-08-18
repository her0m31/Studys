//ButtonAction.java
import javax.swing.*;
import java.awt.*;

public class ButtonAction extends JFrame {
    ButtonAction() {
        super( "Button Action" );

        Container myContainer = getContentPane();
        JButton mybutton = new JButton( "Button" );
        myContainer.add( mybutton );
        
        setSize( 150, 100 );
        setVisible( true );

        mybutton.addActionListener( new ActListener2( mybutton ) );
        
        addWindowListener( new WinAdapter() );
    }

    public static void main( String [] args ) {
        ButtonAction buttonAction = new ButtonAction();
    }
}