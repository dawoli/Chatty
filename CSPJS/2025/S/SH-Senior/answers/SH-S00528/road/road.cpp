#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int x[1000006];
int y[1000006];
int z[1000006];
int c[105];
int a[13][10004];
int vis[14];
struct edge{
	int v,w;
};
struct node{
	int u,v,w;
	bool operator<(const node &a) const{
		return w<a.w;
	}
};
set<node> s;
vector<edge> g[10004];
int cnt;
int fa[10015];
int ans=1e15;
int anc(int x){
	int y=x;
	while(x!=fa[x]){
		x=fa[x];
	}
	fa[y]=x;
	return x;
}
int kruskal(){
	int tot=0;
	while(cnt!=1){
		node cur=*s.begin();
		if(anc(cur.u)!=anc(cur.v)){
			tot+=cur.w;
			fa[fa[cur.v]]=fa[cur.u];
			cnt--;
		}
		s.erase(s.begin());
	}
	return tot;
}
void init(int step){
	if(step>k){
		cnt=n;
		int tot=0;
		for(int j=1;j<=n;j++){
			fa[j]=j;
		}
		s.clear();
		for(int j=1;j<=m;j++){
			s.insert(node{x[j],y[j],z[j]});
		}
		for(int i=1;i<=k;i++){
			if(vis[i]==1){
				fa[n+i]=n+i;
				cnt++;
				tot+=c[i];
				for(int j=1;j<=n;j++){
					s.insert(node{n+i,j,a[i][j]});
				}
			}
		}
		ans=min(kruskal()+tot,ans);
		return;
	}
	vis[step]=0;
	init(step+1);
	vis[step]=1;
	init(step+1);
	return;
}
int p[105];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		g[x[i]].push_back({y[i],z[i]});
		g[y[i]].push_back({x[i],z[i]});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	init(1);
	cout<<ans<<endl;
	return 0;
}

