#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[10005],c[15];
struct edge{
	ll u,v,w,f;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
}e[2000005];
ll nE;
ll ok[15],p[10005];
ll root(ll u){
	return ((u==p[u])?u:(p[u]=root(p[u])));
}
ll solve(ll s){
	fill(ok,ok+k+1,0);
	ok[0]=1;
	ll cntk=0,ans=0;
	for(ll i=1;i<=k;i++){
		if((s>>(i-1))&1){
			ok[i]=1;
			cntk++;
			ans+=c[i];
		}
	}
	for(ll i=1;i<=n+k;i++){
		p[i]=i;
	}
	ll cnt=0;
	for(ll i=1;i<=nE;i++){
		if(!ok[e[i].f]){
			continue;
		}
		ll ru=root(e[i].u),rv=root(e[i].v);
		if(ru!=rv){
			//cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
			p[ru]=rv;
			ans+=e[i].w;
			cnt++;
			if(cnt==n+cntk){
				break;
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		if(e[i].u>e[i].v){
			swap(e[i].u,e[i].v);
		}
		e[i].f=0;
	}
	nE=m;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[j];
		}
		for(ll j=1;j<=n;j++){
			e[++nE]=(edge){j,n+i,a[j],i};
		}
	}
	sort(e+1,e+nE+1);
	ll ans=1e18;
	for(ll s=0;s<(1<<k);s++){
		ans=min(ans,solve(s));
	}
	cout<<ans;
	return 0;
}

