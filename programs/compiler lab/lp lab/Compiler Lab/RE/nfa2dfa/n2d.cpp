#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

char a[20][10][10];
int n;
void read()
{
    ifstream fin;
    fin.open("nfa.txt",ios::in);
    char ch,temp[2];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                a[i][j][k]='\0';
    int j;
    n=j=0;
    while(fin.get(ch))
    {
        temp[0]=ch;
        temp[1]='\0';
        if(ch=='\n')
        {
            n++;
            j=0;
        }
        else if(ch==',')
            continue;
        else if(ch==' ')
            j++;
        else if(ch!='-')
            strcat(a[n][j],temp);
    }
    n++;
}
void add(int i,int j)
{
    cout<<endl<<i<<" "<<j<<"\t";
    for(int k=0;a[i][j][k]!='\0';k++)
    {
        int l=a[i][j][k]-'0';
        strcat(a[n][j],a[l][j]);
        cout<<a[l][j];
    }
    char temp[2];
    temp[0]=n-'0';
    temp[1]='\0';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(strcmp(a[i][j],a[n][j])==0)
                strcpy(a[i][j],temp);
    }
    strcpy(a[n][j],temp);
    n++;
}
void n2d()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j][1]!='\0')
                add(i,j);

    }
}

int main()
{
    read();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    n2d();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    getchar();
}
