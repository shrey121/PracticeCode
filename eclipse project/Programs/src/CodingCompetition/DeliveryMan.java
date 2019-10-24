package CodingCompetition;

import java.util.Scanner;

public class DeliveryMan 
{	
	public static void main(String[] args) 
	{
		
		Scanner in = new Scanner(System.in);
		try
		{	int n = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			int[] ai = new int[n];
			int[] bi = new int[n];
			int[] done=new int[n];
			int i,j,temp,tip=0;
			
			for(i=0;i<n;i++)
			{
				System.out.println(done[i]);
			}
		
		for(i=0;i<n;i++)
		{
			a[i]=in.nextInt();
		}
		for(i=0;i<n;i++)
		{
			b[i]=in.nextInt();
		}
		
		for(i=0;i<n;i++)
		{
			ai[i]=i;
		}
		for(i=0;i<n;i++)
		{
			bi[i]=i;
		}
	
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(i!=j)
				{
					if(a[i]<a[j])
					{
						temp=a[j];
						a[j]=a[i];
						a[i]=temp;
						temp=ai[j];
						ai[j]=ai[i];
						ai[i]=temp;
					}
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(i!=j)
				{
					if(b[i]<b[j])
					{
						temp=b[j];
						b[j]=b[i];
						b[i]=temp;
						temp=bi[j];
						bi[j]=bi[i];
						bi[i]=temp;
					}
				}
			}
		}
		
		for(i=0,j=0; i<n && j<n && x>0 && y>0; )
		{
			if(a[i]>b[j])
			{
				if(done[ai[i]]!=1)
				{
					tip=tip+a[i];
					x--;
					done[ai[i]]=1;
				}
				i++;				
			}
			else 
			{
				if(done[bi[j]]!=1)
				{
					tip=tip+b[j];
					y--;
					done[bi[j]]=1;
				}
				j++;				
			}
		}
		System.out.println(tip);
	}
	catch(Exception e)
	{
		e.printStackTrace();
	}
	finally
	{	in.close();
	}
}
}
