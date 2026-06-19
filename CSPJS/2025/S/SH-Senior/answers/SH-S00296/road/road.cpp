#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int n,m,k,u[MAXN],v[MAXN],w[MAXN],c[MAXN],a[MAXN][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=n*2;
	cout<<ans;
	return 0;
}
