#include<iostream.h>
#include<conio.h>
#include<process.h>

char tree[127];
int nc=0,te=0;

void put(void)
{   char item;
	int p,i;
	if(nc==126)
	{   cout<<"\nTree is full";
		goto st;
	}
	cout<<"\nEnter the element";
	item=getch();
	if(nc==0)
	{	tree[nc]=item;
		nc++;
		if(item!=' ')
		{	te++;
		}
	}
	else
	{   up:
		p=(nc-1)/2;
		if(tree[p]==' ')
		{   if(nc==1)
			{	cout<<"\nRoot node is empty. Can't form tree.";
				goto st;
			}
			else
			{   tree[nc]=' ';
				nc++;
				tree[nc]=' ';
				nc++;
				if(nc==126)
				{   cout<<"\nTree is full";
					goto st;
				}
				goto up;
			}
		}
		tree[nc]=item;
		nc++;
		if(item!=' ')
		{	te++;
		}
	}
	st:
}

void info(void)
{   char item;
	int i,pos=-5,t;
	cout<<"\nEnter the element";
	item=getch();
	for(i=0;i<=nc;i++)
	{	if(tree[i]==item)
		{ 	pos=i;
		}
	}
	if(pos==-5)
	{	cout<<"\nElement not found!!";
	}
	else
	{ 	t=(pos-1)/2;
		if(pos==0)
		{	cout<<"\nNo parent. It's a root node.";
		}
		else
		{	cout<<"\nParent:\t"<<tree[t];
		}

		t=(2*pos)+1;
		if((tree[t]==' ') || (t>=nc))
		{	cout<<"\nNo left child.";
		}
		else
		{	cout<<"\nLeft child:\t"<<tree[t];
		}

		t=(2*pos)+2;
		if((tree[t]==' ') || (t>=nc))
		{	cout<<"\nNo right child.";
		}
		else
		{	cout<<"\nRight child:\t"<<tree[t];
		}
	}
}

void dis(void)
{   int i;
	cout<<"\n\n";
	for(i=0;i<=nc;i++)
	{   if((i==1) || (i==3) || (i==7) || (i==15) || (i==31) || (i==64))
		{	cout<<endl;
		}
		cout<<tree[i];
	}
}

void pre(void)
{   int t,e,lc,rc,p,i;
	char ptree[127];
	for(i=0;i<nc;i++)
	{	ptree[i]=tree[i];
	}
	cout<<"\nPreorder:\t";
	e=te;
	cout<<ptree[0];
	ptree[0]='^';
	e--;
	t=0;
	while(e>0)
	{   lc=(2*t)+1;
		if((lc<nc)&&(ptree[lc]!=' ')&&(ptree[lc]!='^'))
		{	cout<<ptree[lc];
			ptree[lc]='^';
			e--;
			t=lc;
			goto a1;
		}

		rc=(2*t)+2;
		if((rc<nc)&&(ptree[rc]!=' ')&&(ptree[rc]!='^'))
		{	cout<<ptree[rc];
			ptree[rc]='^';
			e--;
			t=rc;
			goto a1;
		}

		p=(t-1)/2;
		t=p;
		a1:
	}
}

void main()
{	char ch;
	clrscr();

	while(1)
	{   clrscr();
		cout<<"\n1)Insert Node\n2)Information of node\n3)Display tree\n4)Preorder\n5)Exit\n";
		ch=getch();
		if(ch=='1')
		{	put();
			dis();
			getch();
		}
		else if (ch=='2')
		{  	info();
			dis();
			getch();
		}
		else if (ch=='3')
		{	dis();
			getch();
		}
		else if (ch=='4')
		{	pre();
			getch();
		}
		else if (ch=='5')
		{	exit(1);
		}
		else
		{   cout<<"\nWrong choise.\n";
			getch();
		}
	}
}