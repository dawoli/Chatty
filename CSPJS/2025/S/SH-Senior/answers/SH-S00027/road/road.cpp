#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e4+5;
struct Edge{
	int u,v,w;
}e[N];
int n,m,k,c,a,fa[N],ans;

bool cmp(Edge x,Edge y){
	return x.w<y.w;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++) cin>>a;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		int x=find(e[i].u),y=find(e[i].v);
		fa[x]=y;
		ans+=e[i].w;
	}
	cout<<ans;
	return 0;
}
