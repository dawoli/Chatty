#include <bits/stdc++.h>
using namespace std;
int t;
int f[10100];
struct node {
	long long p,w;
};
vector<node>N[10100];
map<int,node>mp;
bool vis[10100];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++){
		long long x,y,w;
		cin>>x>>y>>w;
		N[x].push_back({y,w});
		N[y].push_back({x,w});
	}
	for(int i=0;i<n;i++){
		
	}
	if(k==0){//%20
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
