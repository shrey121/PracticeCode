//this program takes marks of students and calculate average marks. it prints number of students who got above average marks.

package CodingCompetition;

import java.util.Scanner;

public class AboveAverage 
{	public static void main(String[] args)
	{	Scanner in=new Scanner(System.in);
		try
		{	int testCases=in.nextInt();
			for(int i=0;i<testCases;i++)
			{	int students=in.nextInt();
				int marks[]=new int[students];
				int j;
				for(j=0;j<students;j++)
				{	marks[j]=in.nextInt();
				}
				int sum=0;
				for(j=0;j<students;j++)
				{	sum=sum+marks[j];
				}
				int average=sum/students;
				int counter=0;
				for(j=0;j<students;j++)
				{	if(marks[j]>average)
					{	counter++;
					}
				}
				System.out.println(counter);
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