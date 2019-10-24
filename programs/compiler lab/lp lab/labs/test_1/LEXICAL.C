#include<stdio.h>
#include<string.h>


char delim[25]={';',',','(',')','[',']','{','}','=','+','-','/','*','%','#','<','>','!','&','|','^','~','.','"',' '};


int check(char);
void analyze(const char *);


int main(int argc,char *argv[])
{
if(argc!=2)
printf("Usage: Lexi fileName");
analyze("karo.c");


return 0;


} 


int check(char c)
{
int i,present=0;
int length;

delim[25]='\0';

length=strlen(delim);
for(i=0;i<length;i++)
if(delim[i]==c)
present=1;
return present;
}


void analyze(const char *fileName)
{
FILE *fp;

char next_token[100];
char buffer[100],delim_as_token;
int i,j,k;
int start_point=0,end_point=0;

fp=fopen(fileName,"r");

//printf("%s",buffer);

for(i=0;i<100;i++)
buffer[i]=next_token[i]='\0';






while(fgets(buffer, 100, fp) != NULL)
{

//printf("%s",buffer);	
	start_point=i=0;
	while(i<strlen(buffer))
	{

		if(check(buffer[i]))
		{
		end_point=i;

		k=0;
		for(j=start_point;j<end_point;j++)
		next_token[k++]=buffer[j];

		next_token[k]='\0';
		
		if(strcmp(next_token,"")!=0)
		printf("  [%s]",next_token);
		
		if(buffer[i]!=' ')
		printf("  [%c]",buffer[i]);
		
		start_point=end_point+1;
		}

	i++;	
	}

printf("\n");

}
fclose(fp);
}




