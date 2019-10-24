#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int find(int line,int block[][10],int k)
  {
   int i ,j;
    for(i=0;i<k;i++)
     {
      for(j=0;j<2;j++)
      {
       if(line == block[i][j])
	 return i;
      }
  }
 return -1;
}
int already(int block[][10],int k)
  {
     int j=0;
     while(1)
      {
	if(block[k][j] == -1)
	 return j;
       else
	j++;
      }

  }
void enter(int line_no ,int item,int block[][10],int k)
  {
    int u,j;
    u = find(line_no,block,k);
     j= already(block,u);
    if(j!=-1)
     block[u][j] = find(item,block,k);
  }


int search(int arr[],int to_be_searched,int len)
 {
   int i;
   for(i=0;i<len;i++)
     if( arr[i] == to_be_searched )
       return 1;
   return 0;
 }


void sort_Leader(int arr[],int len)
 {
   int i,j,temp;
   for(i=0;i<len-1;i++)
     {
	for(j=i;j<len;j++)
	  {
	    if(arr[i]>arr[j])
	      {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	      }
	  }
     }
 }
int main()
 {
   FILE * fp;
   int i = 0 , k=1,block[10][10],end,j;
   char ip[50][50];
   int Leader[10],no_of_goto = -1;
   clrscr();
   for(i=0;i<10;i++)
      Leader[i] = -1;
   for(i=0;i<10;i++)
     for(j=0;j<10;j++)
       block[i][j]=-1;

   Leader[0] = 0;    //First statement is Leader
   fp =  fopen("sarfraz.txt","r");
   if(fp==NULL)
   printf("\nfile could not open\n");
   i = 0;
   while(fscanf(fp,"%s",&ip[i]) != EOF )
     {
      // printf("\ni=%d %s",i,ip[i]);
       if(strcmp(ip[i],"goto") == 0)
	   {
	      no_of_goto++;
	      if(!search(Leader,i-2*no_of_goto,k) )
		 Leader[k++] = i - 2*no_of_goto ;
	      i++;
	      fscanf(fp,"%s",&ip[i]);
	      //printf("he:%s ",ip[i]);
	      if(!search(Leader,atoi(ip[i]),k) )
	       Leader[k++] = atoi(ip[i]);
	  }

	  i++;
      }
    i--;
    end = i -2* (no_of_goto+1);
    sort_Leader(Leader,k);

     printf("LEADERS ARE : ");
     for(i=0;i<k;i++)
       printf("%d ",Leader[i]);

     printf("\n\nBLOCKS ARE : \n");
     for(i=0;i<k-1;i++)
	printf("\n\t%2d to %2d" ,Leader[i],Leader[i+1]-1);

      printf("\n\t%2d to %2d ",Leader[i],end);

     for(i=0;i<k;i++)
       {
	  block[i][0] = Leader[i];
	  block[i][1] = Leader[i+1]-1;
       }
      block[i-1][0] = Leader[i-1];
      block[i-1][1] = end;

   for(i=0;i<k;i++)
     {
       if(i!=k-1)
      block[i][2] = i+1;
    }
    rewind(fp);
    printf("\n");
    i=0;no_of_goto = 1;
     while(fscanf(fp ,"%s\n",&ip[i]) != EOF )
    {
	  if(strcmp(ip[i],"goto") == 0)
	     {
		no_of_goto++;
		i++;
		fscanf(fp,"%s\n",&ip[i]);
		enter(i-(2*no_of_goto)+2,atoi(ip[i]),block,k);

	     }
	   i++;
    }
  printf("\n\tFLOW GRAPH :\n\n");
    for(i=0;i<k;i++)
	{
	 printf("B%d : ",i);
	 for(j=2;j<4;j++)
	   {
	     if(block[i][j]==-1)
	     printf("%2c ",45);
	     else
	      printf("B%d ",block[i][j]);
	   }
	  printf("\n");
	}
    getch();
    return 0;

 }