#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 5005
#define mod 998244353
map<string ,bool> m;
ll n,a[N],ans,maxt;
bool b[N];
void dfs(ll d,ll s,ll maxt,string st,ll ls)
{
	if(s > (maxt<<1) && m.find(st) == m.end())
	{
		ans = (ans+1) % mod;
		m[st] = 1;
	}
	if(d == n+1 || ls == n) return;
	for(int i = ls+1 ; i <= n ; i++)
	{
		if(!b[i])
		{
			b[i] = 1;
			string s1 = " ";
			ll x = i;
			while(x)
			{
				s1 = (char)(x%10+'0') + s1;
				x /= 10;
			}
			dfs(d+1,s+a[i],((a[i]>maxt)?(a[i]):(maxt)),st+s1,i);
			b[i] = 0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	dfs(1,0,0,"",0);
	printf("%lld\n",ans);
	return 0;
}
