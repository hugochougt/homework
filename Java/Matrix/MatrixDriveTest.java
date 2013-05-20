// Filename: MatrixDriveTest

import java.io.*;
import java.util.*;

public class MatrixDriveTest {

    public static void main(String [] args) throws Exception
    {
    	
    	int m, n;	//m保存行数, n保存列数
    	double [][] matrix;	//保存矩阵
    	
    	Scanner in = new Scanner(System.in);
    	
    	System.out.println("Input a m×n matrix...");	
    	
    	m = in.nextInt();
    	n = in.nextInt();
    	
    	matrix = new double[m][n];
    	
    	//System.out.println("m = " + matrix.length);
    	//System.out.println("n = " + matrix[0].length);
    	
    	for(int i = 0; i < m; i++)
    		for(int j = 0; j < n; j++)
    		{
    			matrix[i][j] = in.nextDouble();
    		}
    	
    	Matrix A = new Matrix(matrix);
    	//A.print();
    	
    	System.out.println("Input a m×n matrix...");
    	
    	m = in.nextInt();
    	n = in.nextInt();
    	
    	matrix = new double[m][n];
    	
    	//System.out.println("m = " + matrix.length);
    	//System.out.println("n = " + matrix[0].length);
    	
    	for(int i = 0; i < m; i++)
    		for(int j = 0; j < n; j++)
    		{
    			matrix[i][j] = in.nextDouble();
    		}
    	
    	Matrix B = new Matrix(matrix);
    	
    	//Matrix C = A.add(B);
    	//C.print();
    	//Matrix D = A.sub(B);
    	//D.print();
    	//Matrix E = A.mul(B);
    	//E.print();
    	
    	System.out.println("1. A + b");
		System.out.println("2. A - B");
		System.out.println("3. A * B");
		
		int ch = 0;
		
		System.out.print("Choose your operation: ");
		try{
			BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
			ch = Integer.parseInt(br.readLine());
		}catch(IOException ex){}
		
		Matrix C = new Matrix();
		
		switch(ch)
			{
				case 1:C = A.add(B);C.print();break;
				case 2:C = A.sub(B);C.print();break;
				case 3:C = A.mul(B);C.print();break;
				default:System.out.println("Choice Error!!");break;
			}
    }
    
    
}