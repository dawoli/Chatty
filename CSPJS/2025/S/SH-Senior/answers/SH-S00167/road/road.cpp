#include <bits/stdc++.h>
using namespace std;
 
int n,m,k;
long long x[10005][10005],cost[15],dp[1005][1005],y[1005];
int main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			x[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		x[a][b]=c;
		x[b][a]=c;
	}
	for(int i=0;i<k;i++){
		cin>>cost[i];
		for(int j=0;j<n;j++){
			cin>>y[j][i];
		}
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
