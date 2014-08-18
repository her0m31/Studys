//MyChoice.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class MyChoice extends JFrame {
    public MyChoice() {
        super( "DaisLab" );

        Container myContainer = getContentPane();
        myContainer.setLayout( new GridLayout( 3, 2, 5, 10) );

        JPanel p  = new JPanel( new GridLayout() );
        JLabel l1 = new JLabel( "0312014142" );
        JLabel l2 = new JLabel( "Æ£¥±Ã« ÂóÌ´" );
        JLabel l3 = new JLabel( "isusi007" );
        p.add( l1 );
        p.add( l2 );
        p.add( l3 );
        
        myContainer.add( p );

        pack();
        setVisible( true );

        addWindowListener( new WindowAdapter() {
                public void windowClosing( WindowEvent we ) {
                    System.exit(0);
                }
            } );
    }

    public static void main( String [] args ) {
        MyChoice p0 = new MyChoice();
    }
}