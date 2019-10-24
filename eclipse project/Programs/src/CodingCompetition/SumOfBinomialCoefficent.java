package CodingCompetition;

import java.util.Scanner;

public class SumOfBinomialCoefficent 
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		try
		{	int testCases = in.nextInt();
			int n[]=new int[testCases];
			for(int a=0; a<testCases; a++)
			{
				n[a]=in.nextInt();
			}
			
			
			double f=1,max=Integer.MIN_VALUE;
			int i,r,sum=0;
						
			for(i=0;i<n.length;i++)
			{
				if(n[i]>max)
				{
					max=n[i];
				}
			}
			
			double fact[]=new double[(int)max+1];

			fact[0]=1;
			for(i=1;i<=max;i++)
			{
				f=f*i;
				f=Math.floor(f);
				fact[i]=f;
			}
			for(int a=0; a<testCases; a++)
			{					
				for(r=0;r<=n[a];r++)
				{
					f=fact[n[a]]/(fact[r]*fact[n[a]-r]);
					sum=sum+(int)(f%3);
				}
				sum=sum%1000000007;
				System.out.println(sum);
			}
		}
		catch(Exception e)
		{	e.printStackTrace();
		}
		finally
		{	in.close();
		}
	}

}
