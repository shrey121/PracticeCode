#include<stdio.h>
int main()
{
	FILE *f;
	int w[6],t[6],num[6],n=0,temp,i=0,pr,j=0,l=0,k=0,x[10],p[10],m=0;
	f=fopen("file.txt","r");
	char ch,b[20][100];
	float awt=0,att=0;
	do
	{
		ch=fgetc(f);
		if(ch!='\n')
		{
			b[j][i]=ch;
			i++;
		}
		else
		{
			b[j][i]='\n';
			j++;
			i=0;
		}
	}while(ch!=EOF);
	b[j][i]='\n';
	for(k=0;k<j;k++)
	{
		for(l=0;b[k][l]!='\n';l++)
		{
			printf("%c",b[k][l]);
		}
		printf("\n");
	}
	i=0;
	pr=1;
	for(k=0;k<=j;k++)
	{
		for(l=0;b[k][l]!='\n';l++)
		{
			if(b[k][l]==' ')
			{
				if(b[k][l+1]>=48&&b[k][l+1]<=57)
				{
					x[i]=b[k][l+1]-48;
					num[n++]=pr++;
					if(b[k][l+2]>=48&&b[k][l+2]<=57)
					{
						x[i]=(10*x[i])+(b[k][l+2]-48);
					}
					i++;	
				}
				if(b[k][l+2]==' ')
				{
					if(b[k][l+3]>=48&&b[k][l+3]<=57)
					{
						p[m]=b[k][l+3]-48;
						m++;
					}
					l=l+2;
				}
				else if(b[k][l+3]==' ')
				{
					if(b[k][l+4]>=48&&b[k][l+4]<=57)
					{
					p[m]=b[k][l+4]-48;
					m++;
					}
					l=l+3;
				}
		
			}
		}
	}
	w[0]=0;
	pr=1;
	for(l=0;l<i;l++)
	{
		for(m=0;m<i;m++)
		{
			if(p[l]<p[m])
			{
				temp=p[l];
				p[l]=p[m];
				p[m]=temp;
				temp=x[l];
				x[l]=x[m];
				x[m]=temp;
				temp=num[l];
				num[l]=num[m];
				num[m]=temp;
			}
		}
	}
	for(l=0;l<i;l++)
	{
		w[l+1]=w[l]+x[l];
	}
	for(l=0;l<i;l++)
	{
		t[l]=x[l]+w[l];
	}
	for(l=0;l<i;l++)
	{
		awt+=w[l];
		att+=t[l];
	}
	for(l=0;l<i;l++)
	{
		printf("--------");
	}
	printf("\n");
	for(l=0;l<i;l++)
	{
		printf("|  P%d  |",num[l]);
	}
	printf("\n");
	for(l=0;l<i;l++)
	{
		printf("--------");
	}
	printf("\n");	
	for(l=0;l<=i;l++)
	{
	printf("%d      ",w[l]);
	}
	printf("\nAvg waiting time=%f\n",awt/i);
	printf("Avg turnaround time=%f\n",att/i);
}
