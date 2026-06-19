#include<bits/stdc++.h>
using namespace std;

int ans[5] = {-1, 1, 7, 4}, g[10] = {8, 10, 18, 22, 20, 2, 6};

void solve()
{
	int n;
	scanf("%d", &n);
	if(n < 5)
	{
		printf("%d\n", ans[n - 1]);
		return;
	}
	printf("%d", g[n % 7]);
	if(n % 7 < 5) n -= 7;
	n -= n % 7;
	while(n)
	{
		n -= 7;
		printf("8");
	}
	printf("\n");
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	while(t--) solve();
}
