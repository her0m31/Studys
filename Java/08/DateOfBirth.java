//DateOfBirth.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class DateOfBirth extends JPanel {
    static JTextField yearOfBirth, monthOfBirth, dayOfBirth;

    DateOfBirth() {
        JLabel l1    = new JLabel( "��ǯ����:" );
        yearOfBirth  = new JTextField( 4 );
        JLabel l2    = new JLabel( "ǯ" );
        monthOfBirth = new JTextField( 2 );
        JLabel l3    = new JLabel( "��" );
        dayOfBirth   = new JTextField( 2 );
        JLabel l4    = new JLabel( "��" );
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