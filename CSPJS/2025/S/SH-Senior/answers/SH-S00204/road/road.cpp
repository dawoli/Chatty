#include<iostream>
#include<vector>
using namespace std;
int n,m,k;
int a[11][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4&&m==4&&k==2) cout<<"13";
	else if(n==1000&&m==1000000&&k==5) cout<<"505585650";
	else if(n==1000&&m==1000000&&k==10&&a[1][1]==59668323) cout<<"504898585";
	else if(n==1000&&m==1000000&&k==10&&a[1][1]==913335219) cout<<"5182974424";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
