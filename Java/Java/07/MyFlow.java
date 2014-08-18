//MyFlow.java
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MyFlow extends JFrame {
    MyFlow() {
        super( "FlowLayout" );

        Container myContainer = getContentPane();


        BorderLayout borderLayout 
            = new BorderLayout();
        myContainer.setLayout( borderLayout );
        

        /*
          GridLayout gridLayout 
          = new GridLayout( 3, 2, 5, 10 );
          myContainer.setLayout( gridLayout );
                    
          FlowLayout flowLayout 
          = new FlowLayout( FlowLayout.RIGHT, 5, 10 );
          myContainer.setLayout( flowLayout );
        */

        JLabel myLabel1 = new JLabel( "This is North. ", JLabel.CENTER );
        JLabel myLabel2 = new JLabel( "This is South. ", JLabel.CENTER );
        JLabel myLabel3 = new JLabel( "This is West.  ", JLabel.CENTER );
        JLabel myLabel4 = new JLabel( "This is East.  ", JLabel.CENTER );
        JLabel myLabel5 = new JLabel( "This is Center.", JLabel.CENTER );
        
        myContainer.add( myLabel1, BorderLayout.NORTH  );
        myContainer.add( myLabel2, BorderLayout.SOUTH  );
        myContainer.add( myLabel3, BorderLayout.WEST   );
        myContainer.add( myLabel4, BorderLayout.EAST   );
        myContainer.add( myLabel5, BorderLayout.CENTER );
          
        /*
          JLabel myLabel1 = new JLabel( "This is 1." );
          JLabel myLabel2 = new JLabel( "This is 2." );
          JLabel myLabel3 = new JLabel( "This is 3." );
          JLabel myLabel4 = new JLabel( "This is 4." );
          JLabel myLabel5 = new JLabel( "This is 5." );
          
          myContainer.add( myLabel1 );
          myContainer.add( myLabel2 );
          myContainer.add( myLabel3 );
          myContainer.add( myLabel4 );
          myContainer.add( myLabel5 );
        */

        setSize( 300, 200 );
        setVisible( true );

        addWindowListener( new WindowAdapter() {
                public void windowClosing( WindowEvent we ) {
                    System.exit( 0 );
                }
            } );
    }

    public static void main( String [] args ) {
        MyFlow myFlow = new MyFlow();
    }
}