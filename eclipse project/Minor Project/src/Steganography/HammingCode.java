package Steganography;

//method used to calculate the hamming code is referred from
//http://users.cis.fiu.edu/~downeyt/cop3402/hamming.html

/**
 * this class contains operations related to calculation of hamming code
 * @author Shreyansh,Afsha
 */

public class HammingCode 
{
	/**
	 * this method takes the message string and convert it into char array with hamming bits
	 * @param msg message string
	 * @return char string with hamming bits
	 */
	
	static char[] encrypt(String msg)
	{	
		System.out.println("Message to be encrypted: "+msg);
		int i, j, k = 0, temp;
		char tempMsg[] = msg.toCharArray();
		char frame[] = new char[21];
		i = (tempMsg.length) * 21 + 21;	//Using unicode system + hamming bits
		//Additional 21 bits will contain msg length at starting which will help in extracting msg
		
		char data[] = new char[i];
		
		//Adding msg length in starting. if msg=HELLO then msg.length=5 not 5*21
		frame = insertBits(msg.length());
		for(j = 0; j < 21; j++, k++)
		{
			data[k] = frame[j];
		}
		
		for(i = 0; i < tempMsg.length; i++)	//converting message into binary bits
		{
			temp=(int)tempMsg[i];
			frame = insertBits(temp);
			for(j = 0; j < 21; j++, k++)
			{
				data[k] = frame[j];
			}
		}
		//String temp=new String(data);
		//System.out.println("binary: "+temp);
		
		String temp2=new String(data);
		System.out.println("Encrypted text: "+temp2);
		
		return data;
	}
	
	/**
	 * this method takes one character and makes a frame of data bits and hamming bits
	 * @param data character to be converted 
	 * @return the frame of 21 bits having data and hamming bits
	 */
	
	static char[] insertBits(int data)
	{
		int i, j, k, hammingBit, position;	//using even parity
		//char temp;
		char binary[] = new char[16];
		char frame[] = new char[21];
		
		binary = Utility.convertBinary(data);
		
		for(i = 0; i < 21; i++)	
		{
			frame[i] = '0';
		}
		
		for(i = 0; i < 16; i++)	
		{
			frame[i] = binary[i];
		}
		
		for(i = 1; i < frame.length; i = i * 2)	//shifting data to make space for hamming bits
		{
			for(j = (frame.length) - 1; j >= i; j--)
			{
				frame[j] = frame[j - 1];
			}
		}
		
		for(position = 1; position <= frame.length; position = position*2)
		{
			position--;
			hammingBit = 0;
			i = position+1;
			j = i - 1;
			k = position + 1;
			while(k < frame.length)	//calculating parity bit
			{
				if(j != 0)
				{
					if(frame[k] == '1' && hammingBit == 0)
					{	
						hammingBit = 1;
					}
					else if(frame[k] == '1' && hammingBit == 1)
					{
						hammingBit = 0;
					}
					k++;
					j--;
				}
				else
				{
					for(j = 0; j < i && k < frame.length; j++, k++);
					j = i;
				}
			}
			hammingBit = hammingBit + 48;
			frame[position] = (char)hammingBit;	//storing parity
			position++;
			//System.out.println("parity "+position+": "+(int)(parity-48));
		}
		
		System.out.println(frame);
		
		return frame;
	}

	/**
	 * this methods remove the hamming bits and convert message into original form
	 * @param msgBits array containing data and hamming bits
	 * @return message string
	 */
	
	static String decrypt(char[] msgBits)
	{
		int i, j, k, count=-1, value;
		char frame[]=new char[21];
		char binary[]= new char[16];
		
		char msg[]=new char[((msgBits.length)/21)];
		
		for(k=0; k<msgBits.length; k+=21)
		{
			//extracting each character frame
			for(j=0;j<21;j++)
			{
				frame[j]=msgBits[k+j];	
			}
			
			frame=check(frame);
			
			//performing shift operation
			for(i=0, j=-1; i<21; i++)
			{
				if(i==0||i==1||i==3||i==7||i==15)
				{
					continue;
				}
				else
				{
					binary[++j]=frame[i];
				}
			}
			
			value=0;
			
			//calculating the decimal value of each character
			for(i=15,j=0;i>=0;i--,j++)
			{
				if(binary[i]=='1')
				{
					value+=(int)Math.pow(2, j);
				}
			}
						
			System.out.println(binary);
			System.out.println("value : "+value);
			
			//if character is a number
			/*if(value>=0 && value<=9)
			{
				value+=48;
			}
			*/			
			msg[++count]= (char)value;					
		}
				
		String message = new String(msg);
		System.out.println(message);
		return message;				
	}
	
	/**
	 * checks for any error in frame while embedding or extraction of bits
	 * @param msgBits bits to be checked
	 * @return the corrected bits
	 */
	
	static char[] check(char[] msgBits)
	{
		int i, p1=0, p2=0, p4=0, p8=0, p16=0, error=0, temp; //parity bits
		
		//calculating parity p1
		for(i=0; i<21; i+=2)
		{
			temp=(int)(msgBits[i]-48);
			p1+=temp;
		}
		if(p1%2!=0)
		{
			error+=1;
		}
		
		//calculating parity p2
		for(i=1; i<21; i+=4)
		{
			temp=(int)(msgBits[i]-48)+(int)(msgBits[i+1]-48);
			p2+=temp;
		}
		
		if(p2%2!=0)
		{
			error+=2;
		}
		
		//calculating parity p4
		for(i=3;i<19;i+=8)
		{
			temp=(int)(msgBits[i]-48)+(int)(msgBits[i+1]-48)+(int)(msgBits[i+2]-48)+(int)(msgBits[i+3]-48);
			p4+=temp;
		}
		temp=(int)(msgBits[19]-48)+(int)(msgBits[20]-48);
		p4+=temp;
		
		if(p4%2!=0)
		{
			error+=4;
		}
		
		//calculating parity p8
		for(i=7; i<15; i++)
		{
			temp=(int)(msgBits[i]-48);
			p8+=temp;
		}
		
		//p8=msgBits[7]+msgBits[8]+msgBits[9]+msgBits[10]+msgBits[11]+msgBits[12]+msgBits[13]+msgBits[14];
		
		if(p8%2!=0)
		{
			error+=8;
		}
		
		//calculating parity p16
		for(i=15; i<21; i++)
		{
			temp=(int)(msgBits[i]-48);
			p16+=temp;
		}
		
		//p16=msgBits[15]+msgBits[16]+msgBits[17]+msgBits[18]+msgBits[19]+msgBits[20];
		
		if(p16%2!=0)
		{
			error+=16;
		}
		
		//plz see what should be returned when there exist multiple errors
		//if(error>20)
			//System.out.println("MULTIPLE ERRORS IN MESSAGE");
				
		 if(error==0)
		 {
			 System.out.println("NO ERRORS IN MESSAGE");
			return msgBits;
		 }
		else
		{			
			System.out.println(" ERRORS IN MESSAGE");
			
			//correcting error
			if(msgBits[error-1]=='1')
			{
				msgBits[error-1]='0';
			}
			else
			{
				msgBits[error-1]='1';
			}
				
			return msgBits;
		}
	}
}
