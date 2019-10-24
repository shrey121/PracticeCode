#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node
{	int data;
	node *left;
	node *right;
	node *next;
} *start=NULL, *temp, *t, *tn, *m1, *m2;

void tree(void)
{      	while(1)
	{   	temp=start;
		m1=start;
		while(temp->next!=NULL)
		{	if((m1->data)>(temp->data))
			{	m1=temp;
			}
			temp=temp->next;
		}

		temp=start;
		if(m1==start)
		{	start=start->next;
			m1->next=NULL;
		}
		else
		{       while(temp->next!=m1)
			{	temp=temp->next;
			}
			temp->next=m1->next;
			m1->next=NULL;
		}

		temp=start;
		m2=start;
		while(temp->next!=NULL)
		{	if((m2->data)>(temp->data))
			{       m2=temp;
			}
			temp=temp->next;
		}

		temp=start;
		if(m2==start)
		{	start=start->next;
			m2->next=NULL;
		}
		else
		{       while(temp->next!=m2)
			{	temp=temp->next;
			}
			temp->next=m2->next;
			m2->next=NULL;
		}

		temp=new node;
		temp->data=(m1->data)+(m2->data);
		temp->left=m1;
		temp->right=m2;
		if(start->data<0)
		{	start=temp;
			goto end;
		}
		else
		{	t=start;
			tn=t->next;
			while((tn->data)>=0)
			{	t=t->next;
				tn=tn->next;
			}
			temp->next=t->next;
			t->next=temp;
		}
	}
	end:
}

void display(node *ptr)
{	if(ptr!=NULL)
	{       cout<<ptr->data<<"  ";
		display(ptr->left);
		display(ptr->right);
	}
}

void main()
{	clrscr();
	int i;
	cout<<"Enter a number:\t";
	temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->next=NULL;
	cin>>temp->data;
	start=temp;
	while(1)
	{	cout<<"Enter a number. (Enter a negative number to stop):\t";
		cin>>i;
		temp=new node;
		temp->left=NULL;
		temp->right=NULL;
		temp->next=NULL;
		temp->data=i;
		t=start;
		while(t->next!=NULL)
		{	t=t->next;
		}
		t->next=temp;
		if(i<0)
			goto fin;
	}
	fin:
	cout<<"\nNumbers entered by you are:\n";
	t=start;
	while(t->next!=NULL)
	{	cout<<t->data<<"  ";
		t=t->next;
	}
	tree();
	cout<<"\nHuffman tree (Preorder traversal):\n";
	display(start);
	getch();
}