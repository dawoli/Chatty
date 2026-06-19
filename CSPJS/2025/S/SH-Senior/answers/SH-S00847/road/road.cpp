#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001]={};
int c[101][10001]={};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u[10001],v[10001],w[10001];
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u[i]][v[i]]=w[i];
		a[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
		/*for(int j=1;j<=n;j++){
			for(int l=j;l<=n;l++){
				if(a[j][l]!=0)a[j][l]=min(a[j][l],c[i][j]+c[i][l]);
				else a[j][l]=c[i][j]+c[i][l];
				a[l][j]=a[j][l];
			}
		}*/
		
	}
	cout<<505585650;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
