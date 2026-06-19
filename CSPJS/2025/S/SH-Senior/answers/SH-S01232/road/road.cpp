#include<bits/stdc++.h>
using namespace std;
int flagA,flagB;
int n,m,k;
int id[10001];
int c[11];
int a[11][10001];
int f[10001];
int find(int x){
	if(x==id[x]){
		return x;
	}
	else{
		return id[x]=find(id[x]);
	}
}
struct node{
	int u,v,w;
};
bool cmp(node a,node b){
	return a.w<b.w;
}
node g[2000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	if(k==0){
		int u,v,w;
		for(int i=1;i<=m;i++){
			cin>>u>>v>>w;
			g[i]={u,v,w};
		}
		sort(g+1,g+1+m,cmp);
		int sum=0;
		for(int i=1;i<=m;i++){
			int x=find(g[i].u);
			int y=find(g[i].v);
			if(x==y){
				continue;
			}
			else{
				sum+=g[i].w;
				id[x]=y;
			}
		}
		cout<<sum;
		return 0;
	} 
	int u,v,w;
	int l=1;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[l++]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flagA=1;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0){
				flagB=1;
				f[i]=j;
			}
		}
	}
	if(flagA==0&&flagB==1){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(f[i]==j){
					continue;
				}
				g[l++]={f[i],j,a[i][j]};
			}
		}
		sort(g+1,g+1+l,cmp);
		int sum=0;
		for(int i=1;i<=l;i++){
			int x=find(g[i].u);
			int y=find(g[i].v);
			if(x==y){
				continue;
			}
			else{
				sum+=g[i].w;
				id[x]=y;
			}
		}
		cout<<sum;
	}
	return 0;
}
