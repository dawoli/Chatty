#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,inf=1e9,M=2e6+10,MOD=998244353;
int n,m,k;
struct node{
	int u,v,d;
} e[M];
bool cmp(node a,node b){
	return a.d<b.d;
}
int p[N];
int find(int u){
	if(p[u]!=u)	p[u]=find(p[u]);
	return p[u];
}
int c[15][N];
int equ[15];
int ans=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,d;
			scanf("%lld %lld %lld",&u,&v,&d);
			e[i]={u,v,d};
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,d=e[i].d;
			if(find(u)==find(v))	continue;
			p[u]=p[v];
			ans+=d;
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=m;i++){
			int u,v,d;
			scanf("%lld %lld %lld",&u,&v,&d);
			e[i]={u,v,d};
		}
		for(int i=1;i<=k;i++){
			int ff;
			scanf("%lld",&ff);
			for(int u=1;u<=n;u++){
				scanf("%lld",&c[i][u]);
				if(c[i][u]==0)	equ[i]=u;
			}
		}
		for(int i=1;i<=k;i++){
			for(int v=1;v<=n;v++){
				if(v==equ[i])	continue;
				e[++m]={equ[i],v,c[i][v]};
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,d=e[i].d;
			if(find(u)==find(v))	continue;
			p[u]=p[v];
			ans+=d;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
