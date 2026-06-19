#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10009;
vector<pair<int,int> > to[N];
int n,m,k;
int c[11],a[11][N];
void solve0(){
	dfs(1);
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back(make_pair(v,w));
		to[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	if(k==0) solve0();
	return 0;
}

