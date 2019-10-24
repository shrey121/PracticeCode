package CodingCompetition;

import java.util.Scanner;

public class BinaryCombination 
{
	public static void main(String[] args) 
	{
		Scanner in = new Scanner(System.in);
		try 
		{
			int n = in.nextInt();
			int k = in.nextInt();
			double totalCombination, possibleCombination;
			totalCombination=Math.pow(2,n);
			possibleCombination=Math.pow(2,(n-k+1))-1;
			for(int i=2;i<Math.sqrt(totalCombination);i++)
			{
				if(i%possibleCombination==0 && i%totalCombination==0)
				{
					possibleCombination=possibleCombination/i;
					totalCombination=totalCombination/i;
				}
			}			
			System.out.println((int)possibleCombination+"/"+(int)totalCombination);
			
		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		} 
		finally 
		{
			in.close();
		}
	}
}
