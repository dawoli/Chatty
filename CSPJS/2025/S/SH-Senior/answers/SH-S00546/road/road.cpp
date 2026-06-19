#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[1000005][3];
	int b[15][10005];
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=m;i++){
	for(int j=1;j<=k;i++){
		a[i][3]=min(a[i][3],b[j][1]+b[j][a[i][1]]+b[j][a[i][2]]);
	}
	ans+=a[i][3];
	}
	cout<<ans;
	return 0;
}
