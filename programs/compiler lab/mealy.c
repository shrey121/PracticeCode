#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *p;
	int fa[10][10],cs,init,i=0,j=0,m,n,size,op[50],k=0;
	char c=' ',str[100],ch;
	p=fopen("automata.txt","r");
	fscanf(p,"%d\n",&init);
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
	printf("\nMealy machine(Input followed by its output)\n");
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
	i=0,k=0;
	while(cs!=-1&&str[i]!='\0')
	{
        if(((str[i]-48)*2)>n)
                            cs=-1;
        else
        {
		cs=fa[cs][(str[i]-48)*2];
		op[k]=fa[cs][((str[i]-48)*2)+1];
		i++;
		k++;
        }
	}
    if(str[i]=='\0')
    {
             printf("\nThe output of mealy machine is:\n");
             for(i=0;i<k;i++)
             printf("%d",op[i]);
    }
    else if(cs==-1)
    {
                   printf("\nString not accepted\n"); 
    }
    printf("\nDo you want to enter more strings?(y/n)\n");
    scanf("%c",&ch);
}while(ch=='y');
	getch();
}
