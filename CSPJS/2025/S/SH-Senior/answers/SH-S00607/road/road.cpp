#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct NODE{
	long long u,v,w;
};
bool cmp(NODE a,NODE b){
	return a.w<b.w;
}
vector<NODE>edge;
long long c[15],a[15][10010];
long long fa[10010];
long long find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		edge.push_back({u,v,w});
	}
	long long A=0;
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		A|=c[i];
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			A|=a[i][j];
		}
	}
	if(k==0){
		for(long long i=1;i<=n;i++)fa[i]=i;
		long long ans=0;
		for(auto pos:edge){
			long long u=pos.u;
			long long v=pos.v;
			long long w=pos.w;
			if(find(u)!=find(v)){
				ans+=w;
				fa[find(u)]=find(v);
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(A==0){
		printf("0\n");
		return 0;
	}
}
