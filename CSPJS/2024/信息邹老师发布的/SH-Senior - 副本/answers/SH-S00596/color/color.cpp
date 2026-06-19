#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[200005],ans;
void input()
{
	cin>>n;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
}
void dfs(bool op,ll pos,ll lst0,ll lst1,ll cnt)
{
	if(pos == n + 1)
	{
		ans = max(ans,cnt);
		return;
	}
	if(op)
	{
		if(lst1 != 0 && a[lst1] == a[pos]) cnt += a[pos];
		dfs(1,pos + 1,lst0,pos,cnt);
		dfs(0,pos + 1,lst0,pos,cnt);
	}
	else
	{
		if(lst0 != 0 && a[lst0] == a[pos]) cnt += a[pos];
		dfs(1,pos + 1,pos,lst1,cnt);
		dfs(0,pos + 1,pos,lst1,cnt);
	}
}
void solve1()
{
	ans = 0;
	dfs(1,1,0,0,0);
//	dfs(0,1,0,0,0);
	cout<<ans<<endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		input();
		if(n <= 15) solve1();
		else cout<<0<<endl;
	}
	return 0;
}
