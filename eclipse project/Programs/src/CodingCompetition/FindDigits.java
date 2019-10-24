/*
 * 11
123456789
114108089
110110015
121
33
44
55
66
77
88
106108048
 */

package CodingCompetition;

import java.util.Scanner;

public class FindDigits
{	public static void main(String[] args)
	{	Scanner in=new Scanner(System.in);
		int testCases,counter;
		long i,num,temp,t;
		try
		{	testCases=in.nextInt();
			for(int j=0;j<testCases;j++)
			{	counter=0;
				temp=-1;
				num=in.nextInt();
				for(i=10;num>(i/10);i=i*10)
				{	if(i==10)
					{	temp=num%(num%i);
					}
					else
					{	t=(((num%i)-(num%(i/10)))/(i/10));
						if(t!=0)
						{	temp=num%t;
						}
					}					
					if(temp==0)
					{	counter++;
					}
				}
				System.out.println(counter);
			}
		}
		finally
		{	in.close();
		}
	}
}