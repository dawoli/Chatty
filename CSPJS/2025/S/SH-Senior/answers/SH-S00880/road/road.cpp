#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,a[10005][10005],c[10005],co[10005],vis[10005][10005];
queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,v;
		cin>>x>>y>>v;
		a[x][y]=v;
		a[y][x]=v;
		ans+=v;
	}
	cout<<ans;
	return 0;
} 
