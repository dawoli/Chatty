#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 510
ll n,m,cnt,unc,ans,cn,c[N];
char ch;
bool b[N],x[N];
void dfs(ll dep,ll unc,ll cnt)
{
	if(dep == n+1)
	{
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(!x[i])
		{
			x[i] = 1;
			dfs(dep+1,unc+((unc>=c[i] || b[dep] == 0)?1:0),cnt+((unc>=c[i] || b[dep] == 0)?0:1));
			x[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>ch;
		b[i] = (ch == '1');
	}
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld",&c[i]);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}
