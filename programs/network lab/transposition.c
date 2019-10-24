#include<stdio.h>
#include<string.h>
int main()
{	char st[50],k[10];
	char m[10][10],ch;
	int i,j,l,l1,p,r,t;
	int n[10];
	
	printf("\nEnter key:\t");
	gets(k);
	fflush(stdin);
	
	i=0;
	printf("Enter string:\t");
	scanf("%c",&ch);
	st[i]=ch;
	i++;
	while(ch!='\n')
	{	scanf("%c",&ch);
		st[i]=ch;
		i++;
	}

	//printf("%s",st);
	l=strlen(k);
	for(i=0;i<10;i++)
	{	for(j=0;j<10;j++)
		{	m[i][j]='*';
		}
	}
		
	i=0;	j=0;
	for(p=0;st[p]!='\n';p++)
	{	if(st[p]!=' '&&st[p]!='.'&&st[p]!=',')
		{	m[i][j]=st[p];
			j++;
			if(j==l)
			{	j=0;
				i++;
			}
		}
	}
	if(j!=0)
	{	while(j!=l)
		{	m[i][j]='$';
			j++;
		}
	}
	r=i+1;
	
	printf("\nGenerated matrix:\n");
	for(i=0;i<r;i++)
	{	for(j=0;j<l;j++)
		{	//if(m[i][j]!='*'&&m[i][j]!='$')
			{	printf("%c ",m[i][j]);
			}
		}
		printf("\n");
	}
	
	t=0;
	printf("\nEncrypted text:\t");
	for(i=97;i<123;i++)
	{	for(j=0;j<l;j++)
		{	if(k[j]==i)
			{	for(p=0;p<r;p++)
				{	//if(m[p][j]!='$')
						printf("%c ",m[p][j]);
						st[t]=m[p][j];
						t++;
				}
			}
		}	
	}
	//puts(st);
	printf("\nEnter key to decrypt:\t");
        gets(k);
        fflush(stdin);
	l=strlen(k);
	l1=strlen(st);
	l1=l1/l;
	for(i=0;i<10;i++)
        {       for(j=0;j<10;j++)
                {       m[i][j]='*';
                }
        }
	t=0;
	for(i=0;i<l;i++)
	{	for(j=0;j<l1;j++)
		{	m[i][j]=st[t];
			t++;
		}
	}
	printf("\nMatrix created:\n");
	for(i=0;i<10;i++)
        {       for(j=0;j<10;j++)
                {       if(m[i][j]!='*')
				printf("%c ",m[i][j]);
                }
		printf("\n");
        }
	for(i=0;i<10;i++)
	{	n[i]=0;
	}	
	p=1;
	for(i=97;i<123;i++)
        {       for(j=0;j<l;j++)
                {       if(k[j]==i)
                        {  	n[j]=p;
				p++;
                        }
                }
        }
	for(i=0;i<l;i++)
	{	//printf("%d ",n[i]);
	}
	
	printf("\nDecrypted text:\n");
	//printf("%d %d",l1,l);
	for(j=0;j<l1;j++)
	{	for(i=0;i<l;i++)
		{	p=(n[i]-1);
			if(m[p][j]!='$')
				printf("%c ",m[p][j]);
		}
	}
	printf("\n");
	return 0;
}
