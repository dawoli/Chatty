#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
};
vector<edge>e;
int n,m,k;
int fa[10010];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e.push_back({i,j,w});
		}
	}
	sort(e.begin(),e.end(),cmp);
	int mstl=0;
	int c=0;
	for(int i=0;i<e.size();i++){
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		int ru=find(u),rv=find(v);
		if(ru==rv)continue;
		mstl+=w;
		fa[ru]=rv;
		c++;
		if(c==n-1)break;
	}
	cout<<mstl<<endl;
	return 0;
}
