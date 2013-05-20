import javax.swing.JFrame;

/**
 * 计算器入口类
 */

public class Main {
	public static void main(String[] args) {
		CalFrame calFrame = new CalFrame();
		calFrame.pack();	//使面板紧凑
		calFrame.setVisible(true);
		calFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
