#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int c[27];
int fa[10050];
struct no{
	int u,v,w;
}f[1000007];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
bool cmp(no A,no B){
	return A.w<B.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>f[i].u>>f[i].v>>f[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	sort(f+1,f+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=f[i].u,v=f[i].v,w=f[i].w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int aaa;
			cin>>aaa;
		}
	}
	cout<<ans;
	return 0;
}

