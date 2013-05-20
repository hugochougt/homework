// Filename: IOOperation.java
import java.io.*;

class  IOOperation
{
	public static void main(String[] args) 
	{
		FileInputStream File1 = null;
		FileInputStream File2 = null;
		BufferedReader in = null;
		String sFile;

		if(args.length != 2)
		{
			System.out.println("The command line should be: java IOOperation testX.txt testX.txt");
			System.out.println("X should be one of the array: 1, 2, 3");
			System.exit(0);
		}

		try
		{
			File1 = new FileInputStream(args[0]);
			File2 = new FileInputStream(args[1]);
			
			//输出两个文件
			try
			{
				//输出文件1
				in = new BufferedReader(new FileReader(args[0]));
				System.out.println(args[0] + ":");
				System.out.println("");
				while((sFile = in.readLine()) != null)
					System.out.println(sFile);

				//输出文件2
				in = new BufferedReader(new FileReader(args[1]));
				System.out.println(args[1] + ":");
				System.out.println("");
				while((sFile = in.readLine()) != null)
					System.out.println(sFile);

				System.out.println("");
			}
			catch (IOException e)
			{
				System.out.println(e);
			}
			finally
			{
				try
				{
					if(in != null)
						in.close();
				}
				catch (Exception e)
				{
					System.out.println(e);
				}
			}

			//判断两个文件是否相等
			try
			{
				System.out.print("It is obvous that ");
				if(File1.available() != File2.available())
				{
					//System.out.println("File1:" + File1.available());
					//System.out.println("File2:" + File2.available());
					System.out.println(args[0] + " is not equal to " + args[1]);
				}
				else
				{
					boolean tag = true;

					while( File1.read() != -1 && File2.read() != -1)
					{
						if(File1.read() != File2.read())
						{
							tag = false;
							break;
						}
					}

					if(tag == true)
						System.out.println(args[0] + " equals to " + args[1]);
					else
						System.out.println(args[0] + " is not equal to " + args[1]);
				}
			}
			catch(IOException e)
			{
				System.out.println(e);
			}
		}
		catch (FileNotFoundException e)
		{
			System.out.println("File can't find..");
		}
		finally
		{
			
			try
			{
				if(File1 != null)
					File1.close();
				if(File2 != null)
					File2.close();
			}
			catch (IOException e)
			{
				System.out.println(e);
			}
		}
	}
}
