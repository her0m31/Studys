import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Test extends JFrame {
    private JTextField tf = new JTextField();
    private JButton bt = new JButton("コンソール表示を確認せよ");
    
    public Test() {
        this.getContentPane().setLayout(null);
        tf.setBounds(new Rectangle(10, 10, 100, 20));
        bt.setBounds(new Rectangle(10, 50, 100, 20));
        
        bt.addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent e) {
                    String text = tf.getText();
                    if( text == null ) {
                        System.out.println("nullである");
                    } else {
                        System.out.println("nullではない");
                    }
                    System.out.println("[" + text + "]");
                }
            });
        
        this.getContentPane().add( tf );
        this.getContentPane().add( bt );
        this.setSize(500, 400);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setVisible(true);
    }
    
    public static void main(String[] args) {
        Test t = new Test();
    }
}