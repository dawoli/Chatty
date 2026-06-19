#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int u;
			cin>>u;
			c+=u;
		}
		ans=min(ans,c);
	}
	cout<<ans;
	return 0;
}
