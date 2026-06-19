#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10004][10004];
int ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=0;
			a[j][i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c[i];
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			
		}
	}
	
	cout<<ans<<endl;
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
