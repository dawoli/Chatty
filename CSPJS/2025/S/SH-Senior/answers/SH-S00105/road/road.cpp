#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,tot;
int f[200010],ans,tota,totb,siz[200010];
struct node{
	int u,v,w;
}e[1000010],ea[10010],eb[200010];
int c[11];
bool vis[1000010];
int a[11][10010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int Find(int x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}
void Union(int x,int y,int z){
	int fx=Find(x),fy=Find(y);
	if(siz[fx]<siz[fy]) swap(fx,fy);
	if(fx!=fy){
		f[fy]=fx;
		siz[fx]+=siz[fy];
		vis[z]=1;
	}
}
void init(){
	for(int i=1;i<=n+k;i++){
		f[i]=i;
		siz[i]=1;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		Union(e[i].u,e[i].v,i);
		if(vis[i]){
			ea[++tota]=e[i];
			ans+=e[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			eb[++totb]={i+n,j,a[i][j]};
		}
	}
	sort(eb+1,eb+totb+1,cmp);
	for(int i=0;i<(1<<k);i++){
		tot=n-1;
		init();
		int nowa=1,nowb=1;
		int temp=0;
		for(int j=1;j<=k;j++){
			if(i>>(j-1)&1){
				temp+=c[j];
			}
		}
		for(int j=1;j<=__builtin_popcount(i)+n-1;j++){
			while(nowa<=tota&&Find(ea[nowa].u)==Find(ea[nowa].v))nowa++;
			while(nowb<=totb&&(Find(eb[nowb].u)==Find(eb[nowb].v)||(i>>(eb[nowb].u-n-1)&1)==0)) nowb++;
			if(nowa>tota){
				Union(eb[nowb].u,eb[nowb].v,1);
				temp+=eb[nowb++].w;
			}else if(nowb>totb){
				Union(ea[nowa].u,ea[nowa].v,1);
				temp+=ea[nowa++].w;
			}else if(ea[nowa].w<eb[nowb].w){
				Union(ea[nowa].u,ea[nowa].v,1);
				temp+=ea[nowa++].w;
			}else{
				Union(eb[nowb].u,eb[nowb].v,1);
				temp+=eb[nowb++].w;
			}
		} 
		ans=min(ans,temp);
	}
	cout<<ans;
}
