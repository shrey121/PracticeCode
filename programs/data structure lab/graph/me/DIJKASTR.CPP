#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<process.h>
#define INFINITY 32000
#define MAX 15

void main()
{	clrscr();
	int graph[MAX][MAX],n,pre[MAX],pd;
	FILE *p;
	int i=0,j=0,k,s,t;
	int distance[MAX],perm[MAX];
	int current,dc;
	int smalldist,newdist;
	char ch,ch2;
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
	cout<<"\n Enter the starting node and the ending node:\t";
	cin>>ch;
	s=(int)(ch-65);
	cin>>ch;
	t=(int)(ch-65);
	for(i=0;i<n;i++)
  	{	perm[i]=0;		
  		distance[i]=INFINITY;
 	}
  	perm[s]=1;			
  	distance[s]=0;
  	current=s;
	while(current!=t)
  	{	smalldist=INFINITY;
  		dc=distance[current];
  		for(i=0;i<n;i++)
    		{	if(perm[i]==0)
    			{	newdist=dc+graph[current][i];
     				if(newdist<distance[i])
     				{	distance[i]=newdist;
      					pre[i]=current;
     				}
     				if(distance[i]<smalldist)
     				{	smalldist=distance[i];
      					k=i;
     				}
   			}
		} 
   		current=k;
   		perm[current]=1;
  	}  
  	ch=(char)(s+65);
	ch2=(char)(t+65);
	cout<<"\nThe shortest path from node "<<ch<<" to "<<ch2<<" is:\t"<<distance[t];
	getch();
}