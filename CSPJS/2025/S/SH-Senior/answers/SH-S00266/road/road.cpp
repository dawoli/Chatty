#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,c[15],a[15][10010],f[11451];
struct edge{
	ll u,v,w,ci;
};
vector<edge> e;
ll getroot(ll x){
	if(f[x]==x)return x;
	return f[x]=getroot(f[x]);
}
void merge(ll x,ll y){
	ll rx=getroot(x),ry=getroot(y);
	f[rx]=ry;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w,0});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++)e.push_back({n+i,j,a[i][j],i});
	}
	sort(e.begin(),e.end(),cmp);
	ll mincost=LLONG_MAX;
	for(ll x=0;x<(1<<k);x++){
		ll cost=0,cntn=n-1;
		for(ll i=1;i<=k;i++){
			if(x&(1<<(i-1))){
				cost+=c[i],cntn++;
			}
		}
		for(ll i=1;i<=n+k;i++)f[i]=i;
		
		for(ll i=0;i<e.size();i++){
			if((x&(1<<(e[i].ci-1))||e[i].ci==0)&&getroot(e[i].u)!=getroot(e[i].v)){
				merge(e[i].u,e[i].v);
				cost+=e[i].w;cntn--;
				if(cntn==0)break;
			}
		}
		if(cost<mincost)mincost=cost;
	}
	cout <<mincost<<endl;
	return 0;
}
