//Text.java
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Text{
    public static void main (String [] args) {
        JFrame myframe = new JFrame ("SoftC");
        JLabel mylabel = new JLabel ("<html>The java command executes Java bytecodes created by the Java<br>
compiler, javac. The Just In Time compiler (JIT) 
compiles<br>These bytecodes into machine instructions by default in the
<br>Solaris Java Virtual Machine (JVM) using java.</html>");
        
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