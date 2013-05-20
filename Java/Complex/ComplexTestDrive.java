// Filename: ComplexTestDrive

import java.io.*;
import java.util.*;
import java.lang.Double;

public class ComplexTestDrive
{
	public static void main(String[] args) 
	{
		int ch = 0;	//算术操作符: + - *
		
		Scanner in = new Scanner(System.in);
		
		String A, B;	//A是实部, B是虚部
		//while(true)
		//{
			System.out.println("Input the first plural");
			System.out.print("Input the real: ");
			A = in.next();
			System.out.print("Input the image: ");
			B = in.next();
			
			Complex c1 = new Complex(A, B);
			
			System.out.println("Input the second plural");
			System.out.print("Input the real: ");
			A = in.next();
			System.out.print("Input the image: ");
			B = in.next();
			
			Complex c2 = new Complex(A, B);
			
			//c1.print();
			//c2.print();
			
			System.out.println("1. A + b");
			System.out.println("2. A - B");
			System.out.println("3. A * B");
			
			System.out.print("Choose your operation: ");
			try{
				BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
				ch = Integer.parseInt(br.readLine());
			}catch(IOException ex){}
			//System.out.println("ch = " + ch);
			
			Complex c3 = new Complex();
			
			switch(ch)
			{
				case 1:c3 = c1.add(c2);c3.print();break;
				case 2:c3 = c1.sub(c2);c3.print();break;
				case 3:c3 = c1.mul(c2);c3.print();break;
				default:System.out.println("Choice Error!!");break;
			}
			
		//}
	}
}