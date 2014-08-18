//TextCheckEvent.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class TextCheckEvent extends JFrame implements ItemListener, ActionListener {
    JCheckBox c1, c2;
    JTextField te;
    JLabel    l4;
    String dic;
    String name;

    TextCheckEvent() {
        super( "TextCheckEvent" );
        
        Container myContainer = getContentPane();
        myContainer.setLayout( new BorderLayout() );
        
        JPanel p1 = new JPanel( new FlowLayout() );
        JLabel l1 = new JLabel( "Your name please." );
        te        = new JTextField( 20 );
        p1.add( l1 );
        p1.add( te );
        
        JPanel p2 = new JPanel( new BorderLayout() );
        JLabel l2 = new JLabel( "Your name please." );
        c1        = new JCheckBox( "OxfordAdvanced Learner's Dictionary" );
        c2        = new JCheckBox( "Longman Language Activator" );
        p2.add( l2, BorderLayout.NORTH  );
        p2.add( c1, BorderLayout.CENTER );
        p2.add( c2, BorderLayout.SOUTH  );

        JPanel  p3 = new JPanel( new BorderLayout() );
               
        JPanel  p4 = new JPanel( new FlowLayout() );
        JLabel  l3 = new JLabel( "Are you sure?" );
        JButton b1 = new JButton( "Yes, I am." );  
        JButton b2 = new JButton( "No, I'm not." );
        p1.add( l3 );
        p1.add( b1 );
        p1.add( b2 );

        l4 = new JLabel( " " );

        p3.add( p4, BorderLayout.NORTH );
        p3.add( l4, BorderLayout.SOUTH );
     
        myContainer.add( p1, BorderLayout.NORTH  );
        myContainer.add( p2, BorderLayout.CENTER );
        myContainer.add( p3, BorderLayout.SOUTH  );

        pack();
        setVisible( true );
        
        b1.addActionListener( this );
        b1.setActionCommand("B1");
        b2.addActionListener( this );
        b2.setActionCommand("B2");
        
        c1.addItemListener  ( this );
        c2.addItemListener  ( this );
        
        addWindowListener( new WinAdapter() );
    }
    
    public void actionPerformed( ActionEvent ae ) {
        String cmd = ae.getActionCommand();
        
        if( cmd == "B1" ) { 
            if( dic != null ) {
                name = te.getText();
                l4.setText( name +" selects "+ dic );
            }
        }
        else if( cmd == "B2" ){
            l4.setText(" ");
        }
    }
    
    public void itemStateChanged( ItemEvent ie ) {
        if( ie.getItemSelectable() == c1 ) {
            if( c1.isSelected() )
                dic = "Oxford.";
        }
        else {
            if( c2.isSelected() )
                dic =  "Longman.";
        }
    }
    
    public static void main( String [] args ) {
        TextCheckEvent textCheckEvent = new TextCheckEvent();
    }
}