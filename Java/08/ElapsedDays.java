//ElapsedDays.java
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.awt.*;

public class ElapsedDays extends JFrame implements ActionListener {
    JTextField result;

    ElapsedDays() {
        super( "My Living Days" );
        
        Container myContainer = getContentPane();
        myContainer.setLayout( new BorderLayout() );
        
        DateOfBirth  birthday = new DateOfBirth();
       
        JPanel p1    = new JPanel( new FlowLayout( ) );
        DateOfSurvey survey   = new DateOfSurvey();
        JButton b1    = new JButton( "計算" );
        p1.add(   survey, BorderLayout.SOUTH );
        p1.add(       b1, BorderLayout.WEST );


        JPanel  p2 = new JPanel( new FlowLayout() );
        JLabel  l1 = new JLabel( "生後経過日数" );
        result     = new JTextField( 20 ); 
        JLabel  l3 = new JLabel( "日" );
        JButton b2 = new JButton( "終了" );
        p2.add( l1 );
        p2.add( result );
        p2.add( b2 );
        
        myContainer.add( birthday, BorderLayout.NORTH  );
        myContainer.add( p1, BorderLayout.CENTER  );
        myContainer.add( p2, BorderLayout.SOUTH );
              
        pack();
        setVisible( true );
        
        b1.addActionListener( this );
        b2.addActionListener( this );
                       
        addWindowListener( new WinAdapter() );
    }

    public void actionPerformed( ActionEvent ae ) {
        Calendar cal = Calendar.getInstance();

        if( ae.getActionCommand() == "計算" ) {
            int yearB  = Integer.parseInt( DateOfBirth.yearOfBirth.getText() );
            int monthB = Integer.parseInt( DateOfBirth.monthOfBirth.getText() );
            int dayB   = Integer.parseInt( DateOfBirth.dayOfBirth.getText() );

            int yearS  = Integer.parseInt( DateOfSurvey.yearOfSurvey.getText() );
            int monthS = Integer.parseInt( DateOfSurvey.monthOfSurvey.getText() );
            int dayS   = Integer.parseInt( DateOfSurvey.dayOfSurvey.getText() );
               
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
        ElapsedDays mld = new ElapsedDays();
    }
}