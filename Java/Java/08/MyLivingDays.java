//MyLivingDays.java
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.awt.*;

public class MyLivingDays extends JFrame implements ActionListener {
    JTextField yearOfSurvey, monthOfSurvey, dayOfSurvey;
    JTextField yearOfBirth,  monthOfBirth,  dayOfBirth;
    JTextField result;

    MyLivingDays() {
        super( "My Living Days" );
                
        Container myContainer = getContentPane();
        myContainer.setLayout( new BorderLayout() );
        
        JPanel p1    = new JPanel( new FlowLayout() );
        JLabel l1    = new JLabel( "生年月日:" );
        yearOfBirth  = new JTextField( 4 );
        JLabel l2    = new JLabel( "年" );
        monthOfBirth = new JTextField( 2 );
        JLabel l3    = new JLabel( "月" );
        dayOfBirth   = new JTextField( 2 );
        JLabel l4    = new JLabel( "日" );
        p1.add( l1 ); 
        p1.add( yearOfBirth );
        p1.add( l2 );
        p1.add( monthOfBirth );
        p1.add( l3 );
        p1.add( dayOfBirth );
        p1.add( l4 );
            
        JPanel  p2    = new JPanel( new FlowLayout() );
        JLabel  l5    = new JLabel( "調査年月日:" );
        yearOfSurvey  = new JTextField( 4 );
        JLabel  l6    = new JLabel( "年" );
        monthOfSurvey = new JTextField( 2 );
        JLabel  l7    = new JLabel( "月" );
        dayOfSurvey   = new JTextField( 2 );
        JLabel  l8    = new JLabel( "日" );
        JButton b1    = new JButton( "計算" );
        p2.add( l5 );
        p2.add( yearOfSurvey );
        p2.add( l6 );
        p2.add( monthOfSurvey );
        p2.add( l7 );
        p2.add( dayOfSurvey );
        p2.add( l8 );
        p2.add( b1 );
        
        JPanel  p3  = new JPanel( new FlowLayout() );
        JLabel  l9  = new JLabel( "生後経過日数" );
        result      = new JTextField( 20 ); 
        JLabel  l10 = new JLabel( "日" );
        JButton b2  = new JButton( "終了" );
        p3.add( l9 );
        p3.add( result );
        p3.add( b2 );
        
        myContainer.add( p1, BorderLayout.NORTH  );
        myContainer.add( p2, BorderLayout.CENTER );
        myContainer.add( p3, BorderLayout.SOUTH  );
        
        pack();
        setVisible( true );
        
        b1.addActionListener( this );
        b2.addActionListener( this );
                       
        addWindowListener( new WinAdapter() );
    }

    public void actionPerformed( ActionEvent ae ) {
        Calendar cal = Calendar.getInstance();

        if( ae.getActionCommand() == "計算" ) {
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
            
            result.setText( String.valueOf( resulted ) );
        }
        else if( ae.getActionCommand() == "終了" ) {
            System.exit( 0 );
        }
    }
    
    public static void main( String [] args ) {
        MyLivingDays mld = new MyLivingDays();
    }
}