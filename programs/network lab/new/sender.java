import java.io.*;
import java.net.*;
public class sender
{
	public static void main(String args[])throws Exception
 	{
  		char ch,ch1;
		int i,pos;
		String input="",output="";
		String plaintext="abcdefghijklmnopqrstuvwxyz";
		String serverip = args[0];
		String ciphertext="QWERTYUIOPASDFGHJKLZXCVBNM";

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Socket soc=new Socket(serverip,3030);
		DataOutputStream dos=new DataOutputStream(soc.getOutputStream());
		
		System.out.print("Enter Data To Send : ");
		input=br.readLine(); //attack
		System.out.print("Enter key : ");
		int shift=Integer.parseInt(br.readLine());

		for(i=0;i<input.length();i++)
		{
			/*
			ch=input.charAt(i);
			pos=plaintext.indexOf(ch);
			ch1=ciphertext.charAt(pos);
			output=output+ch1;*/
			int offset;

			if(input.charAt(i)>='a' && input.charAt(i)<='z')
			{
				offset=((int)(input.charAt(i)))-97;
				offset=(offset+shift)%26;
				output+=(char)(offset+97);
			}

			else if(input.charAt(i)>='A' && input.charAt(i)<='Z')
			{
				offset=((int)(input.charAt(i)))-65;
				offset=(offset+shift)%26;
				output+=(char)(offset+65);
			}

			else
				output=output+input.charAt(i);
		}

		System.out.println("ENCRYPTED DATA IS "+output);
		dos.writeUTF(output);
 	}
}