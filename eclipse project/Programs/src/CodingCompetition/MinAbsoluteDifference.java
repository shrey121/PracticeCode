package CodingCompetition;

import java.util.Arrays;
import java.util.Scanner;

public class MinAbsoluteDifference 
{	
	//static int numbers[];
		
	public static void main(String args[]) 
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] numbers=new int[n];
		int i,j,diff,mindiff=Integer.MAX_VALUE;
		for(i=0;i<n;i++)
		{
			numbers[i]=in.nextInt();
		}
		
		//quickSort(0, numbers.length-1);
		Arrays.sort(numbers);
		
		for(i=0,j=1;j<n;i++,j++)
		{
			diff=numbers[j]-numbers[i];
			if(diff<mindiff)
			{
				mindiff=diff;
			}
		}
		for(i=0,j=1;j<n;i++,j++)
		{
			diff=numbers[j]-numbers[i];
			if(diff==mindiff)
			{
				System.out.print(numbers[i]+" "+numbers[j]+" ");
			}
		}
		
	}
	/*
	static void quickSort(int lowerIndex, int higherIndex) {
        
        int i = lowerIndex;
        int j = higherIndex;
        int mid=lowerIndex+(higherIndex-lowerIndex)/2;
        int pivot = numbers[mid];
        while (i <= j) {
            
            while (numbers[i] < pivot) {
                i++;
            }
            while (numbers[j] > pivot) {
                j--;
            }
            if (i <= j) {
                exchangeNumbers(i, j);
                i++;
                j--;
            }
        }
        if (lowerIndex < j)
            quickSort(lowerIndex, j);
        if (i < higherIndex)
            quickSort(i, higherIndex);
        
    }
	
	static void exchangeNumbers(int i, int j) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
*/
}
