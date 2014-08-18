//DrawSine.java
import javax.swing.*;
import java.awt.*;

public class DrawSine extends JComponent {
    int elapsedDays;
        
    DrawSine( int elapsedDays ) {
        this.elapsedDays = elapsedDays;
        setPreferredSize( new Dimension( 360, 200 ) );
    }
    
    public void paintComponent( Graphics g ) {
        super.paintComponent( g );
        
        if( elapsedDays != 0 ) {
            g.drawLine( 0, 100, 360, 100 );
            
            int [] xpoints = new int [37];
            int [] ypoints = new int [37];
            
            for( int i = 0; i < xpoints.length; i++ ) {
                xpoints[i] = i * 10;
                ypoints[i] = (int)( 100 - 100 * Math.sin( 2 * Math.PI * (elapsedDays + i) / 23 ) );
            }
            g.setColor( Color.red );
            g.drawPolyline( xpoints, ypoints, xpoints.length );
            
            g.drawLine( 0, 100, 360, 100 );
            for( int i = 0; i < xpoints.length; i++ ) {
                xpoints[i] = i * 10;
                ypoints[i] = (int)(100 - 100 * Math.sin( 2 * Math.PI * (elapsedDays + i) / 28 ));
            }
            g.setColor( Color.cyan );
            g.drawPolyline( xpoints, ypoints, xpoints.length );
            
            g.drawLine( 0, 100, 360, 100 );
            for( int i = 0; i < xpoints.length; i++ ) {
                xpoints[i] = i * 10;
                ypoints[i] = (int)(100 - 100 * Math.sin( 2 * Math.PI * (elapsedDays + i) / 33 ));
            }
            g.setColor( Color.pink );
            g.drawPolyline( xpoints, ypoints, xpoints.length );
        }
    }
    
    void reset( int e ) {
        elapsedDays = e;

        repaint();
    }
}