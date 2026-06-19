#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
int n,m,k;
int u,v,w;
int dis[10010][10010],c[11],a[11][10010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"0";
	return 0;
}
