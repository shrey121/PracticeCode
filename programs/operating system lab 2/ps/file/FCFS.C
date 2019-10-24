#include<stdio.h>

#include<conio.h>
int main()

{	int data[10],i,j,n,gc[10],tc;

	float awt,atat;

	FILE *p;

	clrscr();
	p=fopen("ps.txt","r+");

	if(p==NULL)

	{	printf("\nCouldn't open file");

		return 1;

	}

	i=0;

	while((fscanf(p,"%d", &data[i]))!=EOF)

	{	i++;

	}
	
n=i;

	printf("\nContents of file are:\nProcess\t\tBurst time");

	for(i=0;i<n;i++)

	{	printf("\np%d\t\t\t%d",(i+1),data[i]);

	}

	tc=0;

	for(i=0;i<n;i++)

	{	tc=tc+data[i];

		gc[i]=tc;


	}

	awt=0;

	atat=0;

	for(i=0;i<(n-1);i++)

	{	awt=(float)(awt+gc[i]);

	}

	for(i=0;i<n;i++)

	{	atat=(float)(atat+gc[i]);

	}

	awt=(float)(awt/n);

	atat=(float)(atat/n);

	printf("\nAverage waiting time:\t%f",awt);

	printf("\nAverage turn around time:\t%f",atat);

	printf("\nG chart:\n");

	for(i=0;i<n;i++)

	{	printf("+-------------\t+");

	}

	printf("\n");

	for(i=0;i<n;i++)

	{	printf("|\tp%d\t|",(i+1));

	}

	printf("\n");

	for(i=0;i<n;i++)

        {       printf("+-------------\t+");

        }

	printf("\n0\t\t");

	for(i=0;i<n;i++)

        {       printf("%d\t\t",gc[i]);

        }

	printf("\n");

	getch();
	return 0;

}
