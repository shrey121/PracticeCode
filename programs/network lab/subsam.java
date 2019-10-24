import java.util.*;
class array
{
    public static void main(String args[])
    {
	int i,j,offset,de_offset,flag;
	char text[];
	char code[]=new char[30];
	
	System.out.println("Enter the plaintext: ");
	
	Scanner sc=new Scanner(System.in);
        //System.out.println("Please enter elements...");
        text=sc.next().toCharArray();
        System.out.println("Array elements are : ");
        for (i=0;i<text.length;i++)
            System.out.println(text[i]);


	//System.out.flush;
	
	System.out.println("Enter the key: ");
	offset=sc.nextInt();

        offset=offset%26;

	for(i=0;i<text.length;i++)
	{
		if(text[i]+offset<=122)
		{
			code[i]=(char)((int)text[i]+offset);
		}

		else
		{
			code[i]=(char)((int)text[i]+offset-26);
		}
	}

	for (j=0;j<i;j++)
            System.out.println(code[j]);

	
//	System.out.println("Cipher text: " + code);
/*
	printf("Enter the key: ");
	scanf("%d",&de_offset);

	if(offset!=de_offset)
	{
		printf("Provided key is wrong");
		flag=1;
	}

	if(flag!=1);
	{	
		for(i=0;i<strlen(code);i++)
		{
			if(code[i]<65+offset)
			{
				decrypt[i]=code[i]-offset+26;
			}

			else
			{
				decrypt[i]=code[i]-offset;
			}
		}

		printf("Decrypted text: %s",decrypt);
	}
*/

	}
}
