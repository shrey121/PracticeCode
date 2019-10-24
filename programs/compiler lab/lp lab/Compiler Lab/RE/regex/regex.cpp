#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>

char str[100],r[10][10];
int ri[10],n,m[10],mn;
void read()
{
    cout<<"Enter expression:";
    cin.getline(str,10);
    n=mn=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(')
            m[mn++]=n;
        else if(str[i]=='*')
    }
}
