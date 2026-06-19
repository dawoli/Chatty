#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=1e6+1e5+20; 
int n,m,k;
int head[N],cnt;
int c[11];
int d[11];
int a[11][N]; 
struct node{
	int u,to,v,nxt;
}e[M];
void addedge(int u,int v,int w) {
	e[++cnt]={u,v,w,head[u]};
	head[u]=cnt;
}
bool cmp(node a,node b) {
	return a.v<b.v;
}
int fa[N];
int findfa(int x) {
	if (fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
void unite(int x,int y){
	int a=findfa(x),b=findfa(y);
	fa[a]=b;
}
long long kruskal(int n) {
	int tot=0;
	long long ans=0;
	for (int i=1;i<=cnt;i++) {
		int u=e[i].u;
		int to=e[i].to;

		if (findfa(u)!=findfa(to)) {
			unite(u,to);
			tot++;
			ans+=e[i].v;
		}
		if (tot==n-1) break;
	}
	return ans;
} 
void solve1() {
	
	for (int i=1;i<=k;i++) {
		for (int j=1;j<=n;j++) {
			addedge(d[i],j,a[i][j]);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	long long ans=kruskal(n);
	cout<<ans<<endl;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k; //n+1-n+k
	for (int i=1;i<=n+k;i++) {
		fa[i]=i;
	} 
	for (int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	bool flag=1;
	for (int i=1;i<=k;i++) {
		cin>>c[i];
		if (c[i]!=0) flag=0;
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
			if (a[i][j]==0) d[i]=j;
		} 
	}
	if (flag) {
		solve1();
		return 0;
	}
	if (k==0) {
		sort(e+1,e+cnt+1,cmp);
		long long ans=kruskal(n);
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}

