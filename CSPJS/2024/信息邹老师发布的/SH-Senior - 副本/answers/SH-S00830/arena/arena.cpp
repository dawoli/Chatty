#define I using
#define love namespace
#define Poncirus_forever std

	I love Poncirus_forever;

#include<cstdio>
#define ll long long
#define in(x) scanf("%d",&x)
const ll N=1e5+5;
int n,m,T,a[N],c[N];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	in(n),in(m);
	for(ll i=1;i<=n;i++) in(a[i]);
	for(ll j=1;j<=m;j++) in(c[j]);
	ll k;
	for(k=0;(1<<k)<n;k++) m=m;
	
	for(ll i=1;i<=k;i++) in(T);
	in(T);
	while(T--)
	{
		ll x[4];
		for(ll i=1;i<4;i++) in(x[i]);
		for(ll i=1;i<=n;i++) a[i]^=x[i%4];
		ll ans=0;
		for(ll f=1;f<=m;f++)
		{
			ll res=0;
			for(ll i=1;i<=c[f];i++) res+=a[i];
			ans^=res*f;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

*/

