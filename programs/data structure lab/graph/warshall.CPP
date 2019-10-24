#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#define max 20	//number of vertices

int graph[max][max],n;

void main()
{	clrscr();
	FILE *p;
	int i=0,j=0,k,n;
	char ch;
	p=fopen("graph.txt","r+");
	if(!p)
	{	cout<<"Couldn't open file.\nExiting from program!!";
		getch();
		exit(1);
	}
	while(!feof(p))
	{  	ch=fgetc(p);
		graph[i][j]=(int)(ch-48);
		j++;
		ch=fgetc(p);
		if(ch=='\n')
		{ 	i++;
			j=0;
		}
	}
	i++;
	n=i;
	cout<<"\nGraph read from file:\n\t";
	ch=65;
	for(i=0;i<n;i++)
	{	cout<<ch<<"\t";
		ch++;
	}
	ch=65;
	cout<<"\n";
	for(i=0;i<n;i++)
	{       cout<<ch<<"\t";
		ch++;
		for(j=0;j<n;j++)
		{     	cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(k=0;k<n;k++)
	{	for(i=0;i<n;i++)
		{	for(j=0;j<n;j++)
			{       if(graph[i][j]!=0&&graph[i][k]!=0&&graph[k][j]!=0)
				{	if(graph[i][j]>(graph[i][k]+graph[k][j]))
					{  	graph[i][j]=(graph[i][k]+graph[k][j]);
					}
				}
			}
		}
	}
	cout<<"\nShortest path between vertices:\n\t";
	ch=65;
	for(i=0;i<n;i++)
	{	cout<<ch<<"\t";
		ch++;
	}
	ch=65;
	cout<<"\n";
	for(i=0;i<n;i++)
	{       cout<<ch<<"\t";
		ch++;
		for(j=0;j<n;j++)
		{     	cout<<graph[i][j]<<"\t";
		}
		cout<<"\n";
	}
	getch();
}
