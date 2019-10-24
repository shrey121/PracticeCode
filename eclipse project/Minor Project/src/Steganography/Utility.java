package Steganography;

/**
 * This class have basic functions which are used across classes.
 * @author Shreyansh, Afsha
 */

public class Utility 
{
	
	/**
	 * this method calculates the maximum of 3 values
	 * @param a
	 * @param b
	 * @param c
	 * @return maximum value
	 */
	
	static int max(int a,int b,int c)
	{
		int max = -2147483648;
		if(a>max)
		{
			max=a;
		}
		if(b>max)
		{
			max=b;
		}
		if(c>max)
		{
			max=c;
		}
		return max;
	}
	
	/**
	 * this method calculated the minimum of 3 values
	 * @param a
	 * @param b
	 * @param c
	 * @return minimum value
	 */
	
	static int min(int a,int b,int c)
	{
		int min = 2147483647;
		if(a<min)
		{
			min=a;
		}
		if(b<min)
		{
			min=b;
		}
		if(c<min)
		{
			min=c;
		}
		return min;
	}
	
	/**
	 * this method converts the data in binary array
	 * @param data
	 * @return binary frame
	 */
	
	static char[] convertBinary(int data)
	{
		int i, j;	// k, hammingBit, position;	//using even parity
		char temp;
		char binary[] = new char[16];
		
		System.out.println("From convertBinary: "+data);
		
		for(i = 0; i < 16; i++)	//filling array with 0's
		{
			binary[i] = '0';
		}
		
		for(i = 0; data != 1 && i<15; i++)	//calculating binary 
		{
			j = (data % 2) + 48;
			binary[i] = (char)j;
			data = data / 2;
		}
		
		binary[i] = '1';
		
		for(i = 0, j = 15; i < 8; i++, j--)	//swapping array
		{
			temp = binary[j];
			binary[j] = binary[i];
			binary[i] = temp;
		}

		String str=new String(binary);
		System.out.println("binary: "+str);
		return binary;
	}
}
