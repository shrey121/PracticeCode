
#include<stdio.h>
#include<conio.h>
void main()
{
FILE *fp;
int i,j,n,row,col,k,l;
int path[10][10],r[10],count,flag,m,b[10];
char a[10][10],ch;
clrscr();
fp=fopen("cdin.txt","r+");
j=0;
i=0;
while((ch=fgetc(fp))!=EOF)
{
if(ch=='\n')
{
j=0;
i++;
}
else
{
a[i][j]=ch;
j++;
}
}


row=i+1;
col=j;
/*printf("\n%d %d\n",row,col);
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
printf("%c",a[i][j]);
}
printf("\n");
}

*/

for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
	
	path[i][j]=0;
}
}

/*code for finding the valid forward paths for each node 2 for direct path and 1 for indirect path*/ 
for(i=0;i<10;i++)
{
	l=0;
	for(j=i;j<10;j++)
	{
	for(k=j+1;k<10;k++)
	{
		if(a[j][k]=='1')
			{
			if(j==i)
			path[i][k]=2;
			else if(path[i][k]==0)
			path[i][k]=1;
			//printf("\n%d %d %d",path[i][l],j,k);
			
			//r[i]=l;
			//l++;
			
			}
		/*else
		{
		path[i][l]=0;
		l++;
		}*/
	}
	}
}

printf("\n\n\n\t\tvalid forward paths\n\n");
for(i=0;i<10;i++)
{
for(j=0;j<10;j++)
{
printf("%d",path[i][j]);
}
printf("\n");
}

/*code for finding dominator list*/

for(i=0;i<10;i++)
{
count=0;
printf("\n %d ",i+1);
for(j=0;j<10;j++)
{
	if(path[i][j]!=0)
	printf("%d ",j+1);
	if(path[i][j]==2)
	{
	b[count]=j;
	count++;
	}	
}
	if(count>1)
	{
	for(k=0;k<count;k++)
	{
	flag=0;

	for(l=0;l<count;l++)
	{

	if((path[b[l]][b[k]]==0)&&k!=l)
	{
	flag=1;
	break;
	}	
	}
	i++;
	if(flag==1)
	printf("\n %d %d",i+1,i+1);
	
	else
	{
	printf("\n %d ",i+1);
	for(m=0;m<10;m++)
	{
	if(path[i][m]!=0)
	printf("%d ",m+1);
	}
	}

	}
	}

}
getch();
}