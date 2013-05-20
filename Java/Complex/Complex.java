// Filename: Complex.java

class Complex 
{
	private double real;
	private double imag;

	Complex()
	{
		//System.out.println("默认构造函数");
	}

	Complex(String r, String i)
	{
		//Double d1 = new Double(r);
		//Double d2 = new Double(i);
		
		real = Double.parseDouble(r);
		imag = Double.parseDouble(i);
		
		//System.out.println("String构造函数");
	}
	
	Complex(double r, double i)
	{
		real = r;
		imag = i;
		
		//System.out.println("double构造函数");
	}
	
	Complex add(Complex cc)
	{
		Complex tmp = new Complex(real + cc.real, imag + cc.imag);
		return tmp;
	}
	
	Complex sub(Complex cc)
	{
		Complex tmp = new Complex(real - cc.real, imag - cc.imag);
		return tmp;
	}
	
	Complex mul(Complex cc)
	{
		double R = 0.0, I = 0.0;
		R = real * cc.real - imag * cc.imag;
		I = real * cc.imag + imag * cc.real;
		Complex tmp = new Complex(R, I);
		return tmp;
	}
	
	void print()
	{
		System.out.println("( " + real + ", " + imag + " )");
	}
}
