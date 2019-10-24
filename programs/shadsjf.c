#include<stdio.h>
int main()
{
	int arr,arr1,wat=0,i=0,j=0,k=0,c[30],g[30],l=0,m=0,x[30],n=0,a[30],tt=0,temp=0,t[30],tat=0,w[30];
	float avg;
	char ch,b[20][30];
	FILE *f1;
	f1=fopen("file.txt","r");
	do
	{
                ch=fgetc(f1);
                //printf("%c",c);
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
	}while(!feof(f1));
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
	}
	printf("\n");
	//printf("\ntt=%d",tt);
	arr1=0;
	for(k=0;k<tt;k++)
	{
		arr=tt;
		for(l=0;l<i;l++)
		{
			if(a[l]<=k)
			{
				if(x[l]>=0&&arr==tt)
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
			c[n]=k;
			g[n]=arr1+1;
			n++;
		}
		x[arr]--;
		arr1=arr;
		if(x[arr]==0)
		{
			t[arr]=k+1;
			x[arr]=100;
		}
	}
	for(k=0;k<n;k++)
	{
		printf("__________");
	}
	
	printf("\n|");
	for(k=0;k<n;k++)
	{
		printf("   p%d  |",g[k]);
	}
	printf("  p%d  |\n",arr1+1);
	for(k=0;k<n;k++)
	{
		printf("----------");
	}
	printf("\n0\t");
	for(k=0;k<n;k++)
	{
		printf("%d\t",c[k]);
	}
	printf("%d",tt);
	printf("\n");
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
		tat=tat+t[k]-a[k];
	}
	printf("\n");
	for(k=0;k<i;k++)
	{
		w[k]=t[k]-a[k]-x[k];
		//printf("w[%d]=%d\t",k+1,w[k]);
		wat=wat+w[k];
	}
	avg=(float)tat/i;
	printf("\n Average Turnaround Time= %f",avg);
	avg=(float)wat/i;
	printf("\n Average waiting time= %f\n",avg);
}
