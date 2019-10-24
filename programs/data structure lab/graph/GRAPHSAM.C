#include<stdio.h>
#include<conio.h>
#include<process.h>

 struct list
{
   int val;
   struct list *link;

}*ptr=NULL,*temp;

 void main()
{
   static int am[6][6];
   static int i,j,n;

   struct list *al[5];

   FILE *f;

   clrscr();
   f=fopen("graph.txt","r+");

   while(!feof(f))
   {
      char c=fgetc(f);

      if(c!='\n')
      {
	 am[i][j++]=c-'0';
	 //printf("i=%d\n",i);
      }

      else
      {
	 i++;
	 //printf("j=%d\n",j);
	 j=0;
      }
   }


   n=i;
   n++;
   //printf("n=%d",n);
   printf("\t\tADJACENCY MATRIX:\n\n\t\t");

   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
	 printf("%d\t",am[i][j]);
      }
      printf("\n\t\t");
   }

   for(i=0;i<n;i++)
   {
      al[i]=(struct list*)malloc(sizeof(struct list));
      al[i]->val=i;
      al[i]->link=NULL;
   }
/*
   for(i=0;i<n;i++)
   {
      printf("\n%d",al[i]->val);
   }
*/
   for(i=0;i<n;i++)
   {
      temp=al[i];
      for(j=0;j<n;j++)
      {
	 if(am[i][j]!=0)
	 {
	    ptr=(struct list*)malloc(sizeof(struct list));
	    ptr->val=j;
	    ptr->link=NULL;
	    temp->link=ptr;
	    temp=ptr;
	 }
      }
   }

   printf("\n");
   for(i=0;i<n;i++)
   {
      temp=al[i];
      while(temp!=NULL)
      {
	 printf("%d-> ",temp->val);
	 temp=temp->link;
      }
      printf("\n");
   }


   fflush(stdin);
   getch();


}