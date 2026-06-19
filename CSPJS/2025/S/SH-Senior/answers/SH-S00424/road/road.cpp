#include<bits/stdc++.h>
using namespace std;
int u[100000001],v[100000001],w[10000001],c[1000005],a[5005][5005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
		ans+=w[i];
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
