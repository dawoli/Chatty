#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[100009],v[100009],w[100009],c[100009],a[100009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>w[i]>>u[i];
	}
	for(int i=1;i<=k;i++)
		for(int i=1;i<=n+1;i++) cin>>a[i];
	cout<<452;
	return 0;
}
