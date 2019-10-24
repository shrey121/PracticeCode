#include<iostream>
#include<fstream>
using namespace std;
#include<string.h>

char nfa[10][10][10],final[10];
int n,m,q,fc,count=0;

void read()
{
    int i,j,k;
    char ch;
    ifstream fin;
    fin.open("kcd3 - new.txt",ios::in);
    n=m=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
                nfa[i][j][k]='\0';
    do
    {
        fin.get(ch);
        m++;
    }while(ch!='\n');
    i=j=k=0;
    while(fin.get(ch))
    {
        if(ch=='\n')
        {
            i++;
            j=k=0;
        }
        else if(ch==',')
        {
           k++;
        }
        else if(ch==' ')
        {
            j++;
            k=0;
        }
        else if(ch=='#')
        {
            n=i;
            fin.get(ch);
            q=ch-'0';
            fin.get(ch);
            fc=0;
            while(fin.get(ch))
            {
                final[fc++]=ch;
            }
        }
        else
            nfa[i][j][k]=ch;
    }
}

void print()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        cout<<endl;
        for(j=0;j<m;j++)
        {
            for(k=0;nfa[i][j][k]!='\0';k++)
            {
                if(k==0)
                    cout<<"\t"<<nfa[i][j][k];
                else
                    cout<<","<<nfa[i][j][k];
            }
        }
    }
}

int nfacheck(char str[],int p,int i,int q)
{
    if(str[p]=='\0')
    {
        for(int j=0;j<fc;j++)
            if(final[j]==i+'0')
                return 1;
        count++;
        if(nfa[q][str[p-1]-'a'][count]!='\0')
            return nfacheck(str,p,nfa[q][str[p-1]-'a'][count]-'0',q);
        return 0;
    }
    if(nfa[i][str[p]-'a'][count]=='\0')
    {
        if(nfa[q][str[p-1]-'a'][count+1]!='\0')
        {
            count++;
            return nfacheck(str,p,nfa[q][str[p-1]-'a'][count],q);
        }
        else
            return 0;
    }
    else
    {
        count=0;
        return nfacheck(str,p+1,nfa[i][str[p]-'a'][count]-'0',i);
    }
}

int main()
{
	read();
	print();
	char str[100];
	cout<<"\nEnter a string:";
	cin>>str;
	int	flag=nfacheck(str,0,q,q);
    if(flag==1)
        cout<<"Accepted...";
    else
        cout<<"Not Accepted...";
	return 0;
}
