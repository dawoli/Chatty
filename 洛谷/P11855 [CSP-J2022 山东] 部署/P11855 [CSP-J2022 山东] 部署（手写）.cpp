#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edge;
vector<vector<int>> order;
vector<int> army;
int n, m, q;
void dfs(int no,int fa)
{
	army[no]+=order[2][no];
	army[no]+=order[1][no];
	for (int i=0;i<edge[no].size();i++)
	{
		if(edge[no][i]==fa)continue;
		order[1][edge[no][i]]+=order[1][no];//原来这行写成了order[1][i]+=order[1][no],导致1指令无法下传或下传错误
		dfs(edge[no][i],no);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	edge.resize(n + 1);
	army.resize(n + 1);
	order.resize(3,vector<int>(n+1,0));
	army[0] = 0;
	order[1][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		army[i] = x;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int p, x, y;
		cin >> p >> x >> y;
		if (p == 1)
		{
			order[1][x] += y;
		}
		if (p == 2)
		{
			order[2][x] += y;
			for (int j = 0; j < edge[x].size(); j++) {
				order[2][edge[x][j]] += y;
			}
		}
	}
	dfs(1,0);
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int a;
		cin >> a;
		cout << army[a] << "\n";
	}
	cout<<endl;
	return 0;
}