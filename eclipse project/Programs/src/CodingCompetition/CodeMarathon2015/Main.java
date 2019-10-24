package CodingCompetition.CodeMarathon2015;

import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class Main
{
	static InputStream in = System.in;
	static byte[] inputbuffer = new byte[1024];
	static int len = 0, ptr = 0;
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int q = readInt();
		int a[] = new int[n];
		int i, j, max, min, l ,r;
		for(i=0; i<n; i++)
		{
			a[i] = readInt();
		}
		for(i=0; i<q; i++)
		{
			l = readInt();
			r = readInt();
			l--;
			j=l;
			min = max = a[j];
			j++;
			for(; j<r; j++)
			{
				if(a[j]>max)	max = a[j];
				min = GCD(min, a[j]);
			}
			System.out.println(max+" "+min);
		}		
	}
	
	static int GCD(int a,int b)
	{
	    if(b==0)
	    return a;
	    return GCD(b,a%b);
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
}