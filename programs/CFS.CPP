#include<iostream.h>
#include<conio.h>
#include<process.h>
#define smax 9		//maximum number of stages in reservation table
#define tmax 15        	//maximum time in reservation table
#define maxstate 20	//maximum number of states generated in graph

int cv[tmax-1],q;

void CalcCollVec()
{	int rt[smax][tmax],i,j,p,t1,t2;
	char ch;
	cout<<"\nGenerating Reservation table.";
	cout<<"\nEnter number of stages in reservation table:\t";
	cin>>p;
	if(p>smax)
	{	cout<<"Error: Increase the value of 'smax' variable in the program.";
		getch();
		exit(1);
	}
	cout<<"Enter number of units of time in reservation table:\t";
	cin>>q;
	if(q>tmax)
	{	cout<<"Error: Increase the value of 'tmax' variable in the program.";
		getch();
		exit(1);
	}
	for(i=0;i<p;i++)
	{	for(j=0;j<q;j++)
		{	rt[i][j]=0;
		}
	}
	for(i=0;i<q-1;i++)
	{	cv[i]=0;
	}
	for(j=0;j<q;j++)
	{       rep:
		cout<<"Enter the stage number which is executing in "<<j+1<<" second:\t";
		cin>>i;
		i--;
		if(i>=p)
		{	cout<<"You entered wrong stage number.\n";
			ch='y';
		}
		else
		{	rt[i][j]=1;
			cout<<"Are there any more stages executing in "<<j+1<<" second:(y/n)\t";
			cin>>ch;
		}
		if(ch=='y'||ch=='Y')
		{	goto rep;
		}
	}
	for(i=0;i<p;i++)
	{  	t1=t2=-1;
		for(j=0;j<q;j++)
		{	if(rt[i][j]==1)
			{       t1=t2=j;
				goto d1;
			}
		}
		d1:
		for(j=t1+1;j<q;j++)
		{     	if(rt[i][j]==1)
			{	t2=j;
				cv[t2-t1-1]=1;
			}
		}
		for(j=t1+1;j<q;j++)
		{	if(rt[i][j]==1)
			{	t1=j;
				goto d1;
			}
		}
	}
	for(i=0,j=q-2;i<q/2;i++,j--)
	{     	t1=cv[i];
		cv[i]=cv[j];
		cv[j]=t1;
	}
	cout<<"\nCollision Vector:\t";
	for(i=0;i<q-1;i++)
	{	cout<<cv[i];
	}
}

void CalcMAL()
{       int state[maxstate][tmax-1],graph[maxstate][maxstate],path[2][maxstate],orwith[tmax-1],result[tmax-1],gc[8],tempgc[15][8],temp[8],a,b,c,n,tn,ti,i,j,f,tf,m,p,z,y;
	float mal,l;
	for(i=0;i<q-1;i++)
	{	state[0][i]=cv[i];
	}
	for(i=0;i<maxstate;i++)
	{	for(j=0;j<maxstate;j++)
		{	graph[i][j]=-1;
		}
	}
	n=1;
	for(tn=0;tn<n;tn++)
	{       for(ti=q-2;ti>-1;ti--)
		{	if(state[tn][ti]==0)
			{       if(ti==0)
				{	for(j=q-2;j>-1;j--)
					{	orwith[j]=0;
					}
				}
				else
				{	i=ti-1;
					for(j=q-2;i>-1;i--,j--)
					{   	orwith[j]=state[tn][i];
					}
					for(;j>-1;j--)
					{   	orwith[j]=0;
					}
				}
				for(i=q-2;i>-1;i--)
				{	if(state[0][i]==1)
					{	result[i]=1;
					}
					else
					{	if(orwith[i]==1)
						{	result[i]=1;
						}
						else
						{	result[i]=0;
						}
					}
				}
				f=0;
				for(i=0;i<n;i++)
				{       tf=1;
					for(j=q-2;j>-1&&tf==1;j--)
					{  	if(state[i][j]!=result[j])
						{	tf=0;
						}
					}
					if(tf==1)
					{	f=1;
					}
				}
				if(f==0)
				{	for(j=q-2;j>-1;j--)
					{	state[n][j]=result[j];
					}
					n++;
					if(n==maxstate)
					{	cout<<"\nError: Increase the value of 'maxstate' variable in the program.";
						getch();
						exit(1);
					}
				}
				a=tn;
				for(i=0;i<n;i++)
				{       tf=1;
					for(j=q-2;j>-1&&tf==1;j--)
					{  	if(state[i][j]!=result[j])
						{	tf=0;
						}
					}
					if(tf==1)
					{	b=i;
					}
				}
				c=q-(ti+1);
				if(graph[a][b]==-1)
				{	graph[a][b]=c;
				}
				else
				{       if(c<graph[a][b])
					{	graph[a][b]=c;
					}
				}

			}
		}
		a=tn;
		b=0;
		if(graph[a][b]==-1)
		{	graph[a][b]=q;
		}
	}
	cout<<"\n\nGraph Created:\t(-1 means there is no path and path with minimum cost is kept to make this multigraph a simple graph)\n\n\t";
	for(i=0;i<n;i++)
	{	for(j=0;j<q-1;j++)
		{	cout<<state[i][j];
		}
		cout<<"\t";
	}
	for(i=0;i<n;i++)
	{       cout<<endl;
		for(j=0;j<q-1;j++)
		{	cout<<state[i][j];
		}
		cout<<"\t";
		for(j=0;j<n;j++)
		{	cout<<graph[i][j]<<"\t";
		}
	}
	for(i=0;i<n;i++)
	{       m=32000;
		for(j=0;j<n;j++)
		{ 	if(graph[i][j]<m&&graph[i][j]>-1)
			{	m=graph[i][j];
			}
		}
		for(j=0;j<n;j++)
		{	if(graph[i][j]!=m)
			{   	graph[i][j]=-1;
			}
		}
	}
	for(i=0;i<15;i++)
	{	for(j=0;j<8;j++)
		{	tempgc[i][j]=-1;
		}
	}
	for(tn=0,mal=32000,p=0;tn<n;tn++)
	{       ti=0;
		for(i=0;i<2;i++)
		{	for(j=0;j<maxstate;j++)
			{	path[i][j]=-1;
			}
		}
		a=tn;
		up:
		path[0][ti]=a;
		for(j=0;j<n;j++)
		{	if(graph[a][j]!=-1)
			{	b=j;
			}
		}
		path[1][ti]=graph[a][b];
		ti++;
		f=0;
		for(j=0;j<ti;j++)
		{   	if(path[0][j]==b)
			{	f=1;
				c=j;
			}
		}
		if(f==0)
		{       a=b;
			goto up;
		}
		else
		{       if(c==0)
			{       tf=0;
				if(p==0)
				{	goto d3;
				}
				for(i=0;i<p;i++)
				{	for(j=0;j<8;j++)
					{	temp[j]=tempgc[i][j];
					}
					for(z=0;z<ti;z++)
					{	for(y=0;y<8;y++)
						{	if(path[1][z]==temp[y])
							{	temp[y]=-1;
							}
						}
					}
					for(j=0;j<8;j++)
					{	if(temp[j]!=-1)
						{	z=-2;
						}
					}
					if(z>0)
					{	tf=1;
					}
				}
				if(tf==0)
				{       d3:
					for(i=0,l=0;i<ti;i++)
					{	tempgc[p][i]=path[1][i];
						l=l+path[1][i];
					}
					p++;
					l=l/ti;
					if(l<mal)
					{	mal=l;
						for(i=0;i<8;i++)
						{	gc[i]=-1;
						}
						for(i=0;i<ti;i++)
						{	gc[i]=path[1][i];
						}
					}
				}
			}
		}
	}
	cout<<"\n\nGreedy Cycle:";
	for(i=0;i<p;i++)
	{       cout<<"\n"<<i+1<<")\t";
		for(j=0;tempgc[i][j]!=-1;j++)
		{   	cout<<tempgc[i][j]<<"\t";
		}
	}
	cout<<"\n\nMinimum Average Latency:\t";
	for(i=0;gc[i]!=-1;i++)
	{	cout<<gc[i]<<"\t";
	}
}

main()
{	clrscr();
	cout<<"\nThis program calculates the minimum average latency from reservation table for pipeline.";
	CalcCollVec();
	CalcMAL();
	getch();
}