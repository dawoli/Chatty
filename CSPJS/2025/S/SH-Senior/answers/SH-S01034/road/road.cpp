#include <bits/stdc++.h>
using namespace std;

const long long MAXN=1e4+10;
const long long MAXM=1e6+10;
const long long INF=1e18;

struct Edge {
	long long p,q,t;
};

long long n,m,k,mn;
long long ud,vd,wd;

long long c[20]={};
bool y[20]={};

long long a[20][MAXN]={};
long long g[1010][1010]={};

Edge e[MAXM];
Edge ec[MAXM];

bool v[MAXM]={};
bool vis[MAXN]={};

long long ans=INF;

bool cmp(Edge x,Edge y) {
	return x.t<y.t; 
}

long long solve() {
	long long res=0;
	for(register long long i=1;i<=n;i++) {
		vis[i]=false;
	}
	for(register long long i=1;i<=k;i++) {
		if(y[i]) {
			res=res+c[i];
		}
	}
	long long cnt=0;
	for(register long long i=1;i<=n;i++) {
		for(register long long j=i+1;j<=n;j++) {
			cnt++;
			ec[cnt].p=i; ec[cnt].q=j;
			ec[cnt].t=INF;
			if(g[i][j]!=-1) ec[cnt].t=g[i][j];
			for(register long long l=1;l<=k;l++) {
				if(y[l]) {
					ec[cnt].t=min(ec[cnt].t,a[l][i]+a[l][j]);
				}
			}
		}
	}
	for(register long long i=1;i<=cnt;i++) {
		v[i]=false;
	}
	sort(ec+1,ec+cnt+1,cmp);
	v[1]=true;
	vis[ec[1].p]=true; vis[ec[1].q]=true;
	res=res+ec[1].t;
	for(register long long teg=1;teg<=n-2;teg++) {
		bool op=false;
		for(register long long i=1;i<=cnt;i++) {
			if(!v[i]) {
				if((vis[ec[i].p] && !vis[ec[i].q]) || (!vis[ec[i].p] && vis[ec[i].q])) {
					v[i]=true;
					vis[ec[i].p]=true;
					vis[ec[i].q]=true;
					res=res+ec[i].t;
					op=true;
				}
			}
			if(op) break;
		}
	}
	return res;
}

void dfs(long long x) {
	if(x==k+1) {
		if(solve()<ans) {
			ans=solve();
		}
		return ;
	}
	y[x]=true;
	dfs(x+1);
	y[x]=false;
	dfs(x+1);
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; mn=n*(n-1)/2;
	for(register long long i=1;i<=m;i++) {
		cin>>ud>>vd>>wd;
		if(ud>vd) swap(ud,vd);
		e[i].p=ud;
		e[i].q=vd;
		e[i].t=wd;
	}
	if(k==0) {
		sort(e+1,e+m+1,cmp);
		v[1]=true;
		vis[e[1].p]=true; vis[e[1].q]=true;
		ans=e[1].t;
		for(register long long teg=1;teg<=n-2;teg++) {
			bool op=false;
			for(register long long i=1;i<=m;i++) {
				if(!v[i]) {
					if((vis[e[i].p] && !vis[e[i].q]) || (!vis[e[i].p] && vis[e[i].q])) {
						v[i]=true;
						vis[e[i].p]=true;
						vis[e[i].q]=true;
						ans=ans+e[i].t;
						op=true;
					}
				}
				if(op) break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(register long long i=1;i<=n;i++) {
		for(register long long j=1;j<=n;j++) {
			g[i][j]=-1;
		}
	}
	for(register long long i=1;i<=m;i++) {
		g[e[i].p][e[i].q]=e[i].t;
	}
	long long tmp=0;
	for(register long long i=1;i<=k;i++) {
		cin>>c[i]; tmp+=c[i];
		for(register long long j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
