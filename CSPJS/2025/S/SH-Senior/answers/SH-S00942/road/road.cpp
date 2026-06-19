#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10010;
struct node{
	int v,w;
}; 
int n,m,k;
vector<node> e[N];
signed main(){
	freopen("read.in","r",stdin);
	freopen("read.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		int c;
		cin>>c;
		for(int j=1;j<n;++j){
			int a;
			cin>>a;
		}
	}
	return 0;
}
