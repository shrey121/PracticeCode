package Steganography;

import java.awt.image.BufferedImage;
import java.util.Random;

/**
 * this class is used to extract the message embedded in the image
 * @author Shreyansh,Afsha
 */

public class getMessage 
{
	BufferedImage img;
	char[] binary = new char[16];
	boolean keyExtracted=false;
	Random key;
		
	public getMessage(BufferedImage tempimg)
	{
		img=tempimg;
	}
	
	/**
	 * extracts the message bits which were embedded in zig zag pattern
	 * @return extracted message bits
	 */
	
	char[] startGettingZigZag()
	{
		char[] tempBinary = new char[16];
		char[] frame = new char[21];
		int maxX = img.getWidth(), maxY = img.getHeight(), y = 1, x = 1, flag = 0, length=0, i, j, mi=0, fi=0, bi=0;
		int numberOfBitsExtracted;
		//x and y are 1 because we have to leave 1st row and column
		
		//we are traveling in zig zag pattern
		while(fi<21)	
		{
			if(flag == 0)
			{	
				System.out.println(" pixel("+x+","+y+")");
				numberOfBitsExtracted=getvalue(x,y);
				
				for(bi=0;bi<(16-numberOfBitsExtracted);bi++);
				for(; bi<16 && fi<21; bi++,fi++)
				{
					frame[fi] = binary[bi];
				}
				
				if(bi==16)
				{	flag = 1;
					y++;
				}
			}
			else
			{
				System.out.println(" pixel("+x+","+y+")");
				numberOfBitsExtracted=getvalue(x,y);
				
				for(bi=0;bi<(16-numberOfBitsExtracted);bi++);
				for(; bi<16 && fi<21; bi++,fi++)
				{
					frame[fi] = binary[bi];
				}
				
				if(bi==16)
				{	
					flag=0;
					y--;
					x++;
					if(x == maxX)
					{
						y = y+2;
						x = 1;
					}
				}
			}
		}
		
		frame=HammingCode.check(frame);
		String str=new String(frame);
		System.out.println("Length frame: "+str);
			
		//performing shift operation
		for(i=0, j=-1; i<21; i++)
		{
			if(i==0||i==1||i==3||i==7||i==15)
			{
				continue;
			}
			else
			{
				tempBinary[++j]=frame[i];
			}
		}
		
		//calculating the decimal value of each character
		for(i=15,j=0;i>=0;i--,j++)
		{
			if(tempBinary[i]=='1')
			{
				length+=(int)Math.pow(2, j);
			}
		}
		
		System.out.println("Length: "+length);
		
		key=new Random(length);
		keyExtracted=true;

		char[] msg = new char[length*21];
		
		if(bi!=16)
		{
			for(; bi<16 && mi<msg.length; bi++, mi++)
			{
				msg[mi] = binary[bi];
			}
		}
		
		while(y < maxY && mi<msg.length)	
		{
			if(flag == 0)
			{
				numberOfBitsExtracted=getvalue(x,y);
				
				for(bi=0;bi<(16-numberOfBitsExtracted);bi++);
				for(; bi<16 && mi<msg.length; bi++,mi++)
				{
					msg[mi] = binary[bi];
				}
				
				flag = 1;
				y++;
			}
			else
			{
				numberOfBitsExtracted=getvalue(x,y);
				for(bi=0;bi<(16-numberOfBitsExtracted);bi++);
				for(; bi<16 && mi<msg.length; bi++,mi++)
				{
					msg[mi] = binary[bi];
				}
				
				flag=0;
				y--;
				x++;
				if(x == maxX)
				{
					y = y+2;
					x = 1;
				}
			}
		}
		//in last row message will be filled linearly
		if(mi<msg.length)
		{
			y--;
			x=2;
			while(mi<msg.length)
			{
			//fill msg linearly
				
				numberOfBitsExtracted=getvalue(x,y);
				for(bi=0;bi<(16-numberOfBitsExtracted);bi++);
				for(; bi<16 && mi<msg.length; bi++,mi++)
				{
					msg[mi] = binary[bi];
				}
				
				x++;
			}
		}
		
		return msg;
	}
	
	/**
	 * extracts message bits from the given pixel.
	 * @param x x coordinate of pixel
	 * @param y y coordinate of pixel
	 * @return number of bits extracted
	 */
	
	int getvalue(int x, int y)
	{
		int currentColor, upperLeftColor, upperColor, leftColor, difference, numberOfBitsExtracted, nBitDecimalValue, plane;
		
		if(keyExtracted==false)
		{
			plane=0;
		}
		else
		{	
			plane = key.nextInt()%3;
			if(plane<0)
			{
				plane = -plane;
			}
		}
				
		System.out.println("Message is extracted from plane "+ plane);
		
		if(plane==0)
		{
			//putting red values of pixel
			currentColor = getRed(x, y);
			upperLeftColor = getRed(x-1, y-1);
			upperColor = getRed(x, y-1);
			leftColor = getRed(x-1, y);
		}
		else if(plane==1)
		{
			//putting green values of pixel
			currentColor = getGreen(x, y);
			upperLeftColor = getGreen(x-1, y-1);
			upperColor = getGreen(x, y-1);
			leftColor = getGreen(x-1, y);
		}
		else
		{
			//putting blue values of pixel
			currentColor = getBlue(x, y);
			upperLeftColor = getBlue(x-1, y-1);
			upperColor = getBlue(x, y-1);
			leftColor = getBlue(x-1, y);
		}
		
		//step 3
		//d is difference
		difference = Utility.max(upperLeftColor,upperColor,leftColor) - Utility.min(upperLeftColor,upperColor,leftColor);
		
		//step 4
		//n is numberOfBitsExtracted
		if(difference<3)
		{
			numberOfBitsExtracted=1;
		}
		else
		{
			if(difference%2 == 0)	//even
			{
				numberOfBitsExtracted = (int) ((Math.log(difference)/Math.log(2))-1);
			}
			else	//odd
			{ 
				numberOfBitsExtracted = (int) (Math.log(difference)/Math.log(2));
			}
		}
		
		//step 5
		nBitDecimalValue = currentColor % (int)(Math.pow(2,numberOfBitsExtracted));
		
		System.out.println(nBitDecimalValue+" value extracted from pixel("+x+","+y+")");
		
		binary = Utility.convertBinary(nBitDecimalValue);
		
		return numberOfBitsExtracted;
		//System.out.println(num++ +" iterations completed");
	}
	
	/**
	 * this method calculates red value of pixel
	 * @param x x coordinate of pixel
	 * @param y y coordinate of pixel
	 * @return red value of the pixel
	 */
	
	int getRed(int x, int y)
	{
		int rgb = img.getRGB(x, y);
		int color = (rgb >> 16) & 0x000000FF;
		return color;
	}
	
	/**
	 * this method calculates green value of pixel
	 * @param x x coordinate of pixel
	 * @param y y coordinate of pixel
	 * @return green value of the pixel
	 */
	
	int getGreen(int x, int y)
	{
		int rgb = img.getRGB(x, y);
		int color = (rgb >> 8) & 0x000000FF;
		return color;
	}
	
	/**
	 * this method calculates blue value of pixel
	 * @param x x coordinate of pixel
	 * @param y y coordinate of pixel
	 * @return blue value of the pixel
	 */
	
	int getBlue(int x, int y)
	{
		int rgb = img.getRGB(x, y);
		int color = rgb & 0x000000FF;
		return color;
	}
}
