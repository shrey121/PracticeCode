#include<iostream>
#include<fstream>
using namespace std;
#include<string.h>
int nfa[10][10][10],n,m=0,n1,t=0;
int dfa[10][10],nd,n1d,extra[10];
int initial,final[10],fc;
void read()
{
		ifstream fin;
		fin.open("kcd4.txt",ios::in);
		int i,j,k,count=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				for(k=0;k<10;k++)
					nfa[i][j][k]=-1;
				dfa[i][j]=-1;
			}
			extra[i]=-1;
		}
		i=0,j=0,k=0;
		char ch;
		fin.get(ch);
		while(ch!='\n')
		{
			if(ch!=' ')
				m++;
			fin.get(ch);
		}
		while(fin.get(ch))
		{
			if(ch==' ')
			{
				j++;
				k=0;
			}	
			else if(ch==',')
				k++;
			else if(ch=='\n')
			{
				i++;
				j=k=0;
				if(count!=m)
					n=i;
				count=0;
			}
			else if(ch=='-')
				nfa[i][j][k]=ch;
			else
				nfa[i][j][k]=ch-'0';
			count++;
		}
		n1=i+1;
}	
void print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<10;k++)
				if(nfa[i][j][k]!=-1)
				{
					if(nfa[i][j][k]!='-'&&k==0)
						cout<<nfa[i][j][k];
					else if(nfa[i][j][k]!='-'&&k!=0)
						cout<<","<<nfa[i][j][k];
					else
						cout<<"-";
				}
			cout<<" ";
		}	
		cout<<endl;
	}
	for(int i=n;i<n1;i++)
		cout<<nfa[i][0][0]<<"\n";
}
void nfa2dfa()
{
	int i,j,k,flag=-1;
	nd=n1d=0;
	initial=nfa[n][0][0];
	for(i=n+1;i<n1;i++)
		final[fc++]=nfa[i][0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(nfa[i][j][1] != -1)
			{
				
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag==0)
		{
			for(j=0;j<m;j++)
				dfa[nd][j]=nfa[i][j][0];
		}
		else
		{
			int last=nd;
			for(j=0;j<m;j++)
			{
				if(nfa[i][j][1]!=-1)
				{
					int calc=0;
					for(k=0;nfa[i][j][k]!=-1;k++)
						calc=(calc*10)+nfa[i][j][k];
					dfa[nd][j]=calc;
					last=nd;
					nd++;
					extra[nd]=calc;
				}	
				else
					dfa[last][j]=nfa[i][j][0];
			}
		}
		nd++;
	}	
	for(i=0;i<nd;i++)
		for(j=i+1;j<nd-1;j++)
			if(extra[i]==extra[j] && extra[i] != -1)
				extra[i]=-99;
	for(i=0;i<nd;i++)
	{
		if(extra[i]!=-99)
		{
		cout<<endl<<i<<"\t";
		for(j=0;j<m;j++)
			if(dfa[i][j]!='-')
				cout<<dfa[i][j]<<"\t";
			else
				cout<<"-\t";
		}
	}
}
int main()
{
	read();
	print();
	nfa2dfa();
}
