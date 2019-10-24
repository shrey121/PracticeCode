#include<stdio.h>
#include<conio.h>
void main()
{
int a[20][20],b[20][20],i,j,n,l,k,flag,flag1;

FILE *f;
clrscr();
f=fopen("in2.txt","r");
fscanf(f,"%d",&n);
printf("%d",n);
printf("\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
fscanf(f,"%d",&a[i][j]);
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
b[i][j]=0;
printf("%d ",a[i][j]);
}
printf("\n");
}
for(i=1;i<=n;i++)
{
for(j=i;j>=1;j--)
{
if(a[j][i]==1 && j!=i)
{
b[j][i]=1;
break;
}
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d  ",b[i][j]);
}
printf("\n");
}
getch();
}
