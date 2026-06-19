#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int start[m+1],end[m+1],cost[m+1];
	for(int i=1;i<=m;i++){
		cin>>start[i]>>end[i]>>cost[i];
	}
	int country[k+1];
	for(int i=1;i<=k;i++){
		cin>>country[i];
		int to_city[n+2];
		for(int j=1;j<=n;j++){
			cin>>to_city[j];
		}
	} 
	return 0;
}
