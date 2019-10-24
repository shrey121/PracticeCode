#include<stdio.h>
#include<string.h>
#include<math.h>


void rm_duplicate(int leader[100])
{
int i,j;
int array_size;
i=0;
while(leader[i++]!='\0')
{
          array_size=i;
}

j=0;

for(i=0;i<array_size;i++)
          {
                    if (leader[i] != leader[j])
                    {
                              j++;
                              leader[j] = leader[i]; // Move it to the front
                    }
          }

leader[j+1]='\0';
}


void find_gen(int leader[100],int gen_matrix[100][100],char tac[100][100],int block_count,int lines)
{         
          int i,j;
          char *if_equal;
          for(i=0;i<100;i++)
          {
                    for(j=0;j<100;j++)
                    {
                              gen_matrix[i][j]=0;
                    }
          }
          for(i=0;i<block_count-1;i++)
          {
                    for(j=leader[i]-1;j<leader[i+1]-1;j++)
                    {
                              if_equal=strstr(tac[j],"=");      
                              if(if_equal)
                              {
                                        gen_matrix[i][j]=1;
                              }                
                    }
          }

          for(j=leader[block_count-1]-1;j<lines;j++)
          {
                    if_equal=strstr(tac[j],"=");      
                    if(if_equal)
                    {
                              gen_matrix[block_count-1][j]=1;
                    }
          }

         
}

void find_kill(int leader[100],int kill_matrix[100][100],char tac[100][100],int block_count,int lines)
{
          int i,j,k;
          for(i=0;i<100;i++)
          {
                    for(j=0;j<100;j++)
                    {
                              kill_matrix[i][j]=0;
                    }
          }
          for(i=0;i<block_count-1;i++)
          {
                    for(j=leader[i]-1;j<leader[i+1]-1;j++)
                    {
                              for(k=0;k<lines;k++)
                              {
                                        if(k<leader[i]-1 || k>=leader[i+1]-1)
                                        {
                                                  if(tac[j][0]==tac[k][0] && tac[j][0]!='i' && tac[j][0]!='g')
                                                  {
                                                            kill_matrix[i][k]=1;
                                                  }
                                        }
                              }
                    }
          }
          
          for(j=leader[block_count-1]-1;j<lines;j++)
                    {
                              for(k=0;k<lines;k++)
                              {
                                        if(k<leader[block_count-1]-1 || k>leader[block_count-1])
                                        {
                                                  if(tac[j][0]==tac[k][0] && tac[j][0]!='i' && tac[j][0]!='g')
                                                  {
                                                            kill_matrix[block_count-1][k]=1;
                                                  }
                                        }
                              }
                    }
                    
}
          



int find_block(int col,int leader[100],int lines)
{
          int i=0,j;
          while(leader[i]!='\0')
          {
                    if(col>=leader[i] && col<leader[i+1])
                    {
                              return i+1;
                              break;
                    }
                    i++;
          }
          if(col>=leader[i-1] && col<=lines)
                    {
                              return i;
                    }
          else 
                    return 0;
}
                              

find_predecessor(int flow_graph[100][100],int block_count,int predecessor[100][100])
{
int i,j;
for(i=0;i<block_count;i++)
{
          for(j=0;j<block_count;j++)
          {
                    predecessor[j][i]=flow_graph[i][j];
          }
}
for(i=0;i<block_count;i++)
{
          printf("\npredecessor of block %d :",i+1);
          for(j=0;j<block_count;j++)
                    {
                              if(predecessor[i][j]==1)
                              {
                                        printf("%d ",j+1);
                              }
                    }
}
printf("\n\n");
}

void copy(int a[100][100],int b[100][100])
{                              
          int x,y;
          for(x=0;x<100;x++)
          for(y=0;y<100;y++)
          b[x][y]=a[x][y];
}       
 
                   
void find_in(int gen_matrix[100][100],int kill_matrix[100][100],int flow_graph[100][100],int block_count,int lines,int in_matrix[100][100],int out_matrix[100][100])
{
          int i,j,k,l;
          int ctr=0;
          int predecessor[100][100];
          int cpy_in[100][100],cpy_out[100][100];
          find_predecessor(flow_graph,block_count,predecessor);
          
        
         
          while(1)
          {
                    copy(in_matrix,cpy_in);
                    copy(out_matrix,cpy_out);
                    
                    for(i=0;i<block_count;i++)
                    {
                              for(k=0;k<block_count;k++)
                              {
                                        if(predecessor[i][k] == 1)
                                        {
                                                  for(l=0;l<lines;l++)
                                                  in_matrix[i][l]= in_matrix[i][l] | out_matrix[k][l];
                                        }
                              }
                              for(l=0;l<lines;l++)
                              out_matrix[i][l]=out_matrix[i][l] | (gen_matrix[i][l] | ((in_matrix[i][l]==1 && kill_matrix[i][l]==0)?1:0));
                    }
                    
                    ctr++;
                    
                              
                               for(i=0;i<block_count;i++)//printtttttttt
                              {
                                        printf("\n %d   :",i+1);
                                        for(j=0;j<lines;j++)
                                        {
                                                printf("%d ",in_matrix[i][j]);
                                                //printf("\t");
                                                //printf("%d ",out_matrix[i][j]);
                                        }
                              }
                              
                              printf("\n");
                              
                              for(i=0;i<block_count;i++)//printtttttttt out
                              {
                                        printf("\n %d   :",i+1);
                                        for(j=0;j<lines;j++)
                                        {
                                                printf("%d ",out_matrix[i][j]);
                                        }
                              }
                              
                    if(same_to_same(in_matrix,cpy_in) && same_to_same(out_matrix,cpy_out))
                    break;
          }
          printf("\nPasses required : %d",ctr);
}


                       
                         
int same_to_same(int a[100][100],int b[100][100])
{                              
          int x,y;
          for(x=0;x<100;x++)
          for(y=0;y<100;y++)
          {
                    if(b[x][y] != a[x][y])
                    return 0;
          }
          return 1;
}    

          
int main(void)
{
char tac[100][100],ch,*go_yes,*go_if,*if_equal;
int i=0,j=0,k,col,l,m,temp;
int lines,leader[100],block_count,block_no,last_line;
int gen_matrix[100][100],kill_matrix[100][100],in_matrix[100][100],out_matrix[100][100],flow_graph[100][100];
int predecessor[100][100];
FILE *fp;

fp=fopen("mytac.txt","r");
while((ch=fgetc(fp))!=EOF)
{
          if(ch=='\n')
          {
                    tac[i][j]='\0';
                    i++;
                    j=0;
          }
          else
          {
                    tac[i][j++]=ch;
          }
} 
                    
lines=i;

printf("\n\nThe TAC is:\n\n");

for(i=0;i<lines;i++)
{         j=0;
          printf("%d  :",i+1);
          while(tac[i][j++]!='\0')
          {
                    printf("%c",tac[i][j-1]);
                    
          }
          printf("\n");
} 

k=1;
leader[0]=1;
for(i=1;i<lines;i++)
{         
          go_yes=strstr(tac[i],"goto");
          if(go_yes)
          {         
                  
                    col=atoi(go_yes+5);
                    printf("%d line %d\n",i+1,col);
                    leader[k++]=col;              
                    if(i+2<=lines)
                    {
                              leader[k++]=i+2;
                    }
           }
} 

leader[k]='\0';

i=0;
while(leader[i++]!='\0')
{
          for(j=i;j<k;j++)
          {         
                    if(leader[i-1]>leader[j])
                    {
                              temp=leader[i-1];
                              leader[i-1]=leader[j];
                              leader[j]=temp;
                    }
          }
}

rm_duplicate(leader);

printf("\n\nThe leaders are :");
i=0;
while(leader[i++]!='\0')
{
          printf("%d ",leader[i-1]);
}          

printf("\n\nblocks are:\n");

i=0;
while(leader[i+1]!='\0')
{
          printf("\nBlock %d :%d - %d",i+1,leader[i],leader[i+1]-1);
          i++;
}
printf("\nBlock %d :%d - %d\n\n",i+1,leader[i],lines);

block_count=i+1;

find_gen(leader,gen_matrix,tac,block_count,lines);

printf("\n\nGen\n");

for(i=0;i<block_count;i++)
{
          printf("\n %d   :",i+1);
          for(j=0;j<lines;j++)
          {
                  printf("%d ",gen_matrix[i][j]);
          }
}
printf("\n\n");

find_kill(leader,kill_matrix,tac,block_count,lines);

printf("\n\nKill\n");
for(i=0;i<block_count;i++)
          {
                    printf("\n %d   :",i+1);
                    for(j=0;j<lines;j++)
                    {
                              printf("%d ",kill_matrix[i][j]);
                    }
          }
printf("\n\n");



//k=0;
for(i=0;i<block_count-1;i++)
{
          last_line=leader[i+1]-2;
          go_yes=strstr(tac[last_line],"goto");
          col=last_line+1;
          block_no=find_block(col,leader,lines);                
          if(go_yes)
          {
                    col=atoi(go_yes+5);
                    go_if=strstr(tac[last_line],"if");
                    
                    if(go_if)
                    {
                              flow_graph[i][block_no]=1;
                              block_no=find_block(col,leader,lines);
                              flow_graph[i][block_no-1]=1;
                    }
                    else
                    {
                              block_no=find_block(col,leader,lines);
                              flow_graph[i][block_no-1]=1;
                    }
                    
          }
          else
          {
                    col=last_line+1;
                    block_no=find_block(col,leader,lines);
                    flow_graph[i][block_no]=1;
          }
}

last_line=lines-1;
go_yes=strstr(tac[last_line],"goto");
if(go_yes)
{
          col=atoi(go_yes+5);
          block_no=find_block(col,leader,lines);
          go_if=strstr(tac[last_line],"if");
          flow_graph[block_count-1][block_no-1]=1;
}

printf("\n\nFlow graph is:\n\n   ");
for(i=0;i<block_count;i++)
{
          printf("%d ",i+1);
}
for(i=0;i<block_count;i++)
{         
          printf("\n%d :",i+1);
          for(j=0;j<block_count;j++)
          {
                    printf("%d ",flow_graph[i][j]);
          }
}
printf("\n\n");
//find_predecessor(flow_graph,block_count,predecessor);

for(i=0;i<100;i++)
{
          for(j=0;j<100;j++)
          {
                    in_matrix[i][j]=0;
                    out_matrix[i][j]=0;
          }
}

find_in(gen_matrix,kill_matrix,flow_graph,block_count,lines,in_matrix,out_matrix);

printf("\n\nIn\n");

for(i=0;i<block_count;i++)
{
          printf("\n %d   :",i+1);
          for(j=0;j<lines;j++)
          {
                  printf("%d ",in_matrix[i][j]);
          }
}
printf("\n\n");


printf("\n\nOut\n");

for(i=0;i<block_count;i++)
{
          printf("\n %d   :",i+1);
          for(j=0;j<lines;j++)
          {
                  printf("%d ",out_matrix[i][j]);
          }
}
printf("\n\n");
}
