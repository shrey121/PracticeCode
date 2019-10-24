#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *p;
	int fs[10],fa[10][10],cs,init,i=0,j=0,m,n,size;
	char c=' ',str[100],ch;
	p=fopen("automata.txt","r");
	fscanf(p,"%d\n",&init);
	while(c!='\n')
	{	
		fscanf(p,"%d%c",&fs[i],&c);
		i++;
	}
	size=i;
	i=0;
	while(!feof(p))
	{
        fscanf(p,"%d%c",&fa[i][j],&c);
		if(c=='\n')
		{
			i++;
			j=0;
		}
		else
		{
			j++;
			n=j;
		}
	}
	m=(i-1);
	printf("\nDFA:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d\t",fa[i][j]);
		}
		printf("\n");
	}
	do
	{
        fflush(stdin);
	    printf("\nEnter the string:\n");
	    gets(str);
	    cs=init;
	    i=0;
	    while(cs!=-1&&str[i]!='\0')
	    {
		 cs=fa[cs][str[i]-97];
		 i++;
	    }
	    if(str[i]!='\0')
	    {
		 printf("\nString not accepted\n");
	    }
	    else if(cs==-1)
	    {
		 printf("\nString not accepted\n");
	    }
	    else
	    {
		 for(i=0;i<size;i++)
		 {
			if(cs==fs[i])
			{
				printf("\nString accepted\n");
				break;
			}
		 }
	    }
     	printf("\nDo you want to enter more strings?(y/n)\n");
	   scanf("%c",&ch);
  }while(ch=='y');
  getch();
}
