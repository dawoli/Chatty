#include <bits/stdc++.h>
#define N 10004
#define M 1000006
using namespace std;
struct ed{
	int u,v;
	long long w;
	bool operator < (ed x) const {
		return w<x.w;
	}
}edge[M];
int n,m,k,id[N];
long long c[11],a[11][N];
int find(int x){
	if(x==id[x]) return x;
	return id[x]=find(id[x]);
}
long long ans;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	sort(edge+1,edge+m+1);
	for(int i=1;i<=m;i++){
		int x=find(edge[i].u);
		int y=find(edge[i].v);
		if(x!=y){
			id[x]=y;
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	return 0;
} 
