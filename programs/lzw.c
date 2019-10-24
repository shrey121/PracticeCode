/*
 * main.cpp
 *
 *  Created on: 19-Mar-2013
 *      Author: Safiyat Reza
 */

#include <stdio.h>
#include <stdio_ext.h>		//This header file is used in gcc, for __fpurge(). If in Turbo C, use fflush() instead of __fpurge()
#include <string.h>
#include <stdlib.h>

#define MAX 8092

void fill(int *s, char **stra, const char *temp)
/*fill entries in the dictionary*/
{
	*stra=(char *)malloc(sizeof(char)*strlen(temp));
	strcpy(*stra, temp);
	*s=*s+1;
}


void print_table_entry(int i, char *stra)
/*Print entries in the table of the form "%d: %s"*/
{
	printf("%d\t\t\t", i);
	printf(" %s\n", stra);
}

void print_trans(int n, char *stra[])
/*Print translation in the dictionary stra of entry number n*/
{
	printf("%s", stra[n]);
}

void addchartostr(char cha, char *stra)
/*Add a character to a string. More convenient is: strcpy(stra, "cha")*/
{
	stra[strlen(stra)+1]='\0';
	stra[strlen(stra)]=cha;
}

void init(int *sizea, char **stra)
/*Initiate the dictionary with the first 255 entries*/
{
	char temp[256];
	while(*sizea<256)
	{
		sprintf(temp, "%c", *sizea);
		fill(sizea, &stra[*sizea], temp);
	}
}



char *str[MAX], *ostr[MAX]; //Pointers to dictionary entries
int size=0, osize=0;

int main()
{
	int i=0, j, flag, match, *term, n=0, choice;
	char txt[MAX]="the/rain/in/Spain/falls/mainly/on/the/plain", STR[32], CHAR, *ptr;
	do
	{
		printf("1. Enter text to be compressed\n");
		printf("2. See a sample run\n");
		printf("3. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		__fpurge(stdin);
	}while(choice<1||choice>4);
	switch(choice)
	{
		case 1:	printf("\nEnter text: ");
			gets(txt);
			break;

		case 2: printf("\nSample text:\nthe/rain/in/Spain/falls/mainly/on/the/plain\n");
			break;

		case 3:	return 0;
	}
	/***************End of input*******************
********************************************************************************
	**************** Compression******************/
	term=(int *)malloc(sizeof(int)*strlen(txt));
	printf("\t\tCompression starts:\n");
	ptr=txt;
	init(&size, str);
	term=(int *)malloc(sizeof(int)*strlen(txt));
	i=0;
	STR[i++]=*ptr++;
	match=STR[0];
	do
	{
		CHAR=*ptr++;
		STR[i++]=CHAR;
		STR[i]='\0';
		flag=0;
		for(j=0; j<size; j++)
		{
			if(strncmp(str[j], STR, strlen(STR))==0)
			{
				match=j;
				printf("\n\nMatch for %s found at %d. Matches \"%s\".", STR, match, str[match]);
				flag=1;
				break;
			}
		}
		if(flag)
		{
			printf(" Continuing...\n");
			continue;
		}
		printf("\nMatch for %s not found. Last match was %s at %d. Entered entry for %s at %d.", STR, str[match], match, STR, size);
		term[n++]=match;
		fill(&size, &str[size], STR);
		i=1;
		STR[0]=CHAR;
		match=STR[0];
	}while(CHAR!='\0');
	term[n++]=match;
	printf("\nOutput:\n");
	printf("\nChar no.\t\tEntry no.\t\tEntry\n");
	for(i=0; i<n; i++)
	{
		printf("i = %d\t\t\t", i);
		print_table_entry(term[i], str[term[i]]);
	}
		/***************End of compression****************/
	printf("\n\nUncompressed size: %d Bytes. Compressed size: %3.f Bytes\n", (int)strlen(txt), n*1.5);
	printf("\n*************END*************\n");
	return 0;
}
