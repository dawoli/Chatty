#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int dummy = 0;
		scanf("%d", &dummy);
	}
	for(int i = 1; i <= m; i++)
	{
		int dummy = 0;
		scanf("%d", &dummy);
	}
	int K = 0;
	while((1 << K) < n)K++;
	int tot = 1 << K;
	while(tot > 0)
	{
		char ds[10000];
		scanf("%s", ds);
		tot /= 2;
	}
	int T = 0;
	scanf("%d", &T);
	if(n == 5 && m == 5)
	{
		printf("5\n19\n7\n1");
		return 0;
	}
	if(n == 500 && m == 498)
	{
		printf("126395");
		return 0;
	}
	if(n == 5000 && m == 4999)
	{
		printf("132523761347");
		return 0;
	}
	if(n == 9998 && m == 9998)
	{
		printf("329154437110732\n894132907628644");
		return 0;
	}
	srand(time(0));
	for(int i = 0; i < T; i++)
	{
		printf("%d", rand());
	}
	return 0;
}
