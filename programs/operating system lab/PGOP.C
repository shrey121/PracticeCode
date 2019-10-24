#include<conio.h>
#include<stdio.h>
int count=0,i=0;
char pg[50];
struct list
{
	int info;
	struct list *link;
}*ptr,*start=NULL,*node,*dptr;
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
void del(char item,char item1)
{
	dptr=start;
	while(dptr!=NULL)
	{
		if(dptr->info==item)
		break;
		else
		dptr=dptr->link;
	}
	dptr->info=item1;
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
	//getch();
}
void op(int item)
{
	int k=0,temp=0;
	char ch;
	dptr=start;
	while(dptr!=NULL)
	{
		  ch=dptr->info;
		  for(k=item;k<i;k++)
		  {
			if(ch==pg[k])
			break;
		  }
		  if(k==i)
		  {
			for(k=0;k<i;k++)
			{
				if(ch==pg[k])
				{
					temp=k;
					break;
				}
			}
			break;
		  }
		  if(k>temp)
		  {
			temp=k;
		  }
		  dptr=dptr->link;
	}
	del(pg[temp],pg[item]);

}
void main()
{
	FILE *p;
	char ch;
	int k=0,ret=0,page,fault=0;
	clrscr();
	p=fopen("page.txt","r");
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
		}
		else
		{
			ret=traverse(pg[k]);
			if(ret==1)
			{
				op(k);
				printf("\t\t %c",pg[k]);
				display();
				fault++;
			}
		}
	}
	printf("\n No. of page faults are %d",fault);
	getch();
}

