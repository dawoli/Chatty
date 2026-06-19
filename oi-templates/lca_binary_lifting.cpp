#include <bits/stdc++.h>
using namespace std;

// 二进制倍增 LCA 模板（1-indexed 节点）
/*
 * 复杂度：预处理 O(n log n)，查询 O(log n)
 * 用法示例：
 *   LCA l(n);
 *   l.addEdge(u,v);
 *   l.build(1);
 *   int a = l.lca(x,y);
 */
struct LCA
{
	int n,LOG;
	vector<int> depth;
	vector<vector<int>> up;
	vector<vector<int>> adj;
	LCA(int _n=0) { if(_n) init(_n); }
	void init(int _n) { n=_n; LOG=1; while((1<<LOG)<=n) LOG++; depth.assign(n+1,0); up.assign(LOG,vector<int>(n+1,0)); adj.assign(n+1,{}); }
	void addEdge(int u,int v) { adj[u].push_back(v); adj[v].push_back(u); }
	void dfs(int u,int p) { up[0][u]=p; for(int k=1;k<LOG;k++) up[k][u]=up[k-1][up[k-1][u]]; for(int v:adj[u]) if(v!=p) { depth[v]=depth[u]+1; dfs(v,u); } }
	void build(int root=1) { depth[root]=0; dfs(root,root); }
	int lca(int a,int b) { if(depth[a]<depth[b]) swap(a,b); int diff=depth[a]-depth[b]; for(int k=0;k<LOG;k++) if(diff>>k&1) a=up[k][a]; if(a==b) return a; for(int k=LOG-1;k>=0;k--) if(up[k][a]!=up[k][b]) { a=up[k][a]; b=up[k][b]; } return up[0][a]; }
};
