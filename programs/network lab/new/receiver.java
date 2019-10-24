import java.io.*;
import java.net.*;
public class receiver
{
	public static void main(String args[])throws Exception
	{
		String input="",output="";
		String plaintext="abcdefghijklmnopqrstuvwxyz";
		String ciphertext="QWERTYUIOPASDFGHJKLZXCVBNM";
		ServerSocket ss=new ServerSocket(3030);
		Socket soc=ss.accept();
		
		DataInputStream dis=new DataInputStream(soc.getInputStream());
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		input=dis.readUTF();
		System.out.print("Enter key : ");
		int shift=Integer.parseInt(br.readLine());

		for(int i=0;i<input.length();i++)
		{
			/*
			ch=input.charAt(i);
			pos=ciphertext.indexOf(ch);
			ch1=plaintext.charAt(pos);
			output=output+ch1;*/
			int offset;

			if(input.charAt(i)!=' ')
			{
				offset=((int)(input.charAt(i)))-97;
				offset=(offset-shift)%26;
				if(offset<0)
					offset+=26;
				output+=(char)(offset+97);
			}

			else
				output=output+input.charAt(i);

		}

		System.out.println("Decrypted Message : "+output);
	}
}