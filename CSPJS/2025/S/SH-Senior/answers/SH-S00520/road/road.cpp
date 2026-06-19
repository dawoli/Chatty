#include<bits/stdc++.h>
#define FILE(X) freopen(X".in","r",stdin); freopen(X".out","w",stdout);
#define ll long long
using namespace std;
const int N=10040,M=1000060,K=15;
int n,m,k;
int hd[N],nxt[M<<1],to[M<<1]; ll w[M<<1];
int c[K];ll a[K][N];
bool vis[N];
ll ans;
struct node{ int u; ll dis; } prique[N]; int pqcnt=1;

void pri_que_push(node x) {
	int u=pqcnt;
	prique[pqcnt++]=x;
	while(u!=1&&(prique[u>>1].u==0||prique[u>>1].dis>x.dis)) {
		prique[u]=prique[u>>1];
		prique[u>>1]=x;
		u>>=1;
	}
	return;
}

node pri_que_pop() {
	node pop_x=prique[1];
	prique[1]={0,0};
	int u=1;
	while(prique[u<<1].u||prique[(u<<1)+1].u) {
		int son=(u<<1)+1;
		if(prique[(u<<1)+1].u==0||(prique[u<<1].u&&prique[u<<1].dis<prique[(u<<1)+1].dis)) {
			son=u<<1;
		}
		prique[u]=prique[son];
		prique[son]={0,0};
		u=son;
	}
	return pop_x;
}

bool pri_que_empty() {
	return prique[1].u==0;
}

void query_mfs() {
	pri_que_push({1,0});
	while(1) {
		if(pri_que_empty()) break;
		node cur=pri_que_pop();
		if(vis[cur.u]) continue;
		ans+=cur.dis;
		for(int i=hd[cur.u];~i;i=nxt[i]) {
			int v=to[i];
			pri_que_push({v,w[i]});
		}
		vis[cur.u]=true;
	}
	return;
}

int main() {
	FILE("road");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) hd[i]=-1;
	for(int i=0;i<m;i++) {
		int u,v;
		cin>>u>>v>>w[(i<<1)+1];
		nxt[i<<1]=hd[u];
		hd[u]=i<<1;
		to[i<<1]=v;
		nxt[(i<<1)+1]=hd[v];
		hd[v]=(i<<1)+1;
		to[(i<<1)+1]=u;
		w[i<<1]=w[(i<<1)+1];
	}
	for(int i=0;i<k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j]; 
	}
	for(int i=1;i<=n;i++) vis[i]=false;
	query_mfs();
	cout<<ans;
	return 0;
}
