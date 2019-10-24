#include<iostream>
#include<fstream>
using namespace std;
void check(char table[][10],int);
void read()
{
	ifstream fin;
	char table[10][10],ch;
	int count=0,j=0;
	fin.open("regularexp.txt",ios::in);
	cout<<"\nRegular expression is: ";
	while(fin.get(ch))
	{
		cout<<ch;
		if(ch=='+' || ch==')')
		{
			table[count][j]='\0';
			count++;
			j=0;
		}
		else
		if(ch!='(' && ch !=')' && ch!=' ' && ch!='*')
		{
			table[count][j++]=ch;
		}
	}
	int i;
	/*for(i=0;i<count;i++)
	{
		cout<<"\n";
		for(j=0;table[i][j]!='\0';j++)
		{
			cout<<table[i][j];
		}
	}*/
	check(table,count);
}

void check(char table[][10],int count)
{
	char str[100];
	cout<<"\nEnter the string: ";
	gets(str);
	int i=0,j=0,pre,l=0,flag=0;
	while(str[i]!='\0')
	{
		pre=i;
		for(j=0;j<count;j++)
		{
			if(str[i]==table[j][0])
			{
				l=0;
				while(1)
				{
					if(table[j][l]=='\0')
						break;
					if(table[j][l]!=str[i]||(str[i]=='\0'))
					{
						flag=1;
						break;
					}
					else
					{
						l++;
						i++;
					}
				}
			}
			
			if(flag==1)
				break;
		}
		if(j==count && pre==i)
			flag=1;
		if(flag==1)
			break;
	}
	if(flag==1)
		cout<<"\nNot accepted";
	else
		cout<<"\nAccepted";
}

int main()
{
	read();
}
