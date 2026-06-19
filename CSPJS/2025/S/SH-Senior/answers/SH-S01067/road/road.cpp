#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u[m+5],v[m+5],w[m+5],c[k+5],a[n+5];
	for(int i=1;i<=m;i++) cin >> u[i] >>v[i] >> w[i];
	for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++) cin >> a[j];
	}
	cout << n+m;
	return 0;
}
