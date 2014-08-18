// Hello1.java
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Hello1{
    public static void main (String [] args) {
        JFrame myframe = new JFrame ("SoftC");
        JLabel mylabel = new JLabel ("Hello java world.");

        Container mycontainer = myframe.getContentPane();
        mycontainer.add(mylabel);

        myframe.setSize(150, 100);
        myframe.setVisible(true);
        
        myframe.addWindowListener(new WindowAdapter (){
                public void windowClosing (WindowEvent evt) {
                    System.exit(0);}
            });
    }
}