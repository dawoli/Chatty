#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5,M=2e4+5;

int n,m,k,f[M],node;
long long c[N],ans=0,sum=0;
bool used[15];
struct edge{int u,v;long long w;}e[N];

bool cmp(edge a,edge b) {return a.w<b.w;}

int find(int x) {
	if(f[x]!=x) return f[x]=find(f[x]);
	return x;
}

long long kruskal() {
	long long res=0,cnt=0;
	for(int i=1;i<=m+k*n;i++) {
		int u=e[i].u,v=e[i].v;
		if(v>n&&!used[v-n]) continue;
		if(find(u)==find(v)) continue;
		res+=e[i].w;
		f[find(u)]=find(v);
		cnt++;
		if(cnt==node-1) {
			return res;
		}
	}
}

void dfs(int x) {
	if(x==k+1) {return;}
	if(!c[x]) dfs(x+1);
	else {
		used[x]=1;node++;sum+=c[x];
		for(int i=1;i<=n+k;i++) f[i]=i;
		long long res=kruskal();
		ans=min(res+sum,ans);
		dfs(x+1);
		used[x]=0;node--;sum-=c[x];
		dfs(x+1);
	}
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	node=n;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i];if(!c[i]) node++,used[i]=1;
		for(int j=1;j<=n;j++) {
			e[m+(i-1)*n+j].u=j;
			e[m+(i-1)*n+j].v=n+i;
			cin>>e[m+(i-1)*n+j].w;
		}
	}
	sort(e+1,e+m+k*n+1,cmp);
	ans=kruskal();
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
