//ATM

import java.util.Scanner;
import java.io.*;
import java.lang.Integer;
import java.lang.Math;

public class ATM
{
	public static void main(String[] args) 
	{
		new ATM();
	}

	ATM()
	{
		welcome();
	}

	void welcome()
	{
		System.out.println("---------------您好，欢迎使用杭电ATM机---------------");
		System.out.print("\n请输入您的卡号(五位数): ");
		CardNumber = scan.next();

		if(CardNumber.equals(AdminAcount))
		{
			System.out.print("\n要进入管理员模式吗?(Y/N)..");
			String ch;
			ch = scan.next();
			if(ch.equals("Y") || ch.equals("y"))
			{
				AdminModel();	
			}
			else
			{
				welcome();
			}
		}
		else
		{
			NormalModel();
		}
	}

	void AdminModel()
	{
		System.out.print("\n请输管理员密码: ");
		String password;
		password = scan.next();
		if(password.equals(originalpassword))
		{
			//管理员界面
			System.out.println("\n管理员您好!\n");
			
			int choice;
			do{
				System.out.println("1>>>账户信息查询");
				System.out.println("2>>>账户解封");
				System.out.println("3>>>退出");
				System.out.print("\n请输入您的选择: ");
				choice = scan.nextInt();
				switch(choice)
				{
					case 1:Check();break;
					case 2:Delock();break;
					case 3:welcome();break;
					default:System.out.print("输入有误!请重新选择!");
				}
			}while(choice != 1 || choice != 2 || choice != 3);
		}
		else
		{
			System.out.println("\n密码错误!\n");
			welcome();
		}
	}

	void Check()
	{
		System.out.println("\n请输入要查询的账号: ");
		String ac;
		ac = scan.next();
		int num = Integer.parseInt(ac);
		account[num] = new Account(ac);
		account[num].show();
	}

	void Delock()
	{
		System.out.println("\n请输入要解封的账号: ");
		String ac;
		ac = scan.next();
		account[Integer.parseInt(ac)].delock();
	}

	void NormalModel()
	{
		System.out.print("\n请输密码: ");
		String password;
		password = scan.next();
		if(password.equals(originalpassword))
		{
			new Account(CardNumber);
			int ch;
			do{
				System.out.println("1>>>取款");
				System.out.println("2>>>转账");
				System.out.println("3>>>修改密码");
				System.out.println("4>>>退出");
				System.out.println("请输入您的选择: ");
				ch = scan.nextInt();
				switch(ch)
				{
					case 1:account[Integer.parseInt(CardNumber)].withdraw();break;
					case 2:account[Integer.parseInt(CardNumber)].transfer();break;
					case 3:account[Integer.parseInt(CardNumber)].ChangePassword();break;
					case 4:welcome();break;
				}
			}while(ch != 1 || ch != 2 || ch != 3 || ch != 4);
		}
		else
		{
			System.out.println("\n密码错误!\n");
		}
	}
	
	Account [] account = new Account[100000];
	String CardNumber;
	String AdminAcount = "00000";
	String originalpassword = "000000";
	Scanner scan = new Scanner(System.in);
}

class Account
{
	Account(String cardnum)
	{
		cardnumber = cardnum;
		balance = Math.random() * 10000;
		password = "000000";
	}

	boolean withdraw()
	{
		if(balance >= 100)
		{
			System.out.println("100");
			{
				if(balance >= 200)
				{
					System.out.println("200");
					{
						if(balance >= 500)
						{
							System.out.println("500");
							if(balance >= 1000)
							{
								System.out.println("1000");
								if(balance >= 2000)
									System.out.println("2000");
							}
						}
					}
				}
			}
			System.out.println("请输入您要取钱的金额: ");
			int mm = in.nextInt();
			if(mm < balance)
			{
				balance -= mm;
				System.out.println("取款成功!请收好您的钱!");
				return true;
			}
			else
			{
				System.out.println("您的余额不足100!");
				return false;
			}
		}
		else
		{
			System.out.println("您的余额不足100!");
			return false;
		}
	}

	boolean transfer()
	{
		System.out.println("请输入您要转帐的金额: ");
		int mm = in.nextInt();
		if(mm < balance)
		{
			balance -= mm;
			System.out.println("取款成功!请收好您的钱!");
			return true;
		}
		else
		{
			System.out.println("您的余额不足!");
			return false;
		}
	}

	boolean ChangePassword()
	{
		System.out.println("请输入原密码: ");
		String pw = in.next();
		if(pw.equals(password))
		{
			System.out.println("请输入新密码: ");
			String pwa = in.next();
			System.out.println("请再次输入新密码: ");
			String pwb = in.next();
			if(pwa.length() == 6 && pwa.equals(pwb))
			{
				System.out.println("密码修改成功!");
				return true;
			}
			else
			{
				System.out.println("密码错误!");
				return false;
			}
		}
		else
		{
			System.out.println("原密码错误!");
			return false;
		}
	}

	void delock()
	{
		lock = false;
		System.out.println("账户解封成功!");
	}

	void show()
	{
		System.out.println("\nCardNumber: " + cardnumber);
		System.out.println("\nPassword: " + password);
		System.out.println("\nBalance: " + balance);
	}
	private double balance;
	private String cardnumber;
	private String password;
	boolean lock = false;
	Scanner in = new Scanner(System.in);
}