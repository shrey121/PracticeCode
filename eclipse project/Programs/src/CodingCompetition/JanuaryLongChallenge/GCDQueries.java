//40 points achived, 60 more to go.

package CodingCompetition.JanuaryLongChallenge;

import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
 
public class GCDQueries
{
	static InputStream in = System.in;
	static byte[] inputbuffer = new byte[1024];
	static int len = 0, ptr = 0;
	
	public static void main(String[] args) throws IOException
	{
		int testCases = readInt();
		for(int a=0; a<testCases; a++)
		{	
			int n = readInt();
			int q = readInt();
			int[] arr;
			arr = new int[n];
			int i, l, r, ans=1;
			
			for(i=0;i<n;i++)
			{	
				arr[i] = readInt();
			}
			
			for(int b=0; b<q; b++)
			{	
				l = readInt();
				r = readInt();
				
				for(i=0; i<n ; i++)
				{
					if(i>=(l-1) && i<=(r-1))
					{
						i=i+(r-l);
					}
					else
					{
						ans=arr[i];
						i++;
						break;
					}
				}
				
				for(; i<n ; i++)
				{
					if(i>=(l-1) && i<=(r-1))
					{
						i=i+(r-l);
					}
					else
					{
						ans=gcd(ans,arr[i]);
					}
				}
				
				System.out.println(ans);				
			}
		}
	}
	
	static int gcd(int m, int n)
	{	
		int r;
	    while(n>0) 
	    {
	        r = m % n;
	        m = n;
	        n = r;
	    }
	    return m;
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

/*
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
 
public class Main
{
	static InputStream in = System.in;
	static byte[] inputbuffer = new byte[1024];
	static int len = 0, ptr = 0;
	
	static int gcd(int m, int n)
	{	
		int r;
	    while(n>0) 
	    {
	        r = m % n;
	        m = n;
	        n = r;
	    }
	    return m;
	}
	
	public static void main(String[] args) throws IOException
	{
		int testCases = readInt();
		for(int a=0; a<testCases; a++)
		{	
			int n = readInt();
			int q = readInt();
			int[] arr = new int[n];
			int [][] leftInfo = new int[q][2];
			int [][] rightInfo = new int[q][2];
			
			int i, l, r, j, leftgcd, rightgcd, leftN=0, rightN=0;
			
			for(i=0;i<n;i++)
			{	
				arr[i] = readInt();
			}
			
			for(int b=0; b<q; b++)
			{	
				l = readInt();
				r = readInt();
				l--;
				r--;
				
				if(l>0)
				{
					leftgcd=arr[0];
					j=0;
				}
				else
				{
					leftgcd=arr[r+1];
					j=r+1;
				}
				
				for(i=0;i<leftN && l>0;i++)
				{
					if(leftInfo[i][0]<l)
					{
						leftgcd=leftInfo[i][1];
						j=leftInfo[i][0];
					}
					else
					{
						break;
					}
				}
				for(i=j+1;i<l;i++)
				{
					leftgcd=gcd(leftgcd,arr[i]);
				}
				
				if(b<q-1 && l!=0)
				{
					if(leftN==0)
					{
						leftInfo[leftN][0]=l-1;
						leftInfo[leftN][1]=leftgcd;
						leftN++;
					}
					else if(leftN==1)
					{
						if(l-1>leftInfo[0][0])
						{
							leftInfo[leftN][0]=l-1;
							leftInfo[leftN][1]=leftgcd;
							leftN++;
						}
						else if(l-1<leftInfo[0][0])
						{
							leftInfo[leftN][0]=leftInfo[leftN-1][0];
							leftInfo[leftN][1]=leftInfo[leftN-1][1];
							leftInfo[leftN-1][0]=l-1;
							leftInfo[leftN-1][1]=leftgcd;
							leftN++;
						}
					}
					else
					{	boolean flag=false;
						for(i=0;i<leftN;i++)
						{
							if(leftInfo[i][0]<l-1)
							{
							}
							else if(leftInfo[i][0]==l-1)
							{
								flag=true;
							}
							else
							{
								break;
							}
						}
						
						if(flag==false)
						{
							for(j=leftN;j>i;j--)
							{
								leftInfo[j][0]=leftInfo[j-1][0];
								leftInfo[j][1]=leftInfo[j-1][1];
							}
							leftInfo[i][0]=l-1;
							leftInfo[i][1]=leftgcd;
							leftN++;
						}
					}
				}

				if(r<(arr.length-1))
				{
					rightgcd=arr[(arr.length-1)];
					j=arr.length-1;
				}
				else
				{
					rightgcd=arr[l-1];
					j=l-1;
				}	
							
				for(i=0;i<rightN && r<(arr.length-1);i++)
				{
					if(rightInfo[i][0]>r)
					{
						rightgcd=rightInfo[i][1];
						j=rightInfo[i][0];
						break;
					}
				}
				for(i=r+1;i<j;i++)
				{
					rightgcd=gcd(rightgcd,arr[i]);
				}
				
				if(b<q-1 && r!=arr.length-1)
				{
					if(rightN==0)
					{
						rightInfo[rightN][0]=r+1;
						rightInfo[rightN][1]=rightgcd;
						rightN++;
					}
					else if(rightN==1)
					{
						if(r+1>rightInfo[0][0])
						{
							rightInfo[rightN][0]=r+1;
							rightInfo[rightN][1]=rightgcd;
							rightN++;
						}
						else if(r+1<rightInfo[0][0])
						{
							rightInfo[rightN][0]=rightInfo[rightN-1][0];
							rightInfo[rightN][1]=rightInfo[rightN-1][1];
							rightInfo[rightN-1][0]=r+1;
							rightInfo[rightN-1][1]=rightgcd;
							rightN++;
						}
					}
					else
					{	boolean flag=false;
						for(i=0;i<rightN;i++)
						{
							if(rightInfo[i][0]<r+1)
							{
							}
							else if(rightInfo[i][0]==r+1)
							{
								flag=true;
							}
							else
							{
								break;
							}
						}
					
						if(flag==false)
						{
							for(j=rightN;j>i;j--)
							{
								rightInfo[j][0]=rightInfo[j-1][0];
								rightInfo[j][1]=rightInfo[j-1][1];
							}
							rightInfo[i][0]=r+1;
							rightInfo[i][1]=rightgcd;
							rightN++;
						}
					}
				}
				
				System.out.println(gcd(leftgcd,rightgcd));
				
			}
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
} 
*/