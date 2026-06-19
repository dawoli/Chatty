#include<bits/stdc++.h>
using namespace std;
int n,t,num,c[10] = {6,2,5,5,4,5,6,3,7,6},s8;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n < 7)
		{
			if(n == 1) printf("-1\n");
			if(n == 2) printf("1\n");
			if(n == 3) printf("7\n");
			if(n == 4) printf("4\n");
			if(n == 5) printf("2\n");
			if(n == 6) printf("6\n");
			continue; 
		}
		if(n % 7 == 0)
		{
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 1)
		{
			printf("10");
			n -= 8;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 2)
		{
			printf("18");
			n -= 9;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 3)
		{
			printf("22");
			n -= 10;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 4)
		{
			printf("20");
			n -= 11;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 5)
		{
			printf("66");
			n -= 12;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
		else if(n % 7 == 6)
		{
			printf("80");
			n -= 13;
			for(int i = 1 ; i <= n/7 ; i++) printf("8");
			printf("\n");
			continue;
		}
	}
	return 0;
}
