#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m,k;
int h[11000],to[2100000],wt[2100000],ne[2100000],idx;
void add(int u,int v,int w) {
	idx++;
	to[idx]=v;
	wt[idx]=w;
	ne[idx]=h[u];
	h[u]=idx; 
}
int c[15],a[15][11000];
bool usd[15],mu[15];
int dis[11000],vst[11000];
priority_queue<pii> q;
int cal() {
	memset(dis,0x3f,sizeof(dis));
	memset(vst,0,sizeof(vst));
	while(!q.empty()) q.pop();
	q.push(make_pair(0,1));
	int ans=0;
	for(int i=1;i<=k;i++) {
		if(usd[i]==1) ans+=c[i];
	}
	while(!q.empty()) {
		while(!q.empty()&&vst[q.top().second]==1) q.pop();
		if(q.empty()) break;
		int u=q.top().second;
		ans+=(-q.top().first);
		q.pop();
		vst[u]=1;
		if(u>n) {
			for(int i=1;i<=n;i++) {
				if(vst[i]==0&&a[u-n][i]<dis[i]) {
					dis[i]=a[u-n][i];
					q.push(make_pair(-dis[i],i));
				}
			}
		} 
		else {
			for(int i=h[u];i;i=ne[i]) {
				int v=to[i],w=wt[i];
				if(vst[v]==0&&w<dis[v]) {
					dis[v]=w;
					q.push(make_pair(-dis[v],v));
				}
			}
			for(int i=1;i<=k;i++) {
				if(usd[i]==0) continue;
				if(vst[n+i]==0&&a[i][u]<dis[n+i]) {
					dis[n+i]=a[i][u];
					q.push(make_pair(-dis[n+i],n+i));
				}
			}
		}
	}
	return ans;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++) {
		cin >> c[i];
		mu[i]=0;
		for(int j=1;j<=n;j++) {
			cin >> a[i][j];
			if(a[i][j]==0) mu[i]=1;
		}
		if(c[i]!=0) mu[i]=0;
	}
	int ans=(1ll<<62);
	for(int i=0;i<(1<<k);i++) {
		int ii=i;
		bool flag=1;
		for(int j=1;j<=k;j++) {
			usd[j]=ii%2;
			ii/=2;
			if(mu[j]==1&&usd[j]==0) flag=0;
		}
		if(flag==0) continue;
		ans=min(ans,cal());
	}
	cout << ans;
	return 0;
}
