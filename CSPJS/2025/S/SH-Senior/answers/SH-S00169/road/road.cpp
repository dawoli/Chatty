#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	ll u,v,w;
};
ll n,m,k,c[15],a[15][10010],fa[10010],ans;
vector <node> g;
bool cmp(node x,node y){
	return (x.w<y.w);
}
ll find(ll x){
	if (fa[x]==x)  return x;
	else  return fa[x]=find(fa[x]);
}
void kruskal(){
	ll cnt=0;
	for (int i=1;i<=n+k;i++)  fa[i]=i;
	sort(g.begin(),g.end(),cmp);
	for (int i=0;i<g.size();i++){
		if (cnt==n+k-1)  return;
		ll u=g[i].u,v=g[i].v,w=g[i].w;
		if (find(u)!=find(v)){
			ans+=w;
			fa[find(v)]=find(u);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	ll u,v,w;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	bool flag=0;
	for (int i=1;i<=k;i++){
		cin>>c[i];
		if (c[i])  flag=1;
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
			if (a[i][j])  flag=1;
		}
	}
	if (!flag)
		for (int i=n+1;i<=n+k;i++)
			for (int j=1;j<=n;j++)
				g.push_back({i,j,0});
	kruskal();
	cout<<ans;
	return 0;
}
/*
4 5 0
1 2 1
1 3 4
3 4 3
2 3 2
2 4 100
*/
