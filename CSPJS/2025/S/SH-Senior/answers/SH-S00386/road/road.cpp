#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=1e18,f[10019],sz[10019],a[19];
struct edge{long long u,v,w,k;};
vector<edge>e;
bool cmp(const edge&x,const edge&y){
	if(x.w!=y.w)return x.w<y.w;
	return x.k<y.k;
}
bool isbuild[19]={true};
long long find(long long x){return f[x]==x?x:f[x]=find(f[x]);}
void unite(long long u,long long v){
	long long fu=find(u),fv=find(v);
	if(sz[fu]>sz[fv])swap(fu,fv);
	f[fu]=fv;
	sz[fu]+=sz[fv];
}
void dfs(long long i,long long sum){
	if(i>k){
		for(long long i=1;i<=n+k;i++)f[i]=i,sz[i]=1;
		long long nd=n-1,cnt=0,ifuse[19]={},ccnt[19]={},cw[19]={};
		for(long long i=0;i<e.size();i++){
			edge now=e[i];
			if(!isbuild[now.k])continue;
			if(find(now.u)==find(now.v))continue;
			unite(now.u,now.v);
			cnt++;
			sum+=now.w;
			if(now.k>0){
				if(!ifuse[now.k]){
					nd++;
					ifuse[now.k]=1;
				}
				ccnt[now.k]++;
				cw[now.k]=now.w;
			}
			if(cnt>=nd)break;
		}
		for(long long i=1;i<=k;i++)
			if(ccnt[i]==1)
				sum-=cw[i]+a[i];
		ans=min(ans,sum);
		return;
	}
	dfs(i+1,sum);
	isbuild[i]=true;
	dfs(i+1,sum+a[i]);
	isbuild[i]=false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e.push_back({u,v,w,0});
	}
	for(long long i=1;i<=k;i++){
		long long u=n+i,w;
		scanf("%lld",&a[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&w);
			e.push_back({u,j,w,i});
		}
	}
	sort(e.begin(),e.end(),cmp);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
