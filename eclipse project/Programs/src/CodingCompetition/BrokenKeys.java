//this program takes some characters and a string then it calculates number of unique characters occurring in the string

package CodingCompetition;

import java.util.Scanner;

public class BrokenKeys 
{	public static void main(String[] args) 
	{	Scanner in=new Scanner(System.in);
		try
		{	int testCases=in.nextInt();
			for(int i=0;i<testCases;i++)
			{	String bk=in.nextLine();
				char[] brokenKeys=bk.toCharArray();
				String w=in.nextLine();
				char[] word=w.toCharArray();
				int wLength=w.length(), bkLength=bk.length(), j=0, k=0, counter=0;
				while(j<bkLength)
				{	k=0;
					out:
					{while(k<wLength)
					{	if(brokenKeys[j]==word[k])
						{	counter++;
							break out;
						}
						k++;
					}
					}
					j++;
				}
				System.out.println(counter);
			}
		}
		finally
		{	in.close();			
		}
	}
}
