// Filename: Matrix.java

class Matrix {

	Matrix(){}

    Matrix(int r, int c)
    {
    	row = r;
    	col = c;
    	matrix = new double[r][c];
    }
    
    Matrix(double [][] m, int r, int c)
    {
    	row = r;
    	col = c;
    	
    	matrix = m;
    }
    
    Matrix(double [][] m) 
    {
    	row = m.length;
    	col = m[0].length;
    	
    	matrix = m;
    }
    
    Matrix add(Matrix b)
    {
    	if((row != b.row) && (col != b.col))
    	{
    		System.out.println("Matrix A can't add Matri B!");
    		System.exit(1);
    	}
    	
    	Matrix tmp = new Matrix(row, col);
    	
    	for(int i = 0; i < row; i++)
    		for(int j = 0; j < col; j++)
    		{
    			tmp.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
    		}
    		
    	return tmp;
    }
    
    Matrix sub(Matrix b)
    {
    	if((row != b.row) && (col != b.col))
    	{
    		System.out.println("Matrix A can't subtract Matri B!");
    		System.exit(1);
    	}
    	
    	Matrix tmp = new Matrix(row, col);
    	
    	for(int i = 0; i < row; i++)
    		for(int j = 0; j < col; j++)
    		{
    			tmp.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
    		}
    		
    	return tmp;
    }
    
    Matrix mul(Matrix b)
    {
    	if(col != b.row)
    	{
    		System.out.println("Matrix A can't multiply Matrix B!");
    		System.exit(1);
    	}
    	
    	Matrix tmp = new Matrix(row, b.col);
    	for(int i = 0; i < row; i++)
    		for(int j = 0; j < b.col; j++)
    		{
    			tmp.matrix[i][j] = 0.0;
    			for(int k = 0; k < b.row; k++)
    			{
    				tmp.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
    			}
    		}
    	return tmp;
    }
    
    void print()
    {
    	for(int i = 0; i < row; i++)
    	{
    		System.out.print(matrix[i][0]);
    		for(int j = 1; j < col; j++)
    		{
    			System.out.print(" " + matrix[i][j]);
    		}
    		System.out.println("");
    	}
    }
    
    private int col;	//列数
    private int row;	//行数
    private double [][] matrix;	//保存矩阵
}