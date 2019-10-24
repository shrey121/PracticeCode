#include<stdio.h>
#include<string.h>
int main()
{	char table[26][26],m[20],k[20],ct[20],ch;
	int i,j,val,t;
	up:
	printf("\nEnter the message you want to encrypt:\t");
	gets(m);
	printf("Enter the key:\t");
	gets(k);
	if(strlen(m)!=strlen(k))
	{		printf("Number of characters are not same. enter again. ");
                goto up;
	}
	printf("\nThe text is encrypted according to table:\n\n");
	printf(" |");
	for(i=97;i<123;i++)
	{	ch=(char)(i);
		printf("%c ",ch);
	}
	printf("\n");
	for(i=0;i<54;i++)
	{	printf("-");
	}
	printf("\n");
	for(i=0,t=0;i<26;i++,t++)
	{	ch=(char)(i+97);
		printf("%c|",ch);
		for(j=0;j<26;j++)
		{	val=j+97+t;
			if(val>122)
			{	val=val-26;
			}	
			table[i][j]=(char)val;
			printf("%c ",table[i][j]);
		}
		printf("\n");
	}
	printf("\nCipher text:\t");
	val=strlen(m);
	for(t=0;t<val;t++)
	{	for(i=0;k[t]!=table[i][0];i++);
		for(j=0;m[t]!=table[0][j];j++);
		printf("%c",table[i][j]);
		m[t]=table[i][j];
	}
	up2:
	printf("\n\nEnter key to decrypt:\t");
	gets(k);
	if(strlen(m)!=strlen(k))
        {       printf("\nNumber of characters in message and key are not same.\nEnter again!!");
                goto up2;
        }
	printf("\nMessage:\t");
	val=strlen(m);
	for(t=0;t<val;t++)
        {       for(i=0;k[t]!=table[i][0];i++);
                for(j=0;m[t]!=table[i][j];j++);
                printf("%c",table[0][j]);
        }
	printf("\n");
	return 0;	
}
