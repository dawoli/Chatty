/*
其实如果一个乡镇如果解锁了，那么其就一定联通进去，所以我们枚举其集合，然后把它们加入原图中跑kruskal求最小生成树就行了 
还有关键性质：原本被淘汰的边，现在更会被淘汰，所以我们在最开始留下n-1条边，然后枚举乡镇集合再跑，对排序优化一下(变成归并)，时间复杂度O(mlogm+n*loglogn*2^k) 

实现：先处理出原图上要的边，然后对每个乡镇都排序。枚举乡镇集合时dfs，每个状态都有一个vector，到下一层就归并，并且删除没用的边(并查集判断)，最后跑kruskal即可(记得加上解锁费) 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
const int N=1e4,M=1e6,K=10;
int n,m,k,c[K+5],f[N+K+5],sz[N+K+5],ans;
struct edge {
	int u,v,w;
}e[M+5],a[K+5][N+5]; vector<edge> e2;
bool operator<(edge l,edge r) {
	return l.w<r.w;
}
int find(int x) {
	if(!f[x])  return x;
	return f[x]=find(f[x]);
}
void merge(int a,int b) {
	a=find(a),b=find(b);
	if(a==b)  return;
	if(sz[a]>sz[b])  swap(a,b);
	f[a]=b,sz[b]+=sz[a];
}
void dfs(int step,int ths,vector<edge> e) {
	if(step==k+1) {
		for(int i=0;i<e.size();i++)  ths+=e[i].w;
		ans=min(ans,ths); return;
	}
	dfs(step+1,ths,e);
	for(int i=1;i<=n+k;i++)  f[i]=0,sz[i]=1;
	int i=0,j=1; vector<edge> nw;
	while(i<e.size()||j<=n) {
		if(j>n||i<e.size()&&e[i].w<a[step][j].w) {
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y)  merge(x,y),nw.push_back(e[i]);
			i++;
		}
		else {
			int x=find(a[step][j].u),y=find(a[step][j].v);
			if(x!=y)  merge(x,y),nw.push_back(a[step][j]);
			j++;
		}
	}
	dfs(step+1,ths+c[step],nw);
}
signed main() {
	fin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		fin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)  f[i]=0,sz[i]=1;
	for(int i=1;i<=m;i++) {
		int x=find(e[i].u),y=find(e[i].v),w=e[i].w;
		if(x!=y)  merge(x,y),ans+=w,e2.push_back(e[i]);
	}
	for(int i=1;i<=k;i++) {
		fin>>c[i];
		for(int j=1;j<=n;j++) {
			int x; fin>>x;
			a[i][j]={j,i+n,x};
		}
		sort(a[i]+1,a[i]+n+1);
	}
	dfs(1,0,e2); fout<<ans; return 0;
}
