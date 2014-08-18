//MyActionEvent.java
import javax.swing.*;
import java.awt.*;

public class MyActionEvent extends JFrame {
    MyActionEvent() {
        super( "My Action Event" );

        Container myContainer = getContentPane();
        
        JButton myButton = new JButton( "Button" );
        myContainer.add( myButton );
        
        setSize( 150, 100 );
        setVisible( true );

        myButton.addActionListener( new ActListener() );
        addWindowListener( new WinAdapter() );
    }

    public static void main( String [] args ) {
        MyActionEvent myActionEvent = new MyActionEvent();
    }
}