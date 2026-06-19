#include<bits/stdc++.h>
using namespace std;

struct node1 // 城市 
{
	int id;
	vector<int> edges;
	vector<int> costs;
}a[1000005];

struct node2 // 乡镇 
{
	int id;
	int cost; // 城市化费用
	vector<int> costs; // 至少连两条，不然没有意义
}b[15]; 

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	int ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin>>u>>v;
		int cost;
		cin>>cost;
		a[u].id = u;
		a[v].id = v;
		a[u].edges.push_back(v);
		a[v].edges.push_back(u);
		a[u].costs.push_back(cost);
		a[v].costs.push_back(cost);
		ans += cost;
	}
	for(int i = 1; i <= k; i++)
	{
		b[i].id = i;
		cin>>b[i].cost;
		for(int j = 1; j <= n; j++)
		{
			int x;
			cin>>x;
			b[i].costs.push_back(x);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
