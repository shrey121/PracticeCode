#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#define max 15
void main()
{	clrscr();
	int a,b,u,v,n,i,j,ne=0;
	int visited[max],min,mincost=0,graph[max][max];
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
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(graph[i][j]==0)
				graph[i][j]=999;
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[0]=1;
 	cout<<"Edges of minimm spanning tree are:\n";
 	while(ne<n-1)
 	{	for(i=0,min=999;i<n;i++)
   			for(j=0;j<n;j++)
    				if(graph[i][j]<min)
     					if(visited[i]!=0)
     					{	min=graph[i][j];
      						a=u=i;
      						b=v=j;
     					}
  		if(visited[u]==0 || visited[v]==0)
  		{	printf("\n Edge %d:(%c %c) graph:%d",ne,(a+65),(b+65),min);
			ne++;
	   		mincost+=min;
   			visited[b]=1;
  		}
  		graph[a][b]=graph[b][a]=999;
	}
 	printf("\n Minimun cost=%d",mincost);
 	getch();
}