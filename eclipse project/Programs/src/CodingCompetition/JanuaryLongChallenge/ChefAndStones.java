package CodingCompetition.JanuaryLongChallenge;

import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class ChefAndStones
{
	static InputStream in = System.in;
	static byte[] inputbuffer = new byte[1024];
	static int len = 0, ptr = 0;
	
	public static void main(String[] args) throws IOException
	{
		long testCases = readLong();
		for(int a=0; a<testCases; a++)
		{	
			long typeOfStones = readLong();
			long totalMinutes = readLong();
			long [] time,profit;
			time = new long[(int)typeOfStones];
			profit = new long[(int)typeOfStones];
			long p, temp, max=Integer.MIN_VALUE;
			int i;
					
			for(i=0;i<typeOfStones;i++)
			{
				time[i]=readLong();
			}
			for(i=0;i<typeOfStones;i++)
			{
				profit[i]=readLong();
			}
			
			for(i=0;i<typeOfStones;i++)
			{
				temp = totalMinutes/time[i];
				p = profit[i]*temp;
				if(p>max)
				{
					max=p;
				}
			}			
			System.out.println(max);
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
