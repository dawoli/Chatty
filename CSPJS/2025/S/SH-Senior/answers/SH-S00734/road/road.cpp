#include<bits/stdc++.h>
#define int long long
using namespace std;
int minn=INT_MAX,n,m,k,sum;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
		minn=min(minn,w);
	}
	cout<<sum-minn;
	return 0;
} 
