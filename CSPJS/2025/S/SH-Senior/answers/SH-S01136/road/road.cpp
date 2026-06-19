#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+9;
const ll M=1e6+9;
struct Edge{
	ll u,v,w;
};
Edge e[M*2];
ll n,m,k,c[11],a[11][N],id[N],ans,cnt,pos[11],state[11];
bool cmp(const Edge&a,const Edge&b){
	return a.w<b.w;
}
ll root(ll u){
	if(id[u]==u) return u;
	return id[u]=root(id[u]);
}
void Kruskal(){
	for(ll i=1;i<=n;i++) id[i]=i;
		sort(e+1,e+m+1,cmp);
		for(ll i=1;i<=m;i++){
			ll ru=root(e[i].u),rv=root(e[i].v);
			if(ru!=rv){
				id[ru]=rv;
				ans+=e[i].w;
				cnt++;
				if(cnt==n-1) break;
			}
		}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++) scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	if(k==0){
		Kruskal();
	}
	else{//A
		for(ll j=1;j<=k;j++){
			for(ll i=1;i<=n;i++)
				if(a[j][i]==0){
					pos[j]=i;
					break;
				}
			for(ll i=1;i<=n;i++){
				if(i==pos[j]) continue;
				e[++m]=(Edge){pos[j],i,a[j][i]};
			}
		}
		Kruskal();
	}
	return 0;
} 
