#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u,v,weight;
};

bool cmp(const edge& a,const edge& b)
{
	return a.weight < b.weight;
}

const int N = 1e4+20;
int n,m,k;
int parent[N],rank1[N],a[11][N],c[11];
vector <edge> adj;
vector <int> point;
const long long INF = 1e18;
long long minn = INF;

void make_set(int v)
{
	parent[v] = v;
	rank1[v] = 0;
}

int find_set(int v)
{
	if (v == parent[v])
	{
		return v;
	}
	return parent[v] == find_set(parent[v]);
}

void unite_set(int a,int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (rank1[a] < rank1[b]) swap(a,b);
		parent[b] = a;
		if (rank1[a] == rank1[b]) rank1[a]++;
	}
}

long long kruskal(vector <edge> edges,int p)
{
	for (int i:point)
	{
		make_set(i);
	}
	sort(edges.begin(),edges.end(),cmp);
	long long total = 0,cnt = 0;
	for (auto& e : edges)
	{
		int a = find_set(e.u),b = find_set(e.v);
		if (a != b)
		{
			cnt++;
			unite_set(e.u,e.v);
			total += e.weight;
		}
	}
	if (cnt == p-1) return total;
	else return INF;
}

void dfs(int start,int k,int sum)
{
	if (n-start+1 < k) return;
	if (k == 0)
	{
		minn = min(minn,kruskal(adj,n+k)+sum);
		return;
	}
	point.push_back(start+n);
	for (int i = 1;i <= n;i++)
	{
		adj.push_back({start+n,i,a[start][i]});
	}
	dfs(start+1,k-1,sum+c[start]);
	for (int i = 1;i <= n;i++)
	{
		adj.pop_back();
	}
	point.pop_back();
	dfs(start+1,k,sum);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++)
	{
		point.push_back(i);
	}
	for (int i = 1,u,v,w;i <= m;i++)
	{
		cin >> u >> v >> w;
		adj.push_back({u,v,w});
	}
	bool t = true;
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if (c[i] != 0) t = false;
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	if (t)
	{
		for (int i = 1;i <= k;i++)
		{
			point.push_back(n+i);
			for (int j = 1;j <= n;j++)
			{
				adj.push_back({n+i,j,a[i][j]});
			}
		}
		cout << kruskal(adj,n);
		return 0;
	}
	for (int i = 0;i <= k;i++)
	{
		dfs(1,i,0);
	}
	cout << minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
