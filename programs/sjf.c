#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 int main()
{
	static int ar[5],bt[5],exe[5],burst[5],arr[5],wt[5],tat[5];
	char name[5][5],nm[5][5];
	static int i,j,k,cnt,count,n,flag,minb,mina,time,timef,wait,ta;
	float awt,atat;

	FILE *p;
	p=fopen("abc.txt","r+");

	printf("\nprocess  arrival  burst\n");

	while((fscanf(p,"%s %d %d",name[i],&arr[i],&burst[i]))!=EOF)
	{
		bt[i]=burst[i];
		ar[i]=arr[i];
		printf("%s\t %d\t %d\n",name[i],ar[i],bt[i]);
		i++;
		n++;
	}

//	printf("\n%d %d\n",i,n);

	fclose(p);
	fflush(stdin);

        mina=ar[0];
        minb=bt[0];

	for(i=0;i<n;i++)
        {
                burst[i]=bt[i];
        }

	
	printf("\n");
	for(i=0;i<15;i++)
        {
                printf("----");
        }
	printf("\n");
        
	while(k<n)
        {
                minb=999999;
                for(i=0;i<n;i++)
		{
			if(ar[i]<(mina+time) && flag==0 && exe[i]==0)
			{
				mina=ar[i];
				
				if(bt[i]<minb)
				{
					minb=bt[i];
					j=i;
				}

				if(bt[i]==minb && ar[j]>ar[i])
				{
					j=i;
				}

			}

			else if(flag==1 && bt[i]<=minb && ar[i]<=time && exe[i]==0)
			{
				if(bt[i]<minb)
				{
					minb=bt[i];
					j=i;
				}

				else if(ar[j]>ar[i])
				{
					j=i;
				}
			}
		}
		
		timef=time;
		printf("| %s", name[j]);
		cnt++;

		for(i=0;i<n;i++)
		{
			if(j!=i && exe[i]==0 && ar[i]<=timef)
			{
				wt[i]+=1;
			}

			else if(j==i && exe[i]==0)
			{
				bt[i]-=1;
				time+=1;
				flag=1;

				if(bt[i]==0)
				{
					k++;
					exe[i]=1;
					strcpy(nm[count++],name[i]);
				}
			}
		}
	}

	printf("|\n");
        for(i=0;i<15;i++)
        {
                printf("----");
        }
        printf("\n");

        for(i=0;i<15;i++)
        {
                if(i<10)
			printf("%d   ",i);
		else
			printf("%d  ",i);
        }
        printf("\n");

	for(i=0;i<n;i++)
	{
		wait+=wt[i];
		tat[i]=burst[i]+wt[i];
		ta+=tat[i];
	}

	awt=(float)wait/n;
	atat=(float)ta/n;
	printf("\nawt=%f",awt);
	printf("\natat=%f\n",atat);
}

