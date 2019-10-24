#include<stdio.h>
#include<conio.h>
int states[10][10][10];
char str[50];
int function(int istate,int fstate,int ilen)
{
	int i,cstate=istate,j;
	if(str[ilen]=='\0' && cstate==fstate) {return 1;}//acceptable
	else if(str[ilen]=='\0') {return 0;}//not acceptable
	else {
		for(j=0;states[cstate][str[ilen]-97][j]!=-1;j++) {
		if(function(states[cstate][str[ilen]-97][j],fstate,ilen+1)==1) {return 1;}//acceptable
		}
	}
	return 0;//not acceptable
}
int main()
{
FILE *fl;
int i,a,j,k;
int currentstate,finalstate,initialstate;
int row=0,col=0,ht=0,nofcols=0,nofrows=0;
char c;
//clrscr();
fl=fopen("abc2.txt","r");
while(1){
	fscanf(fl," %d%c ",&a,&c);
	printf("  %d%c",a,c);
	if(feof(fl)) break;
	if(c==' ') {
		states[row][col][ht++]=a;
		states[row][col][ht]=-1;
		col++;ht=0;
		//if(nofcols<col) nofcols=col;
		}
	else if(c==',') {
		states[row][col][ht++]=a;
		}
	else if(c=='\n') {
		states[row][col][ht++]=a;
		states[row][col][ht]=-1;
		ht=0;
		col=0;
		row++;
		//nofrows=row;
		}
	else if(c=='#') {
		states[row][col][ht++]=a;
		states[row][col][ht]=-1;
		nofrows=row;
		nofcols=col;
		//fscanf(fl,"%c",&c);
		//printf(" c is %c",c);
		//while(!feof(fl))
		//{printf("%c",c);
		//fscanf(fl,"%d",&c);
		//}
		fscanf(fl,"%d%c",&a,&c);
		//printf( "istate %c%d",c,a);
		initialstate=a;
		fscanf(fl," %d%c ",&a,&c);
		finalstate=a;
		break;
		}
	}

printf("\n input is :\n");
for(i=0;i<=nofrows;i++) {
	for(j=0;j<=nofcols;j++) {
		 for(k=0;states[i][j][k]!=-1;k++) {
		 printf("%d,",states[i][j][k]);
		 }
		 printf("-1 ");
		 }
	printf("\n");
}
printf("\n initial state is %d final state is %d",initialstate,finalstate);
//printf("\n nofrows: %d nofcols %d",nofrows,nofcols);
printf("\n enter string:");
scanf("%s",str);
if(function(initialstate,finalstate,0)==1)
printf("\n string acceptable");
else printf("\n string not acceptable");
//getch();
return 0;
}

