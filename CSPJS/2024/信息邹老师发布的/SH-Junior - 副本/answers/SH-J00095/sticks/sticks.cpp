#include <cstdio>
using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n <= 1)
		{
			printf("-1\n");
			continue;
		}
		if(n % 7 == 0)
		{
			for(int i = 7;i <= n;i += 7) printf("8");
		}
		else if(n % 7 == 1)
		{
			printf("10");
			for(int i = 15;i <= n;i += 7) printf("8");
		}
		else if(n % 7 == 2)
		{
			printf("1");
			for(int i = 9;i <= n;i += 7) printf("8");
		}
		else if(n % 7 == 3)
		{
			if(n == 3) printf("7");
			else if(n == 10) printf("22");
			else
			{
				printf("200");
				for(int i = 24;i <= n;i += 7) printf("8");
			}
		}
		else if(n % 7 == 4)
		{
			if(n == 4) printf("4");
			else
			{
				printf("20");
				for(int i = 18;i <= n;i += 7) printf("8"); 
			}
		}
		else if(n % 7 == 5)
		{
			printf("2");
			for(int i = 12;i <= n;i += 7) printf("8");
		}
		else
		{
			printf("6");
			for(int i = 13;i <= n;i += 7) printf("8");
		}
		printf("\n");
	}
	return 0;
}
