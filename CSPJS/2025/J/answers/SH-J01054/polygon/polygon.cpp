#include <bits/stdc++.h>
using namespace std;

const int R = 998244353;
int a[5010];
int n, cnt;

void dfs(int num, int sum, int last)
{
	if (num == n) return;
	if (sum > a[last]*2) cnt = (cnt+1)%R;
	for (int i = last+1; i <= n; i++)
	{
		dfs(num+1, sum+a[i], i);
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);
	dfs(0, 0, 0);
	cnt += 1;
	cnt %= R;
	printf("%d", cnt);
	return 0;
}
