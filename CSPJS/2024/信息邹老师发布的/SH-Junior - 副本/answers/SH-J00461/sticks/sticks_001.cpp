#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	scanf("%d",&n);
	int cnt = n / 7,L = n % 7;
	if(L == 0)
	{
		for(int i = 1; i <= cnt; i++) printf("8");
		printf("\n");
		return;
	}
	if(L == 1)
	{
		if(cnt == 0)
		{
			printf("-1\n");
			return;
		}
		printf("1");
		for(int i = 1; i < cnt; i++) printf("8");
		printf("9\n");
		return;
	}
	if(L == 2)
	{
		printf("1");
		for(int i = 1; i <= cnt; i++) printf("8");
		printf("\n");
		return;
	}
	if(L == 3)
	{
		printf("7");
		for(int i = 1; i <= cnt; i++) printf("8");
		printf("\n");
		return;
	}
	if(L == 4)
	{
		if(cnt == 0)
		{
			printf("4\n");
			return;
		}
		printf("20");
		for(int i = 1; i < cnt; i++) printf("8");
		printf("\n");
		return;
	}
	if(L == 5)
	{
		printf("2");
		for(int i = 1; i <= cnt; i++) printf("8");
		printf("\n");
		return;
	}
	if(L == 6)
	{
		printf("6");
		for(int i = 1; i <= cnt; i++) printf("8");
		printf("\n");
		return;
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();	
}
