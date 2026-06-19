#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int g[10004][10004];
bool in[10004],f;
bool check() {
	for(int i=1;i<=n;i++) {
		if(!in[i]) return false;
	}
	return true;
}
void dfs(int u,int step) {
	int v,w=1e10;
	if(f) return;
	in[u]=1;
	if(check()) {
		cout<<step;
		f=1;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(in[i]) {
			for(int j=1;j<=n;j++) {
				if(w>g[i][j]) {
					if(!in[j]) {
						w=g[i][j];
						v=j;
					}
				}
			}
		}
	}
	dfs(v,step+w);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	for(int x=1;x<=k;x++) {
		int c;
		cin>>c;
		int a[n+1];
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n;i++) {
			for(int j=i;j<=n;j++) {
				g[i][j]=min(g[i][j],c+a[i]+a[j]);
				g[j][i]=min(g[j][i],c+a[i]+a[j]);
			}
		}
	}
	dfs(1,0);
	return 0;
}
