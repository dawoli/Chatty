#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k;
vector<int> to[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		to[u].push_back(v);
		to[v].push_back(u);
		w[u].push_back(c);
		w[v].push_back(c);
	}
	
	return 0;
}

