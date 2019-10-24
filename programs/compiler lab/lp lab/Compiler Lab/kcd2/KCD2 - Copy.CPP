#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include<stdio.h>
char regex[100],n=0;
void read()
{
	ifstream fin;
	fin.open("kcd2.txt",ios::in);
	char ch;
	regex[n++]='(';
	while(fin.get(ch))
		regex[n++]=ch;
    regex[n++]=')';
    regex[n++]='\0';
}
int check(char str[],int p,int i,int l,int n)
{
    cout<<endl<<i<<" "<<l<<" "<<n;
    if(str[p]==regex[i])
    {

    }
    else
    else
        return 0;

}
int main()
{
    char str[100];
	read();
	cout<<regex<<"\n\nEnter a string:";
	cin>>str;
    int i,j,l,n;
    for(j=0;j<n;j++)
    {
        if(regex[j]>='a' && regex[j]<='z')
        {
            i=j;
            l=i-1;
            int count=0;
            for(j=i;j<n;j++)
            {
                if(regex[j]=='(')
                    count++;
                else if(regex[j]==')' && count!=0 )
                    count--;
                else if(regex[j]==')' && count==0)
                    n=j;
            }
            break;
        }
    }
    int flag=check(str,0,i,l,n);
	if(flag==1)
        cout<<"Accepted...";
    else
        cout<<"Not Accepted...";
	return 0;
}
