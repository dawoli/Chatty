#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;++i) printf("8");
			printf("\n");
		}
		else if(n%7==1)
		{
			if(n==1) printf("-1\n");
			else
			{
				printf("10");
				for(int i=1;i<=n/7-1;++i) printf("8");
				printf("\n");	
			}
		}
		else if(n%7==2)
		{  
			printf("1");
			for(int i=1;i<=n/7;++i) printf("8");
			printf("\n");
		}
		else if(n%7==3)
		{
			if(n==3) printf("7\n");
			else if(n==10) printf("22\n");
			else
			{
				printf("200");
				for(int i=1;i<=n/7-2;++i) printf("8");
				printf("\n");
			}
		}
		else if(n%7==4)
		{
			if(n==4) printf("4\n");
			else 
			{
				printf("20");
				for(int i=1;i<=n/7-1;++i) printf("8");
				printf("\n");
			}
		}
		else if(n%7==5)
		{
			printf("2");
			for(int i=1;i<=n/7;++i) printf("8");
			printf("\n");
		}
		else if(n%7==6)
		{
			printf("6");
			for(int i=1;i<=n/7;++i) printf("8");
			printf("\n");	
		}
	}
	
	return 0;
}
