#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int const N=10004,M=1000006,K=15;
//vector<pair<int,ll>> g[N];
struct Edge {
	int u,v;
	ll w;
} edge[M+K*N],oldedge[M+K*N];
int n,m,k;
int c[K],a[K][N];
int fa[N+K],sz[N+K];
int inline find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
void inline conn(int u,int v) {
	if(sz[u]>sz[v]) fa[find(v)]=find(u),sz[u]+=sz[v];
	else fa[find(u)]=find(v),sz[v]+=sz[u];
}
bool inline isconn(int u,int v) {return find(u)==find(v);}
void solveBF() {
//	debug("BF");
	ll minans=1e18;
	for(ll i=0;i<(1<<k);i++) {
//		debug(i);
		int newEdgeCnt=m;
		ll ans=0;
		for(int j=1;j<=m;j++) edge[j]=oldedge[j];
		for(int j=1;j<=k;j++) {
			if(i&(1<<j-1)) {
//				debug(j);
				ans+=c[j];
				for(int p=1;p<=n;p++) edge[++newEdgeCnt]={n+j,p,a[j][p]};
			}
		}
//		for(int i=1;i<=newEdgeCnt;i++) debug(edge[i].u),debug(edge[i].v),debug(edge[i].w);
		sort(edge+1,edge+newEdgeCnt+1,[](Edge a,Edge b){return a.w<b.w;});
		for(int j=1;j<=n+k;j++) fa[j]=j,sz[j]=1;
		int cnt=0;
		for(int j=1;j<=newEdgeCnt;j++) if(!isconn(edge[j].u,edge[j].v)) ++cnt,conn(edge[j].u,edge[j].v),ans+=edge[j].w;
//		debug(cnt);
//		if(ans==5095741225) debug(ans),assert(0);
		minans=min(minans,ans);
	}
	cout<<minans<<endl;
}
ll sumcost[N];
int id[1<<K],id2[1<<K];
void solveBlind() {
//	debug("Blind");
	ll minans=1e18;
	int lim=998000;
	for(int i=0;i<(1<<k);i++) id[i]=i,id2[i]=i;
	sort(id2,id2+(1<<k),[&](int a,int b) {return sumcost[a]<sumcost[b];});
	srand(0x12345678);
	for(int i=0;i<(1<<k);i++) if(rand()%10000<1000) {
		swap(id2[i],id2[rand()%(1<<k)]);
	}
	for(ll p=0;p<(1<<k)&&clock()<lim;++p) {
		ll i=id2[p];
//		debug(i);
		int newEdgeCnt=m;
		ll ans=0;
		for(int j=1;j<=m&&clock()<lim;++j) edge[j]=oldedge[j];
		for(int j=1;j<=k&&clock()<lim;++j) {
			if(i&(1<<j-1)) {
//				debug(j);
				ans+=c[j];
				for(int p=1;p<=n&&clock()<lim;++p) edge[++newEdgeCnt]={n+j,p,a[j][p]};
			}
		}
//		for(int i=1;i<=newEdgeCnt;i++) debug(edge[i].u),debug(edge[i].v),debug(edge[i].w);
		sort(edge+1,edge+newEdgeCnt+1,[](Edge a,Edge b){return a.w<b.w;});
		for(int j=1;j<=n+k&&clock()<lim;++j) fa[j]=j,sz[j]=1;
		int cnt=0;
		for(int j=1;j<=newEdgeCnt&&clock()<lim;++j) if(!isconn(edge[j].u,edge[j].v)) ++cnt,conn(edge[j].u,edge[j].v),ans+=edge[j].w;
//		debug(cnt);
//		if(ans==5095741225) debug(ans),assert(0);
		minans=min(minans,ans);
	}
	cout<<minans<<endl;
}
void solveSpecialA() {
	int newEdgeCnt=m;
	for(int j=1;j<=m;j++) edge[j]=oldedge[j];
	for(int i=1;i<=k;i++) {
		int u=0;
		for(int j=1;j<=n;j++) if(!a[i][j]) u=j;
		for(int j=1;j<=n;j++) edge[++newEdgeCnt]={u,j,a[i][j]};
	}
	ll ans=0;
	sort(edge+1,edge+newEdgeCnt+1,[](Edge a,Edge b){return a.w<b.w;});
	for(int j=1;j<=n+k;j++) fa[j]=j,sz[j]=1;
	for(int j=1;j<=newEdgeCnt;j++) if(!isconn(edge[j].u,edge[j].v)) conn(edge[j].u,edge[j].v),ans+=edge[j].w;
	cout<<ans<<endl;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>oldedge[i].u>>oldedge[i].v>>oldedge[i].w;
	bool isSpecialA=1;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		sumcost[i]+=c[i];
		if(c[i]) isSpecialA=0;
		int cnt=n;
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			sumcost[i]+=a[i][j];
			if(a[i][j]) cnt--;
		}
		if(!cnt) isSpecialA=0;
	}
	if(isSpecialA) solveSpecialA();
	else if(n<=1000&&m<=100000&&k<=5) solveBF();
	else solveBlind();
	return 0;
}

