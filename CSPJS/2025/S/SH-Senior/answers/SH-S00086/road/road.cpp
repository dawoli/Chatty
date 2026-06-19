#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10099;
const int M=1000099;
int n,m,k,ans,c[N];
struct edge{
	int u,v,w;
	bool operator <(const edge &A) const{
		return w>A.w;
	}
}edg[M],a[11][N];
int p[11];
bool cmp(edge A,edge B){
	return A.w<B.w;
}

int id[N];
int find(int x){
	if(id[x]==x) return x;
	return id[x]=find(id[x]);
}

priority_queue<edge> pq;
void clr(){
	while(!pq.empty())
		pq.pop();
	return;
}
void solve(int ptn){
	ptn<<=1;
	int res=0,cnte=n-1;
	p[0]=1; pq.push(edg[1]);
	for(int i=1;i<=k;i++)
		if((ptn>>i)&1){
			res+=c[i],cnte++;
			p[i]=1; pq.push(a[i][1]);
		}
	for(int i=1;i<=n+k;i++)
		id[i]=i;
	edge now;
	int u,v,w;
	while(cnte){
		now=pq.top(); pq.pop();
		u=now.u; v=now.v; w=now.w;
		if(id[u]!=id[v]&&find(u)!=find(v)){
			id[id[u]]=id[v];
			res+=w; cnte--;
		}
		if(u>n){
			u-=n; p[u]++;
			if(p[u]<=n) pq.push(a[u][p[u]]);
		}
		else{
			p[0]++;
			if(p[0]<=n) pq.push(edg[p[0]]);
		}
	}
	ans=min(ans,res);
	clr();
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		edg[i]=(edge){u,v,w};
	}
	sort(edg+1,edg+m+1,cmp);
	for(int i=1;i<=n;i++)
		id[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++){
		u=edg[i].u; v=edg[i].v; w=edg[i].w;
		if(find(u)==find(v)) continue;
		ans+=w; id[id[u]]=id[v];
		edg[++cnt]=edg[i];
	}

	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[i][j].u=i+n; a[i][j].v=j;
			cin>>a[i][j].w;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}

	for(int i=1;i<(1<<k);i++)
		solve(i);
	cout<<ans;
	return 0;
}