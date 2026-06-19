#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100105],x[305][5],c[100005],t,p[100005],nw[100005],f[100005];
bool d[1005][1005];
void input()
{
	cin>>n>>m;
	for(ll i = 1;i <= n;i++) cin>>a[i];
	for(ll i = 1;i <= m;i++) cin>>c[i];
	ll cur = 0;
	p[0] = 1;
	while(p[cur] < n)
	{
		cur += 1;
		p[cur] = p[cur - 1] * 2;
	}
	if(p[cur] > n)
	{
		for(ll i = n + 1;i <= p[cur];i++) a[i] = 2e31 - 1;
	}
	for(ll i = 1;i <= cur;i++)
	{
		string s;
		cin>>s;
		for(ll j = 0;j < s.size();j++)
		{
			d[i][j] = (s[j] - '0');
		}
	}
	cin>>t;
	for(ll i = 1;i <= t;i++) cin>>x[i][0]>>x[i][1]>>x[i][2]>>x[i][3];
}
ll P(ll x)
{
	ll cur = 0;
	p[0] = 1;
	while(p[cur] < x)
	{
		cur += 1;
		p[cur] = p[cur - 1] *2;
	}
	return cur;
}
void solve1()
{
	for(ll i = 1;i <= t;i++)
	{
		ll ans = 0;
		for(ll j = 1;j <= m;j++)
		{
			a[j] ^= x[i][j % 4];
			for(ll x = 1;x <= P(j);x++)
			{
				for(ll y = 1;y * 2 <= j;y++)
				{
					if(x == 1) f[y] = y;
					ll now = f[y] * 2 - 1,now2 = f[y] * 2;
					if(d[x][y] == 0)
					{
						if(a[now] >= x) f[y] = now;
						else f[y] = now2;
					}
					else
					{
						if(a[now2] >= x) f[y] = now2;
						else f[y] = now;
					}
				}
			}
//			cout<<f[1]<<" ";
			nw[j] = a[f[1]];
		}
//		cout<<endl<<endl;
		for(ll j = 1;j <= m;j++)
		{
			if(j == 1) ans = nw[c[j]] * j;
			else ans ^= nw[c[j]] * j;
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	input();
	solve1();
	return 0;
}
