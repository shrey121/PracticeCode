#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int i;
    int power = base % mod;

    for (i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}



 int main()
{
	static int p,q,flag,rem,e,d=1;
	static int i,count;
	static long long n;
	static char text[10],p[10];

	again:
	printf("\nEnter two Prime Nos >100 : ");
	scanf("%d",&p);
	fflush(stdin);
	scanf("%d",&q);
	fflush(stdin);

	if(p>100 && q>100)
	{
		for(i=2;i<(p/2);i++)
		{
			rem=p%i;

			if(rem==0)
			{
				printf("\nP is not prime");
				flag=1;
				goto again;
			}

		}

		printf("\nP is prime no.");

		if(flag==0)
		{
			for(i=2;i<(q/2);i++)
                	{
                        	rem=q%i;

                        	if(rem==0)
                        	{
                                	printf("\nQ is not prime");
                                	flag=1;
                                	goto again;
                        	}

                	}
		}

		printf("\nQ is prime no.");
	}

	else
	{
		goto again;
	}

	printf("\n");

	n=p*q;

	printf("\n%lld\n",n);

	rem=((p-1)*(q-1))/2;
	
	for(i=2;i<rem;i++)
	{
		if(rem%i!=0)
		{
			e=i;
			break;
		}
	}

	printf("\ne=%d\n",e);

	rem=(p-1)*(q-1);

	while(((e*d)%rem)!=1)
	{
		d++;
	}

	printf("d=%d\n",d);

	fflush(stdin);
	scanf("%s",text);
	fflush(stdin);

	puts(text);

	printf("\nmod=%d\n\n\n",modular(111,7,60));

	for(i=0;i<strlen(text);i++)
	{
		c[i]=modular(text[i]-97,e,n);
		printf("\t%d,c[i]);
		count++;
	}

	printf("plaintext\n\n");
	for(i=0;i<count;i++)
	{
		p[i]=modular(c[i],d,n);
                printf("\t%c,p[i]);
	}


	

} 
