#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e4+1e1+5;
int n,m,k;
int ans;
int fa[MAXN];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
priority_queue<pair<int,pair<int,int> > > q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q.push(make_pair(-w,make_pair(u,v)));
	}
	while(!q.empty()){
		pair<int,pair<int,int> > edge=q.top();
		q.pop();
		int u=edge.second.first;
		int v=edge.second.second;
		int w=-edge.first;
		if(find(u)==find(v)) continue;
		ans+=w;
		merge(u,v);
	}
	cout<<ans<<endl;
	return 0;
}
