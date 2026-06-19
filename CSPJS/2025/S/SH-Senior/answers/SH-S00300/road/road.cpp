#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,t[10012][10012],c[12];
long long ans=1e18,s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		t[u][v]=w;
		t[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
//		/*
		s=0;
		for(int j=1;j<=n;j++){
			cin>>w;
			t[i+n][j]=w;
			t[j][i+n]=w;
			s+=w;
		}
		ans=min(ans,s);
//		*/
	}
	cout<<ans;
	return 0;
}
