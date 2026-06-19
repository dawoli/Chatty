#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5,mod = 998244353;
int a[N],ans,n;
void dfs(int i,int maxn,int sum)
{
	if(i > n)
	{
		if(sum > maxn * 2)
			ans = (ans + 1) % mod;
		return;
	}
	dfs(i + 1,max(maxn,a[i]),sum + a[i]);
	dfs(i + 1,maxn,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
