package CodingCompetition;

import java.util.Scanner;

public class RiverRock 
{	static int calculateValue(int val)
	{	int i,temp,sum=0;
		if(val<10)
		{	return (val+val);	
		}	
		if(val==10)
		{	return (val+1);
		}
		for(i=10;val>(i/10);i=i*10)
		{	temp=val%i;
			if(i>10)
			{	temp=temp-(temp%(i/10));
				temp=temp/(i/10);
			}
			sum=sum+temp;
		}
		return sum;
	}
	
	public static void main(String[] args)
	{	Scanner in= new Scanner(System.in);
		int rock, i, testCases;
		int river[]=new int[3];
		boolean run=true;
		try
		{	System.out.println("Enter the number of test cases\n");
			testCases=in.nextInt();
			for(int j=0;j<testCases;j++)
			{	System.out.println("Enter the value of rock\n");
				rock=in.nextInt();
				river[0]=1;
				river[1]=3;
				river[2]=9;
				i=0;
				while(run)
				{	if(river[i]<rock)
					{	river[i]=calculateValue(river[i]);
					}
					else if(river[i]==rock)
					{	System.out.println((i+1)+" "+rock);
						run=false;
					}
					else if(river[i]>rock)
					{	i++;
						if(i==3)
						{	i=0;
							rock=calculateValue(rock);
						}
					}
				}
			}
		}
		finally
		{	in.close();
		}
	}
}
