#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 30

struct node
{	int data;
	node *left;
	node *right;
} *root=NULL, *temp, *t;

node *s[max];
int top;

void preorder(void)
{       cout<<"\nTree (Preorder traversal)\n";
	top=0;
	s[top]=NULL;
	temp=root;
	while(temp!=NULL)
	{	cout<<temp->data<<"  ";
		if(temp->right!=NULL)
		{	top++;
			s[top]=temp->right;
		}
		if(temp->left!=NULL)
		{	temp=temp->left;
		}
		else
		{	temp=s[top];
			top--;
		}
	}
}

void inorder(void)
{       cout<<"\nTree (Inorder traversal)\n";
	top=0;
	s[top]=NULL;
	temp=root;
	again:
	while(temp!=NULL)
	{       top++;
		s[top]=temp;
		temp=temp->left;
	}
	temp=s[top];
	top--;
	while(temp!=NULL)
	{    	cout<<temp->data<<"  ";
		if(temp->right!=NULL)
		{	temp=temp->right;
			goto again;
		}
		temp=s[top];
		top--;
	}
}

void postorder(void)
{	cout<<"Tree (Postordertraversal)\n";
	struct tnode
	{       char status;
		node *p;
	} *ptr, *myptr;
	tnode *s[max];
	top=0;
	s[top]=NULL;
	temp=root;
	myptr=NULL;
	again:
	while(temp!=NULL)
	{	ptr=new tnode;
		ptr->p=temp;
		ptr->status='p';
		top++;
		s[top]=ptr;
		if(temp->right!=NULL)
		{	ptr=new tnode;
			ptr->p=temp->right;
			ptr->status='n';
			top++;
			s[top]=ptr;
		}
		temp=temp->left;
	}
	myptr=s[top];
	top--;
	temp=myptr->p;
	while(myptr->status=='p')
	{	cout<<temp->data<<"  ";
		myptr=s[top];
		top--;
		temp=myptr->p;
	}
	if(myptr->status=='n')
	{	myptr->status='p';
		temp=myptr->p;
		goto again;
	}
}

void insert()
{	temp=new node;
	cout<<"\nEnter the data:\t";
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{	root=temp;
		goto fin;
	}
	t=root;
	while(1)
	{       if((temp->data)<=(t->data))
		{	if((t->left)==NULL)
			{    	t->left=temp;
				goto fin;
			}
			else
			{	t=t->left;
			}
		}
		else if((temp->data)>(t->data))
		{	if((t->right)==NULL)
			{    	t->right=temp;
				goto fin;
			}
			else
			{	t=t->right;
			}
		}
	}
	fin:
}

void main()
{       char ch;
	clrscr();
	while(1)
	{       cout<<"\n1)Insert\n2)Preorder\n3)Inorder\n4)Postorder\n5)Exit";
		ch=getch();
		cout<<ch;
		if(ch=='1')
		{	insert();
		}
		else if(ch=='2')
		{       preorder();
		}
		else if(ch=='3')
		{	inorder();
		}
		else if(ch=='4')
		{	postorder();
		}
		else if(ch=='5')
		{	exit(1);
		}
		else
		{	cout<<"\nWrong choise!!\n\n";
		}
	}
}