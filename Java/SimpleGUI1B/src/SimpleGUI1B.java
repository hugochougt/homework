
import javax.swing.*;
import java.awt.event.*;

public class SimpleGUI1B implements ActionListener 
{
	JButton button; 
	
	public static void main(String [] args)
	{
		SimpleGUI1B gui = new SimpleGUI1B();
		gui.go();
	}
	
	void go()
	{
		JFrame frame = new JFrame();
		button = new JButton("Click me.");
		
		button.addActionListener(this);//向按钮注册
		
		frame.getContentPane().add(button);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 300);
		frame.setVisible(true);
	}
	
	//实现interface上的方法...这才是真整处理事件的方法
	public void actionPerformed(ActionEvent event)
	{
		button.setText("I've been click.");
	}
}
