import java.awt.*;
import javax.swing.*;

class GUI23 extends JPanel{

    JButton jb1;

    GUI23(){
    //�ܥ���κ���
    jb1 = new JButton("Hello");

    //�쥤�����Ȥλ���
    setLayout(new BorderLayout());
    //JPanel������

    add(jb1,BorderLayout.CENTER);

     }
}
class GUI23_1 extends JPanel{

    JButton jb2;

    GUI23_1(){
    //�ܥ���κ���
    jb2 = new JButton("Java");

    //�쥤�����Ȥλ���
    setLayout(new BorderLayout());
    //JPanel������

    add(jb2,BorderLayout.CENTER);

     }
}

public class GUISwing23{
    public static void main(String args[]){

    GUI23 jb_app = new GUI23();
	GUI23_1 jb_app1 = new GUI23_1();
    
     JFrame jf = new JFrame("JButton");
     
     Container c = jf.getContentPane();
	 
     c.add(jb_app,BorderLayout.NORTH);
	 c.add(jb_app1,BorderLayout.SOUTH);
    
 jf.setSize(200, 200);

     jf.setVisible(true);
 jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
}
	
