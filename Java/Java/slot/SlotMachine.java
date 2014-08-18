//SlotMachine.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class SlotMachine extends JFrame implements ActionListener {
    Drum d1, d2, d3;
    
    SlotMachine() {
        super( "SlotMachine" );
        
        String [][] picture = {{"¡ý", "¢£", "¡ß", "¡ù", "¡ù", "¢¨", "¢¤", "¡ý", "Ã®", "¢¤",
                                "¢£", "¡ß", "¡ý", "Ã®", "¢¨", "¢£", "¢¨", "¢¤", "¡ß", "7", "¡ù"},
                               {"¢£", "Ã®", "¡ý", "¡ß", "¢¤", "¢¨", "¡ù", "¢¨", "¢¤", "¡ù",
                                "¡ß", "Ã®", "¡ý", "¡ù", "¢¤", "¢£", "¡ß", "¡ý", "¢£", "7", "¢¨"},
                               {"¢¨", "¡ý", "¢¤", "¡ß", "¢£", "¢¤", "¡ß", "¡ù", "¡ß", "¡ý",
                                "Ã®", "¢£", "¢¨", "¡ù", "¢£", "¡ù", "¢¨", "¢¤", "¡ý", "7", "Ã®"}};
        
        Container myContainer = getContentPane();
        JPanel  p1 = new JPanel( new FlowLayout( FlowLayout.CENTER, 10, 10 ) );
        JButton b1 = new JButton( " LEFT " );
        JButton b2 = new JButton( "CENTER" );
        JButton b3 = new JButton( " RIGHT " );
        p1.add( b1 );
        p1.add( b2 );
        p1.add( b3 );
        
        JPanel p2 = new JPanel( new FlowLayout( FlowLayout.CENTER, 20, 10 ) );
        d1        = new Drum( picture[0], 52 );
        d2        = new Drum( picture[1], 50 );
        d3        = new Drum( picture[2], 48 );
        p2.add( d1 );
        p2.add( d2 );
        p2.add( d3 );
        
        myContainer.add( p1, BorderLayout.SOUTH  );
        myContainer.add( p2, BorderLayout.CENTER );
        pack();
        setVisible( true );
        
        b1.addActionListener( this );
        b1.setActionCommand("B1");
        b2.addActionListener( this );
        b2.setActionCommand("B2");
        b3.addActionListener( this );
        b3.setActionCommand("B3");
        
        addWindowListener( new WinAdapter() );
    }
    
    public void actionPerformed( ActionEvent ae ) {
        String cmd = ae.getActionCommand();
        
        if( d1.running == false && d2.running == false && d3.running == false ) {
            d1.rollStart();
            d2.rollStart();
            d3.rollStart();
        }else {
            if( cmd == "B1" ) {
                d1.rollStop();
            }
            else if( cmd == "B2" ) {
                d2.rollStop();
            }
            else if( cmd == "B3" ) {
                d3.rollStop();
            }
        }
    }
            
    public static void main( String [] args ) {
        SlotMachine p0 = new SlotMachine();
    }
}