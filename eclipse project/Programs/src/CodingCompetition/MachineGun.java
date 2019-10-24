package CodingCompetition;

import java.util.Arrays;
import java.util.Scanner;

class MachineGun 
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		try
		{	
			int s = in.nextInt();
			int l[]=new int[s];
			int i;
			
			for(i=0;i<s;i++)
			{
				l[i]=in.nextInt();
			}
			
			Arrays.sort(l);
				
			for(i=0;i<s-1;i++)
			{
				System.out.print(l[i]-i+" ");
			}
			
			System.out.print(l[i]-i);
		}
		finally
		{	
			in.close();
		}
	}
}
