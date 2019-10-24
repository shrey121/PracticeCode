#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *p;
	int arr,arr1,wat=0,h[30],i=0,j=0,k=0,l=0,m=0,x[30],n=0,a[30],tt=0,temp=0,t[30],tat=0,w[30];
	float avg;
	char ch,b[20][30];
	clrscr();
	p=fopen("pro.txt","r");
	do
	{
		ch=fgetc(p);
	       //	putch(ch);
	       //	getch();
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
	printf("\n\n\n");
	for(k=0;k<=j;k++)
	{
		for(l=0;b[k][l]!='\n';l++)
		{
			printf("%c",b[k][l]);
		}
		printf("\n");
	}
	i=0;
	for(k=0;k<=j;k++)
	{
		for(l=0;b[k][l]!='\n';l++)
		{
			if(b[k][l]==' ')
			{
				if(b[k][l+1]>=48&&b[k][l+1]<=57)
				{
					x[i]=b[k][l+1]-48;
					i++;
				}
			}
			else if(b[k][l]==116)
			{
				a[m]=b[k][l+1]-48;
				m++;
			}
		}
	}
	for(k=0;k<i;k++)
	{
		//printf("%d\t",x[k]);
		tt=tt+x[k];
	       //	getch();
	}
	printf("__________________________________________\n|");
	arr1=0;
	n=0;
	for(k=0;k<tt;k++)
	{
		arr=tt;
		for(l=0;l<i;l++)
		{
			if(a[l]<=k)
			{
				if(x[l]>0&&arr==tt)
				{
					arr=l;
				}
				else if(x[arr]>x[l])
				{
					arr=l;
				}
			}
		}
		if(arr1!=arr)
		{
			h[n]=k;
			n++;
			printf("   p%d  |",arr1+1);
		}
		x[arr]--;
		arr1=arr;
		if(x[arr]==0)
		{
			t[arr]=k+1;
			x[arr]=100;
		}
	}
	printf("   p%d   |\n",arr1+1);
	printf("|________________________________________|\n0\t");
	for(i=0;i<n;i++)
	{
		   printf("%d\t",h[i]);
	}
	printf("%d\n",tt);

	i=0;
	for(k=0;k<=j;k++)
	{
		for(l=0;b[k][l]!='\n';l++)
		{
			if(b[k][l]==' ')
			{
				if(b[k][l+1]>=48&&b[k][l+1]<=57)
				{
					x[i]=b[k][l+1]-48;
					i++;
				}
			}
		}
	}
	for(k=0;k<i;k++)
	{
		//printf("tt%d\t",t[k]);
		tat=tat+t[k];
	}
	printf("\n");
	for(k=0;k<i;k++)
	{
		w[k]=t[k]-a[k]-x[k];
		//printf("w[%d]=%d\t",k+1,w[k]);
		wat=wat+w[k];
	       //	getch();
	}
	avg=(float)tat/i;
	printf("\n Avg turnaround time is %f",avg);
	avg=(float)wat/i;
	printf("\n Avg waiting time is %f",avg);
	//printf("\n n= %d",n+1);
	getch();
}
