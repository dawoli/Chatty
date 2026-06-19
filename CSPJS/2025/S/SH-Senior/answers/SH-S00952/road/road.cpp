#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
} ed[1000009];
int f[1000009];
bool cmp(node x,node y){
	return x.w<y.w;
}
int findfa(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=findfa(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>ed[i].u>>ed[i].v>>ed[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int qqq;
			cin>>qqq;
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	sort(ed+1,ed+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		f[ed[i].u]=findfa(ed[i].u),f[ed[i].v]=findfa(ed[i].v);
		if(f[ed[i].u]!=f[ed[i].v]){
			f[f[ed[i].u]]=f[ed[i].v];
			ans+=ed[i].w;
		}
	}
	cout<<ans;
	return 0;
}
