#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

int stack[20],top=-1,llen=0,loop[20],cfg[20][20],size=0;;

void read()
{
    ifstream fin;
    fin.open("nlooptxt.txt",ios::in);
    char ch;
    int i,j;
    size=-1;
    while(fin.get(ch))
    {
        if(ch=='\n')
        {
            if(size==-1)
                size=j;
            i++;
            j=0;
        }
        else
        if(ch!=' ')
        {
            cfg[i][j++]=ch-'0';
        }
    }cout<<size<<"\n";
}

void push(int m)
{
    stack[++top]=m;
}

int pop()
{
    int t=stack[top--];
    return t;
}

void insert(int m)
{
    int i,flag=0;
    for(i=0;i<llen;i++)
    {
        if(m==loop[i])
        {
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        loop[llen++]=m;
        push(m);
    }
}

void nloop(int n,int d)
{
    
    int i,j;
    top=-1;
    llen=0;
    loop[llen++]=d;
    insert(n);
    while(top!=-1)
    {
        int item=pop();
        //cout<<item<<"\t";
        for(j=0;j<size;j++)
        {
            if(cfg[j][item]==1 && j>d)
            {
                //cout<<j<<"\t";
                insert(j);
            }
        }
    }
    cout<<"\nNatural loop for "<<n+1<<" - "<<d+1<<": ";
    for(j=0;j<llen;j++)
    {
        cout<<loop[j]+1<<"\t";
    }
}

void naloop()
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(cfg[i][j]==1 && i>j)
                nloop(i,j);
        }
    }
}

int main()
{
    read();
    naloop();
}