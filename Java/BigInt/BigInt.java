// Filename: BigInt.java

class BigInt
{
	BigInt(){}
	
	BigInt(int len)
	{
		bigint = new int[len];
	}
	
	BigInt(String BI)
	{
		for(int i = 0; i < BI.length(); i++)
		{
			bigint[i] = BI.charAt(i) - '0';
		}
	}
	
	BigInt add(BigInt B)
	{
		int carry = 0;
		int i;
		int maxlen = bigint.length > B.bigint.length ? bigint.length : B.bigint.length + 1;
		
		BigInt tmp = new BigInt(maxlen);
		
		for(i = 0; i < maxlen; i++)
		{
			tmp.bigint[i] = 0;
		}
		
		for(i = maxlen; i >= 0; i--)
		{
			tmp.bigint[i] = bigint[i] + B.bigint[i] + carry;
			carry = tmp.bigint[i] / 10;
			if(carry == 1)
			{
				tmp.bigint[i] /= 10;
			}
		}
		return tmp;
	}
	
	void print()
	{
		int i = 0;
		if(bigint[0] == 0)
			i++;
		for( ; i < bigint.length; i++)
		{
			System.out.print(bigint[i]);
		}
	}

	private int [] bigint;
}
