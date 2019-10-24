#include<stdio.h>
#include<string.h>

 int main()
{
	static int i,j,offset,de_offset,flag;
	static char text[30],code[30],decrypt[30];
	
	printf("Enter the plaintext: ");
	gets(text);
	fflush(stdin);
	
	printf("Enter the key: ");
        scanf("%d",&offset);
	fflush(stdin);

        offset=offset%26;

	for(i=0;i<strlen(text);i++)
	{
		if(text[i]+offset<=122)
		{
			code[i]=text[i]+offset;
		}

		else
		{
			code[i]=text[i]+offset-26;
		}
	}

	printf("Cipher text: %s",code);

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


}
