#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10,K=10+10;
int u[M],v[M],w[M];
int c[K];
int a[k][N]; 
int main(){
	freopen("road.in","v",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
