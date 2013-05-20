//计算器

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class calculator extends JFrame
{
	public calculator()
	{
		setTilte("计算器");
		initTextPanel();	//显示面板
		initConctrlPanel();	//控制面板
		initKeyPanel();		//数字和运算符面板
	}

	void setTitle()
	{
		textfield = new JTextField("0", 30);
		textfield.setEditable(false);
		textfield.setHorizontalAlignment(JTextField.RIGHT);
		textPanel = new JPanel();
		textPanel.setlayout(new FlowLayout());
		textPanel.add(textfield);
	}
	
	void 

	private JPanel textPanel;//显示框
	private JTextField textfield;
	private JPanel conctrlPanel;//控制框
	private JPanel keyPanel;//数字框
	private StringBuffer numberA;
	private StringBuffer numberB;
	private char optr;//操作符
	private boolean isNew = true;
}
