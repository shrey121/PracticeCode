package Steganography;

import java.awt.image.BufferedImage;
import java.util.Random;

/**
 * This class embeds the given message in the given image.
 * @author Shreyansh,Afsha
 */

public class putMessage 
{
	BufferedImage img;
	char[] msg;
	int index;
	Random key;
	boolean keyInserted = false;
	
	putMessage(BufferedImage tempimg, char[] tempmsg, long seed)
	{
		img = tempimg;
		msg = tempmsg;
		key = new Random(seed);
		index=0;
	}
	
	/**
	 * This method embeds message in Zig Zag pattern. 
	 * @return image with embeded message
	 */
	
	BufferedImage startPuttingZigZag()
	{
		int maxX = img.getWidth(), maxY = img.getHeight(), y = 1, x = 1, flag = 0;
		//x and y are 1 because we have to leave 1st row and column
		//we are travelling in zig zag pattern
		while(y < maxY && index < msg.length)	
		{
			if(flag == 0)
			{
				getsetvalue(x,y);
				flag = 1;
				y++;
			}
			else
			{
				getsetvalue(x,y);
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
		//in last row, message will be filled linearly
		if(index < msg.length)
		{
			y--;
			x=2;
			while(index < msg.length)
			{
			//fill msg linearly
				getsetvalue(x,y);
				x++;
			}
		}
		return img;
	}
	
	/**
	 * This method takes the pixel position and calculates the new RGB values after embedding message bits.
	 * @param x x coordinate of pixel
	 * @param y y coordinate of pixel
	 */
	
	void getsetvalue(int x, int y)
	{
		int rgb, currentColor, upperLeftColor, upperColor, leftColor, newColor, plane;
		int difference, numberOfBitsInserted, temp, nBitDecimalValue, tempStart, tempEnd, i, j, value;
		
		if(keyInserted==false)
		{
			//we are embedding length of message (which is key also) in red plane only.
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
		
		//step 4.1
		//d is difference
		difference = Utility.max(upperLeftColor,upperColor,leftColor) - Utility.min(upperLeftColor,upperColor,leftColor);
		System.out.println("d= "+difference);
		
		//step 4.2
		//n is numberOfBitsInserted
		if(difference<3)
		{
			numberOfBitsInserted=1;
		}
		else
		{
			if(difference%2 == 0)	//even
			{
				numberOfBitsInserted = (int) ((Math.log(difference)/Math.log(2))-1);
			}
			else	//odd
			{ 
				numberOfBitsInserted = (int) (Math.log(difference)/Math.log(2));
			}
		}
		
		//step 4.3
		//b is nBitDecimalValue
		//t is temp
		tempStart = index;
		tempEnd = index + numberOfBitsInserted - 1;
		if(tempEnd>(msg.length-1))
		{
			tempEnd=(msg.length-1);
			numberOfBitsInserted=tempEnd-tempStart+1;
		}
		index=tempEnd+1;
		
		if(index>20)
		{
			keyInserted=true;
		}
		
		for(i=tempEnd, j=1, nBitDecimalValue=0; i >= tempStart; i--, j=j*2)
		{
			if(msg[i]=='1')
			{
				nBitDecimalValue = nBitDecimalValue + j;
			}
		}
		
		System.out.println(numberOfBitsInserted+" bits at index till "+index+" will be inserted in pixel("+x+","+y+") in plane"+plane);
		System.out.println("Decimal value(b): "+nBitDecimalValue);
		
		temp = nBitDecimalValue - (currentColor % (int)(Math.pow(2,numberOfBitsInserted)));
		System.out.println("t value: "+temp);
		
		//step 4.4
		//t1 is value
		if(temp >= (double)(-(((int)(Math.pow(2,numberOfBitsInserted)))-1)/2) && temp < (double)(((int)(Math.pow(2,numberOfBitsInserted)))-1)/2)
		{
			value = temp;
		}		
		else if(temp >= (double)(- (((int)(Math.pow(2,numberOfBitsInserted)))+1)) && temp < (double)(-(((int)(Math.pow(2,numberOfBitsInserted)))-1)/2))
		{
			value = temp+(int)(Math.pow(2,numberOfBitsInserted));
		}		
		else if(temp >= (double)(((int)(Math.pow(2,numberOfBitsInserted)))-1)/2 && temp < (double)(int)(Math.pow(2,numberOfBitsInserted)))
		{
			value = temp-(int)(Math.pow(2,numberOfBitsInserted));
		}		
		else
		{
			value = temp;
		}		
		System.out.println("t1 value: "+value);
		
		//step 4.5
		newColor=currentColor+value;
		System.out.println("color value changed from "+currentColor+" to "+newColor);
		
		if(newColor <= 255 && newColor >=0)
		{
			rgb = img.getRGB(x, y);
			
			String sb = Integer.toBinaryString(rgb);
			System.out.println("old rgb: "+sb);
			
			if(plane==0)
			{
				i = rgb & 0xFF00FFFF;
				rgb = (newColor << 16) | i;
				img.setRGB(x, y, rgb);
			}
			else if(plane==1)
			{
				i = rgb & 0xFFFF00FF;
				rgb = (newColor << 8) | i;
				img.setRGB(x, y, rgb);
			}
			else
			{
				i = rgb & 0xFFFFFF00;
				rgb = newColor | i;
				img.setRGB(x, y, rgb);
			}
			
			sb = Integer.toBinaryString(rgb);
			System.out.println("new rgb: "+sb);
		}
		else
		{
			//error: new pixel value is exceeding 256 or negative.
			//if new pixel value comes negative then whole color will change because negative number are represented as 1's complement
		}
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
