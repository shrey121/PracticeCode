#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
char* iden[]={"char","int","float","const"};
char* key[]={"if","else","void","while","return","case","do","for","switch"};
char op[5]={'+','-','*','/','%','<','>','='};
char dlim[9]={';','{','}','(',')','[',']',':'};
int i=0,j=0,c1=0,k;
int del1[20]={0};
int op1[20]={0};
int ident1[20]={0};
char pro[100];

int iden(char ch)
    {
	if(isalpha(ch)||ch=='_'||isdegit(ch)||ch=='.')
	    return 1;
	else
	    return 0;
    }
int operator(char ch)
    {
	int f=0;
	for(i=0;i<8&&!f;i++)
	   {
	       if(ch==op[i])
	       f=1;
	   }
	return f;
    }
int del(char ch)
    {
	int f=0;
	for(i=0;i<8&&!f;i++)
	   {
	      if(ch==dlim[i])
	      f=1;
	   }
	return f;
    }
void rm_dup()
    {
	for(i=1;i<dli+1;i++)
	   {
	       if(del1[i-1]==0)
		 {
		     del2[di++]=dlm[i++];
		     for(j=i;j<dli;j++)
			{
			    if(dlm[i-1]=dlm[j])
			    del1[j]=1;
			}
		 }
	   }
	for(i=1;i<idi+1;i++)
	   {
	       if(ident1[i-1]==0)
		 {
		     strcpy(ident1[id1i++],ident[i-1]);
		     for(j=i;j<idi;j++)
			{
			    if(!strcmp(ident[i-1],ident[j]))
			    ident1[j]=1;
			}
		 }
	   }
	 for(i=1;i<opri+1;i++)
	   {
	       if(oprtr1[i-1]==0)
		 {
		     strcpy(oprtr1[opri++],oprtr[i-1]);
		     for(j=i;j<opri;j++)
			{
			    if(!strcmp(oprtr[i-1],oprtr[j]))
			    oprtr1[j]=1;
			}
		 }
	   }
    }
void final()
    {
	 int i=0;
	 idi=0;
	 for(i=0;i<uqidi;i++)
	    {
		  if(Iskey(uqiden[i]))        //identifying keywords
		  strcpy(keyword[kdi++],uqiden[i]);
		  else
		  if(isdigit(uqiden[i][0]))    //identifying constants
     strcpy(constant[ci++],uqiden[i]);
     else
     strcpy(iden[idi++],uqiden[i]);
   }
// printing the outputs
printf("\n\tDelemeter are : \n");
for(i=0;i<uqdi;i++)
printf("\t%c\n",uqdel[i]);

printf("\n\tOperators are : \n");
for(i=0;i<uqoperi;i++)
 {
 printf("\t");
 puts(uqop[i]);
 }

printf("\n\tIdentifiers are : \n");
for(i=0;i<idi;i++)
 {
  printf("\t");
  puts(iden[i]);
 }

printf("\n\tKeywords are : \n");
for(i=0;i<kdi;i++)
 {
  printf("\t");
  puts(keyword[i]);
 }

printf("\n\tConstants are :\n");
for(i=0;i<ci;i++)
  {
  printf("\t");
  puts(constant[i]);
  }

printf("\n\tLiterals are :\n");
for(i=0;i<liti;i++)
 {
   printf("\t");
   puts(litral[i]);
 }
}

void main()
{
   clrscr();
   printf("Enter the program:\n");
   gets(pro);
   while(pro[i]!=NULL)
	{
	    if(iden(pro[i]))
	      {
		  while(iden(pro[i]))
		       {
			   idnt[idi][idj++]=pro[i++];
			   idnt[idi][idj]=NULL;
			   idi++;idj=0;
		       }
	    else
	    if(pro[i]=='"')
	      {
		  lit[l++]=pro[i];
		  for(j=i+1;pro[j]!='"';j++)
		     {
			lit[l++]=pro[j];
		     }
		  lit[l++]=pro[j];lit[l]=NULL;
		  strcpy(literal[liti++]=lit);
		  i=j+1;
	      }
	    else
	    if(op(pro[i]))
	      {
		  while(operator(pro[i]))
		       {
			   oprtr[opri][oprj++]=pro[i++];
		       }
		  oprtr[opri][oprj]=NULL;
		  opri++;oprj=0;
	      }
	    else
	    if(del(pro[i]))
	      {
		  while(del(pro[i]))
		       {
			   dlm[dli++]=pro[i];
		       }
	      }
	    else
	      {
		  i++;
	      }
	}
   rm_dup();
   final();

   getch();
}

