#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long

using namespace std;
const int N=1e4+25;
const int M=1e6+1e5+5;
int n,m,k,tot,c[25],f[N],sz[N];
struct edge{
	int u,v,w;
	int fr;//from
}e[M],E[M];
ll ans=0,preans=0;
bool flag=false;
bool cmp(edge x,edge y){
	return (x.w==y.w)?(x.fr>y.fr):(x.w<y.w);
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

int find(int x){return (f[x]==x)?(x):(f[x]=find(f[x]));}
void suan(){
	ans=0;
	int p=0;
	rep(i,1,n+k)f[i]=i;
	rep(i,1,n)sz[i]=1;
	rep(i,1,m+n*k)e[i]=E[i];
	sort(e+1,e+m+k*n+1,cmp);
	int i=0;
	while(!flag&&i<=m+n*k){
		i++;
		int u=e[i].u,v=e[i].v,w=e[i].w,fr=e[i].fr;
		int r1=find(u),r2=find(v);
		if(r1==r2)continue;
		else if(fr){
			p=fr;
			break;
		}else{
			ans+=w;
			if(sz[r1]<sz[r2])swap(r1,r2);
			f[r2]=r1;
			sz[r1]+=sz[r2];
			if(sz[r1]==n){
				flag=true;
				return;
			}
		}
	}
	rep(i,m+(p-1)*n+1,m+(p-1)*n+n){
		E[i].fr=0;
		E[i].w-=c[p];
	}
	preans+=c[p];
}
void suba(){
	ans=0;
	rep(i,1,n+k)f[i]=i;
	rep(i,1,n)sz[i]=1;
	rep(i,1,m+n*k)e[i]=E[i];
	sort(e+1,e+m+k*n+1,cmp);
	int i=0;
	while(!flag&&i<=m+n*k){
		i++;
		int u=e[i].u,v=e[i].v,w=e[i].w,fr=e[i].fr;
		int r1=find(u),r2=find(v);
		if(r1==r2)continue;
		ans+=w;
		if(sz[r1]<sz[r2])swap(r1,r2);
		f[r2]=r1;
		sz[r1]+=sz[r2];
		if(sz[r1]==n){
			flag=true;
			return;
		}
	}
}
void solve(){
//	rd(n);rd(m);rd(k);
	cin>>n>>m>>k;
	rep(i,1,m){
		int u,v,w;
//		rd(u);rd(v);rd(w);
		cin>>u>>v>>w;
		E[++tot]={u,v,w,0};
	}
	bool f=true;
	rep(i,1,k){
//		rd(c[i]);
		cin>>c[i];
		if(c[i])f=false;
		int w;
		rep(j,1,n){
//			rd(w);
			cin>>w;
			E[++tot]={n+i,j,w+c[i],i};
		}
	}
	if(f){
		suba();
		cout<<ans<<endl;
		return;
	}
	while(!flag)
		suan();
	cout<<(ans+preans)<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int TEST=1;
	//cin>>TEST;
	while(TEST--)
		solve();
	return 0;
}
