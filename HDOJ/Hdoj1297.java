// HDOJ1297
import java.math.BigDecimal;
import java.util.*;

public class Hdoj1297 {
	public static void main(String[] args) {
		BigDecimal[] num = new BigDecimal[1003];
		num[0] = new BigDecimal(1); 
		num[1] = new BigDecimal(1);
		num[2] = new BigDecimal(2); 
		num[3] = new BigDecimal(4);
		BigDecimal tmp;
		for(int i = 4; i <= 1000; i++)
		{
			tmp = num[i-1].add(num[i-2]);
			tmp = tmp.add(num[i-4]);
			num[i] = new BigDecimal(tmp.toString());
		}
		System.gc();
		Scanner in = new Scanner(System.in);
		while(in.hasNext())
			System.out.println(num[in.nextInt()]);
	}
}
