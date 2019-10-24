#include<conio.h>
#include<stdio.h>
int count=0;
struct list
{
	int info;
	struct list *link;
}*ptr,*start=NULL,*node,*dptr,*dptr1;
void insert(char item)
{
	node=(struct list*)malloc(sizeof(struct list));
	node->info=item;
	if(start==NULL)
	{
		node->link=start;
		start=node;
		ptr=start;
	}
	else
	{
		ptr->link=node;
		node->link=NULL;
		ptr=node;
	}
}
int traverse(int item)
{
	dptr=start;
	if(start==NULL)
	return 1;
	while(dptr!=NULL)
	{
		if(dptr->info==item)
		return 0;
		dptr=dptr->link;
	}
	return 1;
}
void del()
{
	start=start->link;
}
void del1(char item)
{
	dptr=start;
	dptr1=NULL;
	while(dptr!=NULL)
	{
		if(dptr->info==item)
		break;
		dptr1=dptr;
		dptr=dptr->link;
	}
	if(dptr1==NULL)
	start=start->link;
	else
	dptr1->link=dptr->link;
}
void display()
{
	dptr=start;
	printf("\nPage frames:  ");
	while(dptr!=NULL)
	{
		printf("%c  ",dptr->info);
		dptr=dptr->link;
	}
	getch();
}
void main()
{
	FILE *p;
	char pg[50],ch;
	int i=0,k=0,ret=0,page,fault=0;
	clrscr();
	p=fopen("page.txt","r");
	printf("Content read from file:\n");
	do
	{
		ch=fgetc(p);
		putch(ch);
		if(ch>='0'&&ch<='9')
		{
			pg[i]=ch;
			i++;
		}
	}while(ch!=EOF);
	printf("\nEnter the size of page:\t");
	scanf("%d",&page);
	for(k=0;k<i;k++)
	{
		if(count<page)
		{
			ret=traverse(pg[k]);
			if(ret==1)
			{
				insert(pg[k]);
				display();
				fault++;
				count++;
			}
			else
			{
				del1(pg[k]);
				insert(pg[k]);
			}
		}
		else
		{
			ret=traverse(pg[k]);
			if(ret==1)
			{
				del();
				insert(pg[k]);
				display();
				fault++;
			}
			else
			{
				del1(pg[k]);
				insert(pg[k]);
			}
		}
	}
	printf("\n No. of page faults are %d",fault);
	getch();
}

