#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],p[100005];
bool vis[100005],vis2[100005];
bool Is_condition2()
{
	for(ll i = 1;i <= n;i++)
	{
		if(a[i] > 2)
		{
			return 0;
		}
	}
	return 1;
}
void input()
{
	cin>>n;
	for(ll i = 1;i <= n;i++)
	{
		cin>>a[i];
		p[a[i]] += 1;
	}
}
void solve1()
{
	for(ll i = 1;i <= n;i++) vis[i] = vis2[i] = 0;
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n;i++)
	{
		ll cur = i;
		while(cur + 1 <= n && (vis[cur] || a[cur] <= a[i]))
		{
			cur += 1;
		}
		if(!vis[cur] && a[cur] > a[i])
		{
			vis[cur] = 1;
			vis2[i] = 1;
		}
	}
	ll ans = 0;
	for(ll i = 1;i <= n;i++)
	{
//		cout<<i<<endl;
		if(!vis2[i])
		{
//			cout<<" "<<endl;
			ans += 1;
		}
	}
	cout<<ans<<endl;
}
void solve2()
{
	ll cnt1 = 0,cnt2 = 0;
	for(ll i = 1;i <= n;i++)
	{
		if(a[i] == 1) cnt1 += 1;
		else cnt2 += 1;
	}
//	cout<<cnt1<<" "<<cnt2<<endl;
	cout<<max(cnt1,cnt2)<<endl;
}
void solve()
{
	for(ll i = 1;i <= n;i++) vis2[i] = 0;
	sort(a + 1,a + n + 1);
	for(ll i = 1;i <= n;i++)
	{
		ll cur = i + p[a[i]];
		if(cur > n) break;
		vis2[i] = 1;
	}
	ll ans = 0;
	for(ll i = 1;i <= n;i++)
	{
//		cout<<i<<endl;
		if(!vis2[i])
		{
//			cout<<" "<<endl;
			ans += 1;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input();
	if(n * n <= 1e8) solve1();
	else if(Is_condition2()) solve2();
	else solve();
	return 0;
}
