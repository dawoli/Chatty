#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+9;
const ll S=1e6+9;
ll f[N],T,n,a[N],g[N],cnt[S];
vector<ll>num[S];
void MAIN()
{
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)num[a[i]].push_back(i);
	for(ll i=1;i<=n;i++)
	{
		if(cnt[a[i]]==0)g[i]=0;
		else g[i]=num[a[i]][cnt[a[i]]-1];
		cnt[a[i]]++;
	}
	f[0]=0;ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		if(g[i]==0)f[i]=0;
		else f[i]=f[g[i]]+a[i];
	}
	for(ll i=1;i<=n;i++)num[a[i]].clear(),cnt[a[i]]=0;
	for(ll i=1;i<=n;i++)ans+=f[i];
	cout<<ans<<endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	cin>>T;
	while(T--)MAIN();
	return 0;
}
