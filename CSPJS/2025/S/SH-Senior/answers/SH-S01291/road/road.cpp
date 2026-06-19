#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N][N][N];
int main(){ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;k<=m;j++){
			for(int t=1;t<=k;t++){
				cin>>a[i][j][k];
			}
		}
	}
	return 0;
} 
