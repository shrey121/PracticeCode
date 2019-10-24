//this program takes position(x,y) and position of lower left corner and upper right corner and calculates minimum distance from (x,y) to rectangle border

package CodingCompetition;

import java.util.Scanner;

public class RoyRectangle 
{	public static void main(String[] args)
	{	Scanner in=new Scanner(System.in);
		try
		{	int testCases=in.nextInt();
			for(int i=0;i<testCases;i++)
			{	int values[]=new int[6];
				int j;
				for(j=0;j<6;j++)
				{	values[j]=in.nextInt();
				}
				int distance[]=new int[4];
				distance[0]=values[1]-values[3];
				distance[1]=values[0]-values[2];
				distance[2]=values[5]-values[1];
				distance[3]=values[4]-values[0];
				int min=1000000001;
				for(j=0;j<4;j++)
				{	if(distance[j]<min)
					{	min=distance[j];
					}
				}
				System.out.println(min);
			}
		}
		finally
		{	in.close();
		}
	}
}