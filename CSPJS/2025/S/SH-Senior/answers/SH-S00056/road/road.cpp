#include<iostream>
using namespace std;
int n,m,k;
int u[1000010],v[1000010],w[1000010],c[20],a[20][10010];
int vis[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		int minn=w[i];
		int minni=0;
		for(int j=1;j<=k;j++){
			if(minn>=a[j][u[i]]+a[j][v[i]]+(1-vis[j])*c[j]){
				minn=a[j][u[i]]+a[j][v[i]]+(1-vis[j])*c[j];
				minni=j;
			}
		}
		vis[minni]=1;
		ans+=minn;
		cout<<minn<<endl;
	}
	cout<<ans<<endl;
}
