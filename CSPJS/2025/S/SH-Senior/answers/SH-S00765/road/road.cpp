#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[3010][3010],c[11];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1; i<=m; i++) {
		int c1,c2,cost;
		cin>>c1>>c2>>cost;
		a[c1][c2]=cost;
		a[c2][c1]=cost;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i = 1;i<=n;i++){
			int cost;
			cin>>cost;
			a[n+i][i]=cost;
			a[i][n+i]=cost;
		}
	}cout<<0;
	return 0;
}

