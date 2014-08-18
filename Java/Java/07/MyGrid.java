//MyGrid.java
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class MyGrid extends JFrame {
    MyGrid() {
        super( "DaisLab" );
        
        Container myContainer = getContentPane();
        GridLayout gridLayout = new GridLayout( 3, 2, 5, 10 );
        myContainer.setLayout( gridLayout );
        
        JLabel myLabel1 = new JLabel( "Utino   " );
        JLabel myLabel2 = new JLabel( "Tiba    " );
        JLabel myLabel3 = new JLabel( "Simomura" );
        JLabel myLabel4 = new JLabel( "takeda  " );
        JLabel myLabel5 = new JLabel( "utida   " );
        
        myContainer.add( myLabel1 );
        myContainer.add( myLabel2 );
        myContainer.add( myLabel3 );
        myContainer.add( myLabel4 );
        myContainer.add( myLabel5 );

        setSize( 300, 200 );
        setVisible( true );
        
        addWindowListener( new WindowAdapter() {
                public void windowClosing( WindowEvent we ) {
                    System.exit( 0 );
                }
            } );
    }

    public static void main( String [] args ) {
        MyGrid myGrid = new MyGrid();
    }
}