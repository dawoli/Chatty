#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int l[5005];
int n;
void dfs(int ma,int sum,int now,int s)
{
	ans %= 998244353;
	int may = ma;
	if (sum > ma * 2 && s >= 3)
	{
		ans++;
	}
	for (int i = now+1;i < n;i++)
	{
		sum += l[i];
		ma = max(ma,l[i]);
		dfs(ma,sum,i,s+1);
		sum -= l[i];
		ma = may;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&l[i]);
	}
	sort(&l[0],&l[n-1]);
	for (int i = 0;i < (n-2);i++)
	{
		dfs(l[i],l[i],i,1);
	}
	printf("%d",ans);
	return 0;
}
