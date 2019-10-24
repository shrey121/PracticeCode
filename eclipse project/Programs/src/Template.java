import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class Template //Main (codechef)
{
	static InputStream in = System.in;
	static byte[] inputbuffer = new byte[1024];
	static int len = 0, ptr = 0;
	
	public static void main(String[] args) throws IOException
	{
		int testCases = readInt();
		for(int a=0; a<testCases; a++)
		{	
					
			System.out.println();
		}
	}
	
	static int readByte()
	{
		if(len == -1) throw new InputMismatchException();
		
		if(ptr >= len)
		{
			ptr = 0;
			try 
			{ 
				len = in.read(inputbuffer); 
			} 
			catch(IOException e) 
			{ 
				throw new InputMismatchException(); 
			}
			
			if(len <= 0)
			{
				return -1;
			}
		}
		return inputbuffer[ptr++];
	}
	
	static int readInt()
	{
		int number = 0, i;
		boolean minus = false;
		
		while((i = readByte()) != -1 && !((i >= '0' && i <= '9') || i == '-'));
		
		if(i == '-')
		{
			minus = true;
			i = readByte();
		}
		
		while(true)
		{
			if(i >= '0' && i <= '9')
			{
				number = number * 10 + (i - '0');
			}
			else
			{
				return minus ? -number : number;
			}
			i = readByte();
		}
	}
		
	static long readLong()
	{
		long number = 0;
		int i;
		boolean minus = false;
		
		while((i = readByte()) != -1 && !((i >= '0' && i <= '9') || i == '-'));
		
		if(i == '-')
		{
			minus = true;
			i = readByte();
		}
		
		while(true)
		{
			if(i >= '0' && i <= '9')
			{
				number = number * 10 + (i - '0');
			}
			else
			{
				return minus ? -number : number;
			}
			i = readByte();
		}
	}
}