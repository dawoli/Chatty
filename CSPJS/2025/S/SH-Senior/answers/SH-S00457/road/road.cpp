#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
}

