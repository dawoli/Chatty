#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int f[1009][1009];
struct node{
	int fee;
	int each[1000009];
} p[19];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		f[u][v]=c;
		f[v][u]=c; 
	}
	int ans=0;
	int best=0;
	bool flag=0;
	for(int i=1;i<=k;i++){
		ans=0;
		cin>>p[i].fee;
		ans+=p[i].fee;
		for(int j=1;j<=n;j++) {cin>>p[i].each[j]; ans+=p[i].each[j];}
		if(flag)best=min(best,ans);
		else {
			best =ans;
			flag=1;
		}
	}
	cout <<best<<endl;
	return 0;
}
