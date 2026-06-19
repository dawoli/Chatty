#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,k,c[15],a[15][10005],fa[10015],f[15];
ll ans;
struct rd{
	int u,v;
	ll w;
} g[1500005];
bool cmp(rd x,rd y){
	return x.w<y.w;
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[m+(i-1)*n+j]={n+i,j,a[i][j]};
		}
	}
	sort(g+1,g+m+k*n+1,cmp);
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m+k*n;i++){
		if(get(g[i].u)==get(g[i].v)) continue;
		if(g[i].u>n) f[g[i].u-n]++;
		merge(g[i].u,g[i].v);
		ans+=g[i].w;
	}
	for(int i=1;i<=k;i++){
		if(f[i]>1) ans+=c[i];
	}
	cout<<ans;
	return 0;
}
