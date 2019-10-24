#include<iostream>
#include<fstream>
using namespace std;
#include<string.h>

char dfa[10][10],final[10];
int n,m,q,fc;

void read()
{
    int i,j;
    char ch;
    ifstream fin;
    fin.open("kcd1.txt",ios::in);
    n=m=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            dfa[i][j]='\0';
    do
    {
        fin.get(ch);
        m++;
    }while(ch!='\n');
    i=j=0;
    while(fin.get(ch))
    {
        if(ch=='\n')
        {
            i++;
            j=0;
        }
        else if(ch==',')
        {
            n=i;
            q=dfa[i][0]-'0';
            fc=0;
            while(fin.get(ch))
            {
                final[fc++]=ch;
            }
        }
        else
            dfa[i][j++]=ch;
    }
}

void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<endl;
        for(j=0;j<m;j++)
        {
            cout<<"\t"<<dfa[i][j];
        }
    }
}

int dfacheck(char str[],int p,int q)
{
    if(str[p]=='\0')
    {
        for(int i=0;i<fc;i++)
            if(final[i]==q+'0')
                return 1;
        return 0;
    }
    if(dfa[q][str[p]-'a']=='\0')
        return 0;
    else
        return dfacheck(str,p+1,dfa[q][str[p]-'a']-'0');
}

int main()
{
	read();
	print();
	char str[100];
	cout<<"\nEnter a string:";
	cin>>str;
	int	flag=dfacheck(str,0,q);
	if(flag==1)
        cout<<"Accepted...";
    else
        cout<<"Not Accepted...";
	return 0;
}
