#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#define max 15  //total no. of vertex

int graph[max][max],n;

void create()
{	int i,j;
	char ch;
	FILE *p;
	p=fopen("graph.txt","r+");
	if(!p)
	{	cout<<"\nCouldn't open file.\nExiting from program!!";
		getch();
		exit(1);
	}
	i=0;	j=0;
	while(!feof(p))
	{	ch=fgetc(p);
		graph[i][j]=(int)(ch-48);
		j++;
		ch=fgetc(p);
		if(ch=='\n')
		{	i++;
			j=0;
		}
	}
	n=i;
	cout<<"\nGraph created:\n\t";
	ch=65;
	for(i=0;i<n;i++)
	{	cout<<ch<<"\t";
		ch++;
	}
	cout<<"\n\n";
	ch=65;
	for(i=0;i<n;i++)
	{	cout<<ch<<"\t";
		ch++;
		for(j=0;j<n;j++)
		{	cout<<graph[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
}

void dfs()
{	cout<<"\nTraversing using Depth First Search:\n";
	int temp,i,j,k,top=0,s[max],tgraph[max][max];
	char ch=65;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	tgraph[i][j]=graph[i][j];
		}
	}
	j=0;
	cout<<ch<<"\t";
	for(i=0;i<n;i++)
	{	tgraph[i][j]=0;
	}	
	i=0;
	while(1)
	{	for(j=0;j<n;j++)
		{	if(tgraph[i][j]!=0)
			{	s[top]=j;
				top++;
				for(k=0;k<n;k++)
				{	tgraph[k][j]=0;
				}
			}
		}
		if(top!=0)
		{	top--;
			temp=s[top];
			ch=(char)(temp+65);
			cout<<ch<<"\t";
			i=temp;
		}
		else
		{	goto finish;
		}
	}
	finish:
}

void bfs()
{	cout<<"\nTraversing using Breadth First Search:\n";
	int temp,i,j,k,f=1,r=1,q[max],tgraph[max][max];
	char ch=65;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	tgraph[i][j]=graph[i][j];
		}
	}
	j=0;
	cout<<ch<<"\t";
	for(i=0;i<n;i++)
	{	tgraph[i][j]=0;
	}
	i=0;
	while(1)
	{	for(j=0;j<n;j++)
		{	if(tgraph[i][j]!=0)
			{	q[r]=j;
				r++;
				for(k=0;k<n;k++)
				{	tgraph[k][j]=0;
				}
			}
		}
		if(f!=r)
		{	temp=q[f];
			f++;
			ch=(char)(temp+65);
			cout<<ch<<"\t";
			i=temp;
		}
		else
		{	goto finish;
		}
	}
	finish:
}

void main()
{	clrscr();
	cout<<"Reading file and creating graph...";
	create();
	dfs();
	bfs();
	getch();
}
