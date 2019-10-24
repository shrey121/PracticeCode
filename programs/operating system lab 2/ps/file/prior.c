#include<stdio.h>

#include<conio.h>
int main()

{
	int data[10][2],i,j,ti,sm,pos,n,gc[10][2],tc;

	float awt,atat;

	FILE *p;

	clrscr();
	p=fopen("ps.txt","r+");

	if(p==NULL)

	{	printf("\nCouldn't open file");

		return 1;

	}

	i=0;

	while((fscanf(p,"%d %d", &data[i][0],&data[i][1]))!=EOF)

	{	i++;

	}
	
n=i;

	printf("\nContents of file are:\nProcess\t\tBurst time\tPriority");

	for(i=0;i<n;i++)

	{	printf("\np%d\t\t\t%d\t%d",(i+1),data[i][0],data[i][1]);

	}

	tc=0;

	ti=0;

	for(i=0;i<n;i++)

	{	sm=32000;

		for(j=0;j<n;j++)

		{	if(data[j][1]<sm)

			{	sm=data[j][1];

				pos=j;

			}

		}

		tc=tc+data[pos][0];

		gc[ti][0]=pos;

		gc[ti][1]=tc;

		ti++;

		data[pos][1]=32000;

	}

	awt=0;

	atat=0;

	for(i=0;i<(n-1);i++)

	{	awt=(float)(awt+gc[i][1]);

	}

	for(i=0;i<n;i++)

	{	atat=(float)(atat+gc[i][1]);

	}

	awt=(float)(awt/n);

	atat=(float)(atat/n);

	printf("\nAverage waiting time:\t%f",awt);

	printf("\nAverage turn around time:\t%f",atat);

	printf("\nG chart:\n");

	for(i=0;i<ti;i++)

	{	printf("+-------------\t+");

	}

	printf("\n");

	for(i=0;i<ti;i++)

	{	printf("|\tp%d\t|",(gc[i][0]+1));

	}

	printf("\n");

	for(i=0;i<ti;i++)

        {       printf("+-------------\t+");

        }

	printf("\n0\t\t");

	for(i=0;i<ti;i++)

        {       printf("%d\t\t",gc[i][1]);

        }

	printf("\n");

	getch();
	return 0;

}
