//MyFrame.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    MyFrame() {
        super( "DaisLab" );
        
        Container myContainer1 = getContentPane();
        JLabel myLabel1 = new JLabel( "Æ£¥±Ã«¡¡ÂóÌ´ Takumu Fujigaya" );
        myContainer1.add( myLabel1 );

        setSize( 250, 70 );
        setVisible( true );

        addWindowListener( new WindowAdapter() {
                public void windowClosing( WindowEvent we ) {
                    System.exit( 0 );
                }
            } );
    }

    public static void main( String [] args ) {
        MyFrame myFrame = new MyFrame();
    }
}