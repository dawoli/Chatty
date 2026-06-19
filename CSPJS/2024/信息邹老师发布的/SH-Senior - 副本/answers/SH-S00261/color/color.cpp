#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[200001];
bool c[200001];
long long ans;

void dfs(int num)
{
	if(num == n+1)
	{
		long long sum = 0;
		int b = 0, r = 0;
		for(int i = 1; i <= n; i++)
		{
			if(c[i] == false)
			{
				if(b == 0) b = a[i];
				else if(b != 0 && a[i] == b) sum += a[i];
				else b = a[i];
			}
			if(c[i] == true)
			{
				if(r == 0) r = a[i];
				else if(r != 0 && a[i] == r) sum += a[i];
				else r = a[i];
			}
		}
		ans = max(ans, sum);
		return;
	}
	c[num] = true;
	dfs(num+1);
	c[num] = false;
	dfs(num+1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dfs(1);
		printf("%lld\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
