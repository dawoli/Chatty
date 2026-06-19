#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
	operator <(edge other){
		return w<other.w;
	}
};
int n,m,k,u,v,w,c[11],a[11][10005];
vector<edge> pq,gr;
int fa[10005];
int getfa(int x){
	if(x==fa[x]){
		return x;
	}
	else{
		return fa[x]=getfa(fa[x]);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		pq.push_back(edge({u,v,w}));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i<j)pq.push_back(edge({i,j,a[i][j]}));
			else pq.push_back(edge({j,i,a[i][j]}));
		}
	}
	
	sort(pq.begin(),pq.end());

	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<pq.size();i++){
		if(getfa(pq[i].u)==getfa(pq[i].v))continue;
		gr.push_back(pq[i]);
		fa[getfa(pq[i].v)]=getfa(pq[i].u);
	}
	
	int ans=0;
	for(int i=0;i<gr.size();i++){
		ans+=gr[i].w;
		cout<<gr[i].u<<" "<<gr[i].v<<" "<<gr[i].w<<endl;
	}
	cout<<ans;
} 
