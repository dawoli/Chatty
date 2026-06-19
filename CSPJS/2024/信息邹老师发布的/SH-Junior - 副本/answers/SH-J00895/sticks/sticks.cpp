#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			printf("-1\n");
			continue;
		}
		else if(n==2)
		{
			printf("1\n");
			continue;
		}
		else if(n==3)
		{
			printf("7\n");
			continue;
		}
		else if(n==4)
		{
			printf("4\n");
			continue;
		}
		else if(n==5)
		{
			printf("5\n");
			continue;
		}
		else if(n==6)
		{
			printf("6\n");
			continue;
		}
		if(n%7==0)
		{
			int k=n/7;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==1)
		{
			printf("10");
			int k=n/7-1;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==2)
		{
			printf("1");
			int k=n/7;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==3)
		{
			printf("23");
			int k=n/7-1;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==4)
		{
			printf("20");
			int k=n/7-1;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==5)
		{
			printf("28");
			int k=n/7-1;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
		else if(n%7==6)
		{
			printf("6");
			int k=n/7;
			for(int i=1;i<=k;i++) printf("8");
			printf("\n");
		}
	}
	return 0;
}