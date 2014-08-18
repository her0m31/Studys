import java.awt.*;
import javax.swing.*;

class GUI23 extends JPanel{

    JButton jb1;

    GUI23(){
    //ボタンの作成
    jb1 = new JButton("Hello");

    //レイアウトの指定
    setLayout(new BorderLayout());
    //JPanelの配置

    add(jb1,BorderLayout.CENTER);

     }
}
class GUI23_1 extends JPanel{

    JButton jb2;

    GUI23_1(){
    //ボタンの作成
    jb2 = new JButton("Java");

    //レイアウトの指定
    setLayout(new BorderLayout());
    //JPanelの配置

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
	
