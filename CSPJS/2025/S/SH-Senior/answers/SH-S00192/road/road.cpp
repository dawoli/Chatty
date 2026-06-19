#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e4 + 5,M = 2e6 + 5;

struct edge
{
	int to,cost,id;
};

int visE[M],vis[N],c[15],n,m,k,ans = 1e9,maxn = 1e9;

vector<edge> g[N];

void dfs(int x,int cnt,int cost,string s,int dot)
{
//	printf("dfs(%d,%d,%d)\n",x,cnt,cost);
	if(cost > ans) return ;
	if(cost > maxn) return ;
	if(cnt == n + dot)
	{
		ans = min(ans,cost);
		return ;
	}
	for(edge op : g[x])
	{
		int y = op.to,w = op.cost,id = op.id;
		if(y > n && s[y - n - 1] == '0') continue;
		if(visE[id] > 2) continue;
		if(vis[y] == 0)
		{
			vis[y] = 1;
			if(visE[id]) w = 0;
			visE[id]++;
			dfs(y,cnt + 1,cost + w,s,dot);
			vis[y] = 0;
			visE[id]--;
		}
		else
		{
			vis[y]++;
			if(visE[id]) w = 0;
			visE[id]++;
			dfs(y,cnt,cost + w,s,dot);
			vis[y]--;
			visE[id]--;
		}
	}
}

void Solve0()
{
	dfs(0,0,0,"",0);
	cout << ans;
}

void Solve1()
{
	dfs(0,0,0,"0",0);
	maxn = ans;
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 1});
	dfs(0,0,c[1],"1",1);
	cout << min(maxn,ans);
}

void Solve2()
{
	dfs(0,0,0,"00",0);
	maxn = ans;
	ans = 1e9;
//	cout << endl << endl;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 1});
	dfs(0,0,c[1],"10",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 2,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2],"01",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 2});
	dfs(0,0,c[1] + c[2],"11",2);
//	cout << maxn1 << " " << maxn2 << " " << maxn3 << " " << ans << endl;
	cout << min(maxn,ans);
}

void Solve3()
{
	dfs(0,0,0,"000",0);
	maxn = ans;
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 1});
	dfs(0,0,c[1],"100",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 2,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2],"010",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[3],"001",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 2});
	dfs(0,0,c[1] + c[2],"110",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[3],"101",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[2] + c[3],"011",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 3});
	dfs(0,0,c[1] + c[2] + c[3],"111",3);
	cout << min(maxn,ans);
}

void Solve4()
{
	dfs(0,0,0,"0000",0);
	maxn = ans;
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 1});
	dfs(0,0,c[1],"1000",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 2,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2],"0100",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[3],"0010",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[4],"0001",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 2});
	dfs(0,0,c[1] + c[2],"1100",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[3],"1010",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[4],"1001",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[2] + c[4],"0101",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2] + c[3],"0110",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 4,0,m + (k + 1) * n + 2};
	dfs(0,0,c[4] + c[3],"0011",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 3});
	dfs(0,0,c[1] + c[4] + c[3],"1011",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[1] + c[2] + c[3],"1110",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[2] + c[4],"1101",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 3] = {n + 3,0,m + (k + 1) * n + 3};
	dfs(0,0,c[3] + c[2] + c[4],"0111",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 4});
	dfs(0,0,c[1] + c[2] + c[3] + c[4],"1111",4);
	cout << min(maxn,ans);
}

void Solve5()
{
	dfs(0,0,0,"00000",0);
	maxn = ans;
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 1});
	dfs(0,0,c[1],"10000",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 2,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2],"01000",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[3],"00100",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[4],"00010",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 5,0,m + (k + 1) * n + 1};
	dfs(0,0,c[5],"00001",1);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 2});
	dfs(0,0,c[1] + c[2],"11000",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[3],"10100",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[4],"10010",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 5,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[5],"10001",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[2] + c[5],"01001",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2] + c[4],"01100",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 3,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2] + c[3],"01100",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 4,0,m + (k + 1) * n + 2};
	dfs(0,0,c[4] + c[3],"00110",2);
	maxn = min(maxn,ans);
	ans = 1e9;
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 1,0,m + (k + 1) * n + 3});
	dfs(0,0,c[1] + c[4] + c[3],"10110",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[1] + c[2] + c[3],"11100",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 4,0,m + (k + 1) * n + 1};
	dfs(0,0,c[1] + c[2] + c[4],"11010",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 3] = {n + 3,0,m + (k + 1) * n + 3};
	dfs(0,0,c[3] + c[2] + c[4],"01110",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 5,0,m + (k + 1) * n + 1};
	dfs(0,0,c[5] + c[2] + c[3],"01101",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 1,0,m + (k + 1) * n + 2};
	dfs(0,0,c[5] + c[1] + c[3],"10101",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 4,0,m + (k + 1) * n + 2};
	dfs(0,0,c[5] + c[4] + c[3],"00111",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 3] = {n + 2,0,m + (k + 1) * n + 3};
	dfs(0,0,c[5] + c[4] + c[2],"01011",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 3] = {n + 1,0,m + (k + 1) * n + 3};
	dfs(0,0,c[5] + c[4] + c[1],"10011",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 2,0,m + (k + 1) * n + 2};
	dfs(0,0,c[5] + c[2] + c[1],"11001",3);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 3,0,m + (k + 1) * n + 4});
	dfs(0,0,c[5] + c[2] + c[1] + c[3],"11101",4);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 2] = {n + 4,0,m + (k + 1) * n + 2};
	dfs(0,0,c[5] + c[4] + c[1] + c[3],"10111",4);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 3] = {n + 2,0,m + (k + 1) * n + 3};
	dfs(0,0,c[5] + c[4] + c[2] + c[3],"01111",4);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 4] = {n + 1,0,m + (k + 1) * n + 4};
	dfs(0,0,c[5] + c[4] + c[2] + c[1],"11011",4);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0][n + 1] = {n + 2,0,m + (k + 1) * n + 1};
	dfs(0,0,c[2] + c[4] + c[1] + c[3],"11110",4);
	maxn = min(maxn,ans);
	ans = 1e9;
	g[0].push_back({n + 5,0,m + (k + 1) * n + 5});
	dfs(0,0,c[5] + c[1] + c[2] + c[1] + c[3],"11111",5);
	cout << min(maxn,ans);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w,i});
		g[v].push_back({u,w,i});
	}
	for(int i = n + 1;i <= k + n;i++)
	{
		cin >> c[i - n];
		for(int j = 1;j <= n;j++)
		{
			int cre;
			cin >> cre;
			g[i].push_back({j,cre,m + (i - n - 1) * n + j});
			g[j].push_back({i,cre,m + (i - n - 1) * n + j});
		}
	}
	for(int i = 1;i <= n;i++) g[0].push_back({i,0,m + k * n + i});
	if(k == 0)
	{
		Solve0();
	}
	else if(k == 1)
	{
		Solve1();
	}
	else if(k == 2) Solve2();
	else if(k == 3) Solve3();
	else if(k == 4) Solve4();
	else if(k == 5) Solve5();
	return 0;
}
