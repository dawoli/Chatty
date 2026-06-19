#include<bits/stdc++.h>
using namespace std;
int to[1005][1005];
int main(){
 	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	int ans=10000009;
	int nans=0;
	if(k==0){
	//	cout << 1 << endl;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				to[i][j]=1000008;
			}
		}
		for(int i=1; i<=m; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			// cout << 1 << endl;
			to[a][b]=c;
			to[b][a]=c;
		}
	//	cout << 2 << endl;
		for(int u=1; u<=n; ++u){
			for(int v=1; v<=n && v!=u; v++){
				for(int k=1; k<=n && k!=u && k!=v; ++k){
					//cout << u << v << k << to[u][v];
					cout << u << endl;
					if(to[u][v]>=to[u][k]+to[k][v]){
						to[u][v]=to[u][k]+to[k][v];
					}
				}
			}
		}

		for(int i=1; i<=n; ++i){
			ans+=to[1][i];
		}
		cout << ans << endl;
		return 0;
	}
}
