#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll a[4],st[4],mx[4],opp[4];
}p[1000100];
bool cmp(node x,node y)
{
	if (x.st[1] != y.st[1]) return x.st[1] > y.st[1];
	if (x.st[2] != y.st[2]) return x.st[2] > y.st[2];
	return x.mx[1] > y.mx[1];
}
void sor(ll x,ll y,ll z,ll i)
{
	ll c1 = max(x,max(y,z));
	p[i].mx[1] = c1;
	ll c3 = min(x,min(y,z));
	p[i].mx[3] = c3;
	ll c2 = x +y + z - c1 - c3;
	p[i].mx[2] = c2;
	p[i].st[1] = c1 - c2;
	p[i].st[2] = c2 - c3;
	for (ll k = 1;k <= 3;k++)
	for (ll j = 1;j <= 3;j++)
	{
		if (p[i].a[j] == p[i].mx[k])
		{
			p[i].opp[k] = j;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin >> t;
	while(t--)
	{
		memset(p,0,sizeof p);
		ll n;
		cin >> n;
		for (ll i = 1;i <= n;i++)
		{
			for (ll j = 1;j <= 3;j++)
			{
				cin >> p[i].a[j];
			}
			sor(p[i].a[1],p[i].a[2],p[i].a[3],i);
		}
		sort(p + 1,p + n + 1,cmp);
		ll ans = 0;
		ll cnt[4];
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (ll i = 1;i <= n;i++)
		{
			for (ll j = 1;j <= 3;j++)
				if (cnt[p[i].opp[j]] < n / 2)
				{
					ans += p[i].mx[j];
					cnt[p[i].opp[j]]++;
					break;
				}
		}
		cout << ans << endl;
	}
	return 0;
 } 
