/*NFA
Input:
1 1,2
2 0,2
- -
#0
2
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int i = 0, a[10][10][10], n, m, q0, f[10], fn, v[10][10][10],status=0;
char str[100];
void read()
{
	for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
                    a[i][j][k]=v[i][j][k]=0;
	ifstream fin;
	fin.open("nfa.txt", ios::in);
	char ch;
	n=m=0;
	int value=1;
	while(fin.get(ch))
	{
	    int i=ch-'0';
	    if(ch==',')
            continue;
        else if(ch=='\n')
        {
            n++;
            m=0;
            value=1;
        }
        else if(ch=='#')
            break;
        else if(ch==' ')
        {
            value++;
            m++;
        }
        else if(ch!='-')
        {
            for(int m=0;m<10;m++)
                if(a[n][i][m]==0)
                {
                    a[n][i][m]=value;
                    break;
                }
        }
	}
	fin.get(ch);
	q0=ch-'0';
	fn=0;
	fin.get(ch);
    while(fin.get(ch))
        f[fn++]=ch-'0';
}

void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"(";
            for(int k=0;k<10;k++)
                if(a[i][j][k]!=0)
                    cout<<a[i][j][k]<<" ";
            cout<<")\t";
        }
        cout<<endl;
    }
    cout<<"q="<<q0;
    cout<<"\nf=";
    for(int i=0;i<fn;i++)
        cout<<" "<<f[i];
}

int dfs(int q,int pos)
{
	if(pos==strlen(str))
    {
        for(int i=0;i<fn;i++)
            if(q==f[i])
                return 1;
        return 0;
    }
    int s;
	s=str[pos]-'a'+1;
    i=q;
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(a[i][j][k]==s)
                {
                    status=dfs(j,pos+1);
                    if(status==1)
                        return 1;
                }
}
int main()
{
	read();
	print();
    cout<<"Enter string :";
	cin.getline(str,100);
	status=dfs(q0,0);
	if(status==1)
        cout<<"found";
    else
        cout<<"not found";
	getchar();
	return 0;
}


