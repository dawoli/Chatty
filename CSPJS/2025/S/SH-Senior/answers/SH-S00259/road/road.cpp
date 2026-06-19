#include<bits/stdc++.h>
using namespace std;
void file(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
typedef long long ll;
ll c[15],n,m,k,nE; 
struct Edge{
	ll u,v,w;
	bool operator<(const Edge&a)const{return w<a.w;}
}e[1100005];
ll id[1015];
ll root(ll x){return x==id[x]?x:id[x]=root(id[x]);}
ll kruskal(ll V,ll E){
	sort(e+1,e+1+E);
	ll res=0,cnt=0;
	for(ll i=1;i<=V;i++)id[i]=i;
	for(ll i=1;i<=E;i++){
		ll ru=root(e[i].u);
		ll rv=root(e[i].v);
		if(ru==rv)continue;
		id[ru]=rv;
		res+=e[i].w;
		if(++cnt>=V-1)break;
	}
	return res;
}
bool spA=1;
int main(){
	file();
	scanf("%d%d%d",&n,&m,&k);
	for(ll i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	nE=m;
	for(ll i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(ll j=1;j<=n;j++){
			++nE;
			e[nE].u=n+i,e[nE].v=j;
			scanf("%d",&e[nE].w);
		} 
	}
	for(ll i=1;i<=k&&spA;i++){
		if(c[i]!=0)spA=0;
		bool is0=0;
		for(ll j=1;j<=n&&is0==0;j++){
			ll iE=m+(i-1)*n+j;
			if(e[iE].w==0)is0=1;
		}
		if(is0==0)spA=0;
	}
	if(spA)printf("%d",kruskal(n+k,nE));
	return 0;
}
