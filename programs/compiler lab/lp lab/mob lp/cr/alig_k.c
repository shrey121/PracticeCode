 #include<stdio.h>
void main()
{
        FILE *fp;
        int a,i=0,j=0,l[30],k=0,p,x,p1,p2,blk[30][2],n,gen[30][50],kill[30][50];
        char d[50][20],c,q='0';
        
        //printf("check1\n");
        
        fp=fopen("leader.txt","r+");
        
        while(fscanf(fp,"%c",&c)!= EOF)
        {    
             d[i][j]=c;
             j++;
             
                if(c=='\n')
                {       
                        i++;
                        j=0;
                }
                
                x=i;
        }

        for(i=0;i<x;i++)
        {       
                j=0;
                while(d[i][j]!='\n')
                { 
                  printf("%c",d[i][j]);
                  j=j+1;
                }
                
                printf("\n");
        }

	k=0;
        l[0]=1;
        k++;
         for(i=0;i<x;i++)
        {       
                j=0;
                while(d[i][j]!='\n')
                { 
                  if(d[i][j]=='g' && d[i][j+1]=='o' && d[i][j+2]=='t')
                      {  
                        if(d[i][j+6]=='\n')
                          p=d[i][j+5]-q;
                        else
                          {
                                p1=d[i][j+5]-q;
                                p2=d[i][j+6]-q;
                                p=10*p1+p2;
                                //printf("\n%d %d",i,p);
                           }  
                         //p=p-50;
                         l[k]=p;
                         k++;
                         l[k]=i+2;       
                         k++;
                      }  
                  j++;
                }
                
                //printf("\n");
        }
        l[k]=-1;
        l[k+1]=-1;
        i=0;
       
        while(l[i]!=-1)
        {
                j=0;
                while(l[j]!=-1)
                {
                        if(l[j]>l[j+1] && l[j+1]!=-1)
                        {       
                                p=l[j+1];
                                l[j+1]=l[j];
                                l[j]=p;
                        }
                       
                        k=j;
                        if(l[j]==l[j+1])
                                while(l[k]!=-1)
                                {       
                                      l[k]=l[k+1];
                                      k++;
                                }      
                        j++;
                 }
                 i++;
         }
        i=0;
         //for(i=0;i<10;i++)//
          while(l[i]!=-1)
        {              
                printf("%d  ",l[i]);
                i++;
        }
        p=i-1;
        printf("\n Blocks are:");
        for(i=0;i<p;i++)
        {
		blk[i][0]=l[i];
		blk[i][1]=l[i+1]-1;
                printf("\n%d - %d",l[i],l[i+1]-1);
        }
        blk[i][0]=l[i];
        blk[i][1]=x;
        printf("\n%d - %d",l[i],x);
        n=i+1;	//n= no. of blks
        
        for(i=0;i<n;i++)
        	for(j=0;j<x;j++)
        	{
        		gen[i][j]=0;
        		kill[i][j]=0;
        	}
        	
        for(i=0;i<n;i++)
        {
        	j=blk[i][0]-1;
        	while(j<=blk[i][1]-1)
        	{	
        
        		p2=0;
        		while(d[j][p2]!='\n')
        		{
        			if(d[j][p2]=='=')
        			gen[i][j]=1;
        			p2++;
        		}
        		j++;
        	}
        }	
        	
        	for(i=0;i<n;i++)
        	{
        		printf("\nBlock %d:",i+1);
        		for(j=0;j<x;j++)
        		{
        			printf(" %d",gen[i][j]);
        		}
        	}
        	
        	for(i=0;i<n;i++)
        	{
        		j=blk[i][0]-1;
        		
        		while(j<=blk[i][1]-1)
        		{
        			if(gen[i][j]==1)
        			{
        				//printf("entered ");
					for(k=0;k<x;k++)
					{
						if(k<blk[i][0]-1 || k>blk[i][1]-1)
						{
							if(d[k][0]==d[j][0] && d[k][1]==d[j][1])
							kill[i][k]=1;
						}
					}
				}
        			
        			j++;
        		}
        	}
        		
        		printf("\n\nKill:");
        		
        	for(i=0;i<n;i++)
        	{
        		printf("\nBlock %d:",i+1);
        		for(j=0;j<x;j++)
        		{
        			printf(" %d",kill[i][j]);
        		}
        	}	
        	
        	
}
        
	
