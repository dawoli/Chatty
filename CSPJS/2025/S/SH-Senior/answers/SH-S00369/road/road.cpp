#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,w;
};
vector <Edge> edge;
int n,m,k,a[15][1000005],c[15],ans,fa[1000005];
bool cmp(Edge x,Edge y)
{
	return x.w < y.w;
}
int find(int x)
{
	if(x == fa[x]) return x;
	else return find(fa[x]);
}
bool is_combined(int u,int v)
{
	if(find(u) == find(v)) return true;
	else return false;
}
void combin(int u,int v)
{
	fa[u] = fa[v];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1; i <= m; i ++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge.push_back({u,v,w});
	}
	for(int i = 1; i <= k; i ++)
	{
		scanf("%d",&c[i]);
		for(int j = 1;j <= n; j ++)
			scanf("%d",&a[i][j]);
	}
	sort(edge.begin()+1,edge.end()-1,cmp);
	int cnt = 0;
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++)
	{
		int u = edge[i].u,v = edge[i].v, w = edge[i].w;
		if(cnt == (n-1)) break;
		if(is_combined(u,v)) continue;
		else{
			ans += w;
			combin(u,v);
			cnt ++;
		}
	}
	cout << ans;
	return 0;	
}
