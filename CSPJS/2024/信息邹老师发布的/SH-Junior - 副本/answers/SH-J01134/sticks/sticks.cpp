#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,p=0;
		scanf("%d",&x);
		if(x%7==0 && x>0)
		{
			p=1;
			for(int i=0;i<x/7;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x==2)
		{
			p=1;
			printf("1"); 
			printf("\n");
			continue;
		}
		if(x==3)
		{
			p=1;
			printf("7"); 
			printf("\n");
			continue;
		}
		if(x==4)
		{
			p=1;
			printf("4");
			printf("\n");
			continue; 
		}
		if(x==5)
		{
			p=1;
			printf("2"); 
			printf("\n");
			continue;
		}
		if(x==6)
		{
			p=1;
			printf("6"); 
			printf("\n");
			continue;
		}
		if(x==9)
		{
			p=1;
			printf("18");
			printf("\n"); 
			continue;
		}
		if(x==10)
		{
			p=1;
			printf("22");
			printf("\n"); 
			continue;
		}
		if(x==11)
		{
			p=1;
			printf("20");
			printf("\n"); 
			continue;
		}
		if(x==12)
		{
			p=1;
			printf("28");
			printf("\n"); 
			continue;
		}
		if(x==13)
		{
			p=1;
			printf("80");
			printf("\n"); 
			continue;
		}
		if(x==15)
		{
			p=1;
			printf("108");
			printf("\n"); 
			continue;
		}
		if(x==16)
		{
			p=1;
			printf("400");
			printf("\n");
			continue; 
		}
		if(x==17)
		{
			p=1;
			printf("200");
			printf("\n"); 
			continue;
		}
		if(x==18)
		{
			p=1;
			printf("208");
			printf("\n"); 
			continue;
		}
		if(x==19)
		{
			p=1;
			printf("800");
			printf("\n"); 
			continue;
		}
		if(x==20)
		{
			p=1;
			printf("808");
			printf("\n"); 
			continue;
		}	
		if(x<=1)
		{
			printf("-1");
			printf("\n");
			continue;
		}
		if(x%7==2  && x>=9)
		{
			p=1;
			printf("1");
			for(int i=0;i<x/7;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x%7==1 && x>=8)
		{
			p=1;
			printf("10"); 
			for(int i=0;i<x/7-1;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x%7==3 && x>=10)
		{
			p=1;
			printf("7");
			for(int i=0;i<x/7;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x%7==4 && x>=11)
		{
			p=1;
			printf("4"); 
			for(int i=0;i<x/7-1;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x%7==5 && x>=12)
		{
			p=1;
			printf("2");
			for(int i=0;i<x/7;i++)
			{
				printf("8");
			}
			printf("\n");
		}
		if(x%7==6 && x>=13)
		{
			p=1;
			printf("6"); 
			for(int i=0;i<x/7-1;i++)
			{
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
