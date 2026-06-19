#include<cstdio>
using namespace std;
int T;
int n;
const int cnt[]={6,2,5,5,4,5,6,3,7,6};
void solve1()
{
	for(int i=1;i<=n/7;i++)
		putchar('8');
	puts("");
}
void solve2()
{
	if(n==1)puts("-1");
	else
	{
		printf("10");
		for(int i=1;i<=n/7-1;i++)
			putchar('8');
		puts("");
	}
}
int f(int x)
{
	int ret=0;
	while(x)
	{
		ret+=cnt[x%10];
		x/=10;
	}
	return ret;
}
void solve3()
{
	for(int i=1;i<=1000000;i++)
		if(f(i)==n)
		{
			printf("%d\n",i);
			return;
		}
	puts("-1");
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n%7==0)
			solve1();
		else if(n%7==1)
			solve2();
		else
			solve3();
	}
	return 0;
}

