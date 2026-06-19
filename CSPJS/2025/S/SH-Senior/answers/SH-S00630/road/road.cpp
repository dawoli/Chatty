#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10025],c[20][10005],cnt[20];
long long ans=9e18;
bool vis[10025];
struct Edge{
	long long u,v,w;
}a[1200005];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
long long krus(){
	long long ans=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n+k;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i){
		//cerr<<"u,v,w="<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<endl;
		if(vis[a[i].u]&&vis[a[i].v]&&find(a[i].u)!=find(a[i].v)){
			ans+=a[i].w;
			fa[fa[a[i].u]]=fa[a[i].v];
			//cerr<<"choosed road #"<<i<<endl;
		}
//		else{
//			if(vis[a[i].u]&&vis[a[i].v])
//				//cerr<<"skipped road #"<<i<<" by already connected"<<endl;
//			else if(!vis[a[i].u]) 
//				//cerr<<"skipped road #"<<i<<" by u error"<<endl; 
//			else cerr<<"skipped road #"<<i<<" by v error"<<endl; 
//		}
	}
	return ans;
}
void dfs(int step,int foc){
	if(step>k){
		//debug++;
		//cerr<<"krusing in time "<<debug<<" of "<<(1<<k)<<endl;
		long long tmp=krus();
		ans=min(ans,tmp+foc);
		//cerr<<"ans="<<ans<<" in foc="<<foc<<" and krus="<<tmp<<endl;
		return;
	}
	dfs(step+1,foc);
	vis[n+step]=1;
	dfs(step+1,foc+c[step][0]);
	vis[n+step]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>a[i].u>>a[i].v>>a[i].w;
	//Test Case 1-4
	if(k==0){
		cout<<krus();
	}
	else{
		int maxc=0;
		for(int i=1;i<=k;++i){
			cin>>c[i][0];
			for(int j=1;j<=n;++j){
				cin>>c[i][j];
				a[++m]={n+i,j,c[i][j]};
			}
			maxc=max(maxc,c[i][0]);
		}
		for(int i=1;i<=n;++i)
			vis[i]=1;
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}

