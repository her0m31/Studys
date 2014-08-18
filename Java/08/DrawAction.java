// DrawAction.java
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.awt.*;

public class DrawAction extends JFrame implements ActionListener {
    JTextField yearOfSurvey, monthOfSurvey, dayOfSurvey, yearOfBirth,  monthOfBirth,  dayOfBirth, result;
    DrawSine drawSine;
    
    public DrawAction() {
        super( "Biorithm" );
        
        Container myContainer = getContentPane();
        myContainer.setLayout( new BoxLayout( myContainer, BoxLayout.Y_AXIS ) );
        
        JPanel p1 = new JPanel( new FlowLayout( FlowLayout.RIGHT ) );
        JLabel l1 = new JLabel( "身長" );
        JLabel l2 = new JLabel( "体重" );
        JLabel l3 = new JLabel( "知性" );
        p1.add( l1 );
        p1.add( l2 );
        p1.add( l3 );
        
        drawSine = new DrawSine( 0 );
        
        JPanel p2     = new JPanel( new FlowLayout( ) );
        JLabel l4     = new JLabel( "生年月日:" );
        yearOfBirth   = new JTextField( 4 );
        JLabel l5     = new JLabel( "年" );
        monthOfBirth  = new JTextField( 2 );
        JLabel l6     = new JLabel( "月" );
        dayOfBirth    = new JTextField( 2 );
        JLabel l7     = new JLabel( "日" );
        p2.add( l4 );
        p2.add( yearOfBirth );
        p2.add( l5 );
        p2.add( monthOfBirth );
        p2.add( l6 );
        p2.add( dayOfBirth );
        p2.add( l7 );

        JPanel  p3    = new JPanel( new FlowLayout() );
        JLabel  l8    = new JLabel( "調査年月日:" );
        yearOfSurvey  = new JTextField( 4 );
        JLabel  l9    = new JLabel( "年" );
        monthOfSurvey = new JTextField( 2 );
        JLabel  l10   = new JLabel( "月" );
        dayOfSurvey   = new JTextField( 2 );
        JLabel  l11   = new JLabel( "日" );
        p3.add( l8 );
        p3.add( yearOfSurvey );
        p3.add( l9 );
        p3.add( monthOfSurvey );
        p3.add( l10 );
        p3.add( dayOfSurvey );
        p3.add( l11 );
        
        JPanel  p4    = new JPanel( new FlowLayout() );
        JButton ok    = new JButton( "O.K." );
        JButton clear = new JButton( "CLEAR" );
        JButton exit  = new JButton( "EXIT" );
        p4.add( ok );
        p4.add( clear );
        p4.add( exit );
     
        myContainer.add( p1 );
        myContainer.add( drawSine ); 
        myContainer.add( p2 );
        myContainer.add( p3 );
        myContainer.add( p4 );
        
        ok.addActionListener( this );
        clear.addActionListener( this );
        exit.addActionListener( this );
        
        addWindowListener( new WinAdapter() );
        
        pack();
        setVisible( true );
    }
    
    public void actionPerformed( ActionEvent ae ) {
        Calendar cal = Calendar.getInstance();
        
        if( ae.getActionCommand().equals( "O.K." ) ) {
            int yearB  = Integer.parseInt( yearOfBirth.getText() );
            int monthB = Integer.parseInt( monthOfBirth.getText() );
            int dayB   = Integer.parseInt( dayOfBirth.getText() );
            
            int yearS  = Integer.parseInt( yearOfSurvey.getText() );
            int monthS = Integer.parseInt( monthOfSurvey.getText() );
            int dayS   = Integer.parseInt( dayOfSurvey.getText() );
            
            int count = 0;
            for( int i = yearB; i < yearS; i++) {
                if( i % 4 == 0 && i % 100 != 0 || i % 400 == 0 )
                    count++;
            }
            cal.set( yearB, monthB-1, dayB );
            int dayOfYear1 = cal.get(Calendar.DAY_OF_YEAR);
            
            cal.set( yearS, monthS-1, dayS );
            int dayOfYear2 = cal.get(Calendar.DAY_OF_YEAR);
        
            int resulted = ( ((yearS - yearB) * 365) + ( dayOfYear2 - dayOfYear1 ) + count );
            
            drawSine.reset( resulted );
        }
        else if( ae.getActionCommand().equals( "CLEAR" ) )
            drawSine.reset(0);
        else
            System.exit( 0 );
    }
    
    public static void main( String [] args ) {
        DrawAction drawAction = new DrawAction();
    }
}