#include<stdio.h>
#include<conio.h>
int stack[10],top=-1,loop[10],precount=0,pre[10],fgraph[10][10],domtree[10][10];
int i,j,k,lcount=0;
void push(int);
int pop();
void findpredecessor(int);
void insert(int);
int checkdominator(int,int);
void main()
{
int n,d,m,res;
FILE *fp1, *fp2;
clrscr();
fp1=fopen("fgraph.txt","r");
	if(fp1==NULL)
	{printf("\nCannot open file");
	exit(1);
	}
fp2=fopen("dtree.txt","r");

	if(fp2==NULL)
	{printf("\nCannot open file");
	exit(1);
	}

while(!feof(fp1))
{
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		fscanf(fp1,"%d",&fgraph[i][j]);
	}
}

while(!feof(fp2))
{

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		fscanf(fp2,"%d",&domtree[i][j]);
	}

}
/*printf("\n Displaying data read from files!!\n\n") ;
printf("\n\n2-D fgraph is:")  ;

for(i=0;i<10;i++)
{
	for(j=0;j<10;j++)
	printf("%d ",fgraph[i][j]);
	printf("\n");
}


printf("\n\n2-D dominating tree is:")  ;

for(i=0;i<10;i++)
{
	for(j=0;j<10;j++)
	printf("%d ",domtree[i][j]);
	printf("\n");
}

  */
printf("\nFor back edge, n-->d,");
printf("\n Enter the value of n: ");
scanf("%d",&n);
printf("\n Enter the value of d: ");
scanf("%d",&d);


loop[lcount++]=d;
insert(n);

while(top>=0)
{
m=pop();
//printf("\n element popped is %d",m);
findpredecessor(m);
	for(i=0;i<precount;i++)
	{
	insert(pre[i]) ;
	}



}


printf("\n elements in loop are:") ;

for(i=0;i<lcount;i++)
printf(" %d ",loop[i]) ;

	for(k=1;k<lcount;k++)

	{ printf("\n Checking for loop element %d",loop[k]);

	res=checkdominator(loop[k],d);
	 printf("\n res come out %d",res);
		if(res==0)
		{
		break;  }


	 }

if(res==1)
{
printf("\nThere is a natural loop between %d and %d, whose memebers are:",d,n);
for(i=0;i<lcount;i++)
printf("\n%d",loop[i]);
}

else
printf("\n NO natural looop found!") ;


getch();
}

void push(int item)
{
top++;
stack[top]=item;
//printf("\n pushing %d",stack[top]) ;
}

int pop()
{
int res;
res=stack[top];
top--;
//printf("\n popping %d",res);
return res;
}

void insert(int item)
{
int inloop=0,i;

	for(i=0;i<lcount;i++)
	{
		if(loop[i]==item)
		{
		inloop=1;
		break;
		}
		else
		inloop=0;
	}
			 if(inloop==0)
			 {
			 loop[lcount++]=item;
			 printf("\n pushing from insert %d",item);
			 push(item);
			 }

}


void findpredecessor(int element)
{
//printf("\n Finding predecessor of %d",element);
precount=0;
	for(i=0;i<10;i++)
	{ 	if(fgraph[i][element]==1)
		pre[precount++]=i;
	}

printf("\n Predecessors of %d are:",element) ;

for(i=0;i<precount;i++)
printf("\n%d ",pre[i]);

}


int checkdominator(int element,int dom)        // to check if dom is dominator of element
{
int ans=0;
int tempdom=-1;

printf("\n value of element is\t%d",element);
	for(i=0;i<10;i++)
	{

		if(domtree[i][element]==1)

		{

		tempdom=i;
		break;
		}
	}


if((i==10)&&(tempdom<0))
{ans=0;                   // it is not the dominator (no child)
return ans;
}


if (tempdom==dom)
{
ans=1;
return ans;
}
      else

	{

	printf("\n Calling again!!");
	element=tempdom;
	ans=checkdominator(element,dom);
	}

return ans;
}
