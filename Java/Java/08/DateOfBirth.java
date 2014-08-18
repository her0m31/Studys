//DateOfBirth.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class DateOfBirth extends JPanel {
    static JTextField yearOfBirth, monthOfBirth, dayOfBirth;

    DateOfBirth() {
        JLabel l1    = new JLabel( "生年月日:" );
        yearOfBirth  = new JTextField( 4 );
        JLabel l2    = new JLabel( "年" );
        monthOfBirth = new JTextField( 2 );
        JLabel l3    = new JLabel( "月" );
        dayOfBirth   = new JTextField( 2 );
        JLabel l4    = new JLabel( "日" );
        add( l1 ); 
        add( yearOfBirth );
        add( l2 );
        add( monthOfBirth );
        add( l3 );
        add( dayOfBirth );
        add( l4 );
        setLayout( new FlowLayout() );
    }
}