#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+9,M=2e6+9;
int n,m,k,fa[M],ans,cnt,c[11],vl[11][N];
int get(int x){
	if(fa[x]!=x) fa[x]=get(fa[x]);
	return fa[x]; 
}
struct edge{
	int u,v,w;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
}e[M],tmp[M];
bool vis[M];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int x=get(e[i].u),y=get(e[i].v);
		if(x!=y){
			vis[i]=1;
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	int j=0;
	for(int i=1;i<=m;i++)
		if(vis[i]) e[++j]=e[i];
	for(int i=1;i<=m;i++) tmp[i]=e[i];
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=0;
		bool now=0;
		for(int j=1;j<=n;j++){
			cin>>vl[i][j];
			if(!vl[i][j]) now=1;
		}
		if(!now) flag=0;
	}
	for(int i=0;i<(1<<k);i++){
		if(flag&&i!=(1<<k)-1) continue;
		cnt=n-1;
		int val=0;
		for(int j=0;j<k;j++)
			if((i>>j)&1){
				val+=c[j+1];
				for(int q=1;q<=n;q++) e[++cnt]=edge{n+j+1,q,vl[j+1][q]};
			}
		sort(e+1,e+cnt+1);
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=cnt;j++){
			int x=get(e[j].u),y=get(e[j].v);
			if(x!=y){
				fa[x]=y;
				val+=e[j].w;
			}
		}//cout<<i<<' '<<val<<'\n';
		ans=min(ans,val);
		for(int j=1;j<n;j++) e[j]=tmp[j];
	}
	cout<<ans<<'\n';
	return 0;
} 
