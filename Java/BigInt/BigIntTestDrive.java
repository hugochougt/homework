// Filename: BigIntTestDrive.java

import java.io.*;
import java.util.Scanner;

public class BigIntTestDrive
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		
		String strA, strB;
		
		System.out.println("Input the first integer:");
		strA = in.next();
		BigInt BigA = new BigInt(strA);
		
		System.out.println("Input the second integer:");
		strB = in.next();
		BigInt BigB = new BigInt(strB);
		
		BigInt BigC = BigA.add(BigB);
		
		BigC.print();
	}
}