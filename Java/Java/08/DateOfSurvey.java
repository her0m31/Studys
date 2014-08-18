//DateOfSurvey.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class DateOfSurvey extends JPanel {
    static JTextField yearOfSurvey, monthOfSurvey, dayOfSurvey;  
   
    DateOfSurvey() {
        JPanel  p2    = new JPanel( new FlowLayout() );
        JLabel  l5    = new JLabel( "調査年月日:" );
        yearOfSurvey  = new JTextField( 4 );
        JLabel  l6    = new JLabel( "年" );
        monthOfSurvey = new JTextField( 2 );
        JLabel  l7    = new JLabel( "月" );
        dayOfSurvey   = new JTextField( 2 );
        JLabel  l8    = new JLabel( "日" );
        add( l5 );
        add( yearOfSurvey );
        add( l6 );
        add( monthOfSurvey );
        add( l7 );
        add( dayOfSurvey );
        add( l8 );
        setLayout( new FlowLayout() );
    }
}