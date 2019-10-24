/*******************************************************************************
**                    C program for LZW Decompression                         ** 
**                    created by: Deepanshu Bhatia                            **
**                    Roll No. : 11-css-15                                    **                              
*******************************************************************************/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2000
init_dict();
int i=0;
static char dictab[4096][32];
void main()
{
     int count=0;
     init_dic();
     int j,k[MAX];
     static char str[MAX],temp[32],c[2];
     printf("\n\tEnter the compressed data in integers : \n\t(enter 0 to terminate the input)\n");
     
     /**************************Decompression**********************************/
     
     /*******Decoding first value.Its always present in the dictionary*********/
     scanf("%d",&k[count]);
     strcpy(str,dictab[k[count]]);
     strcpy(temp,dictab[k[count]]);
     count++;
     
     /*******************Decoding subsequent values****************************/
     while(temp[0]!=NULL)
     {
                         scanf("%d",&k[count]);
                         strcat(str,dictab[k[count]]);
                         j=strlen(temp);
                         temp[j]=dictab[k[count]][0];
                         temp[j+1]=0;
                         strcpy(dictab[i],temp);
                         i++;
                         strcpy(temp,dictab[k[count]]);
                         count++;
     }
     printf("\n\tAfter decompressing the input\n\tString : ");
     puts(str);

     printf("\n\tSize of compressed String = %3.f bytes\n",(count-1)*1.5);
     printf("\n\tSize of decompressed string = %d bytes\n",strlen(str));
     system("pause");
     return;
     
}
    
/**********Initialising the Dictionary Table********/ 
init_dic()
{
          char a[32];
          while(i<256)
          {
                      a[0]=i;
                      a[1]=0;
                      strcpy(dictab[i],a);
                      i++;                    
          }           
}


