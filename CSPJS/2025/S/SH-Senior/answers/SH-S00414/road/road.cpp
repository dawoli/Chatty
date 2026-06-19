#include<bits/stdc++.h>
#define int long long
//So hard...IAFO
//int mian()
//froepen()
//slove()
//LUOGU=909552
using namespace std;
int fa[114514];
int find(int x){
	if(x==fa[x])return x;
	else return (fa[x]=find(fa[x]));
}
struct edge{
	int u,v,w;
}ed[1014514];
inline bool cmp(edge& a,edge& b){
	return a.w<b.w;
}
inline void disc(int a,int b){
	if(fa[a]==b)fa[a]=a;
	else fa[b]=b;
}
int n,m,k,c[114],cw[20][10010];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);long long ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>ed[i].u>>ed[i].v>>ed[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cw[i][j];
			ed[++m]={n+i,j,cw[i][j]};
		}
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=m;i++){
		int tu=find(ed[i].u),tv=find(ed[i].v);
		if(tu!=tv){
			fa[tu]=tv;ans+=ed[i].w;
		}
	}
	cout<<ans;
	return 0;
}
