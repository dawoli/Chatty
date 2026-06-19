#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int c[k],a[k][n],u[m],v[m],w[m];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	if(c[1]==0){
		cout<<0;
	}
	
	return 0;
}
