#include<iostream>
#include<fstream>
using namespace std;
#include<string.h>
int nfa[10][10][10],n,m=0,n1,t=0;
void read()
{
		ifstream fin;
		fin.open("kcd3.txt",ios::in);
		int i,j,k,count=0;
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				for(k=0;k<10;k++)
					nfa[i][j][k]=-1;
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

int ndfa(char str[],int p,int i,int l)
{
	int flag;
	if(str[p]==NULL)
	{
		do
		{
			t=0;
			for(int temp=n+1;temp<n1;temp++)
				if(nfa[temp][0][0]==i)
					return 1;
			t++;
			i=nfa[l][str[p-1]-'a'][t];
		}while(i!=-1);
		return 0;
	}	
	if(nfa[i][str[p]-'a'][t]!=-1)
	{
		l=i;
		t=0;
		cout<<"->"<<nfa[i][str[p]-'a'][t];
		flag=ndfa(str,p+1,nfa[i][str[p]-'a'][t],l);
	}
	else
	{
		t++;
		flag=ndfa(str,p,nfa[l][str[p-1]-'a'][t],l);
	}
}

void check()
{
	char str[20];
	cout<<"Enter a string:";
	cin>>str;
	cout<<"State : "<<nfa[n][0][0];
	int flag=ndfa(str,0,nfa[n][0][0],nfa[n][0][0]);	
	if(flag==1)
		cout<<"\nAccepted";
	else
		cout<<"\nNot Accepted";
}
int main()
{
	read();
	print();
	check();
}
