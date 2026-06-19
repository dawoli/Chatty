#include<bits/stdc++.h>
#define Hatsune return
#define Miku 0
using namespace std;

typedef long long ll;
const int N=2e5+10,M=1e6+10;
const ll INF=1e18+10;

ll n,a[N],f[N],pre[N],tot[M],d[N],mx[N];

void solve()
{
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	memset(d,0,sizeof d);
	memset(tot,0,sizeof tot);
	memset(f,0,sizeof f);
	memset(mx,0,sizeof mx);
	for(ll i=1;i<=n;i++)
	{
		d[i]=d[i-1];
		if(a[i]==a[i-1]) d[i]+=a[i];
	}
	for(ll i=1;i<=n;i++) pre[i]=tot[a[i]],tot[a[i]]=i;
	for(ll i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) f[i-1]=mx[i-2]+a[i],mx[i-2]+=a[i];
		else
		{
			if(pre[i]) f[i-1]=max(a[i]+f[pre[i]]+(d[i-1]-d[pre[i]+1]),mx[i-2]);
			else f[i-1]=mx[i-2];
		}
		mx[i-1]=max(mx[i-2],f[i-1]);
	}
	cout<<mx[n-1]<<"\n";
}
	
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--) solve();
	Hatsune Miku;
}
