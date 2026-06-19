#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+9;
long long n,m,k,ans,c[N],fa[N];
struct Node{
	long long u,v,w;
};
Node eg1[N],eg2[N];
long long find_fa(long long a){
	if(fa[a]==a) return a;
	return fa[a]=find_fa(fa[a]);
}
void init(){
	for(long long i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
bool vst[200];
long long num;
long long krus(long long na){
	init();
	long long cnt=0,tot=0,tp1=1,tp2=1,nu,nv,nw,fu,fv;
	for(long long i=1;i<=k;i++){
		if(vst[i]==1) cnt+=c[i];
	}
	while(tot<n+na-1){
		while(tp2<=n*k&&(vst[eg2[tp2].u-n]==0)){
			tp2++;
		}
		if(eg1[tp1].w<eg2[tp2].w){
			nu=eg1[tp1].u;
			nv=eg1[tp1].v;
			nw=eg1[tp1].w;
			tp1++;
		}
		else{
			nu=eg2[tp2].u;
			nv=eg2[tp2].v;
			nw=eg2[tp2].w;
			tp2++;
		}
		fu=find_fa(nu),fv=find_fa(nv);
		if(fu!=fv){
			cnt+=nw;
			fa[fu]=fv;
			tot++;
		}
	}
	return cnt;
}
void dfs(long long now,long long ddd){
	if(now==k+1){
		ans=min(ans,krus(ddd));
		return;
	}
	dfs(now+1,ddd);
	vst[now]=1;
	dfs(now+1,ddd+1);
	vst[now]=0;
}
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(vst,0,sizeof(vst));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&eg1[i].u,&eg1[i].v,&eg1[i].w);
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++){
			eg2[(i-1)*n+j].u=n+i;
			eg2[(i-1)*n+j].v=j;
			scanf("%lld",&eg2[(i-1)*n+j].w);
		}
	}
	sort(eg1+1,eg1+m+1,cmp);
	sort(eg2+1,eg2+k*n,cmp);
	eg1[m+1].w=1e15;
	eg2[k*n+1].w=1e15;
	ans=1e18;
	dfs(1,0);
	cout<<ans;
	return 0;
}
