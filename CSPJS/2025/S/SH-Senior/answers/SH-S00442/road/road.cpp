#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,M=1e4+5,K=15;
ll n,m,k,d[K],c[K],tot[K];
pair<ll,ll> a[K][M];
ll f[K+M];
struct Node{
	ll u,v,w;
}edges[N];
ll ans,sm[K];
ll Find(ll x){
	if(f[x]==x)return x;
	return f[x]=Find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j].first;
			a[i][j].second=j;
		}
		sort(a[i]+1,a[i]+n+1);
		a[i][1].first+=c[i];
		tot[i]=1;
	}
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	sort(edges+1,edges+m+1,[&](Node x,Node y){
		return x.w<y.w;
	});
	for(int i=1;i<=m;i++){
		int fu=Find(edges[i].u),fv=Find(edges[i].v);
		for(int j=1;j<=k;j++){
			while(tot[j]<=n && a[j][tot[j]].first<edges[i].w){
				int fuu=Find(a[j][tot[j]].second),fvv=Find(n+j);
				if(fuu!=fvv){
					f[fuu]=fvv;
					d[j]++;
					sm[j]+=a[j][tot[j]].first;
					ans+=a[j][tot[j]].first;
				}
				tot[j]++;
			}
		}
		if(fu==fv)continue;
		f[fu]=fv;
		ans+=edges[i].w;
	}
	for(int i=n+1;i<=n+k;i++){
		if(d[i-n]==1)ans-=sm[i-n];
	}
	cout<<ans<<'\n';
	return 0;
}
