#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct Edge{
	int u,w;
};
vector<Edge> g[10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
	}
	cout<<cnt;
	return 0;
}
