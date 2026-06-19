#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> s[N];
int n, k, r, c, flg;

void dfs(int stp, int cur, int plc, int fa)
{
	if(flg) return;
	for(int i = plc + 1; i < min(plc + k, (int)s[cur].size()); i++)
	{
		if(stp == r - 1)
		{
			if(s[cur][i] == c) flg = 1;
			continue;
		}
		for(int j = 1; j <= n; j++)
		{
			if(cur == j) continue;
			for(int l = 0; l < s[j].size(); l++)
			{
				if(s[j][l] == s[cur][i]) dfs(stp + 1, j, l, cur);
			}
		}
	}
}

void work()
{
	scanf("%d%d", &r, &c);
	if(n <= 20)
	{
		flg = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < s[i].size(); j++)
			{
				if(s[i][j] == 1) dfs(0, i, j, -1);
			}
		}
		printf("%d\n", flg);
		return;
	}
	if(r == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			int x = 0, y = 0;
			for(int j = 0; j < s[i].size(); j++)
			{
				if(s[i][j] == 1)
				{
					for(int l = j + 1; l < min(j + k, (int)s[i].size()); l++)
					{
						if(s[i][l] == c)
						{
							printf("1\n");
							return;
						}
					}
				}
			}
		}
		printf("0\n");
		return;
	}
	printf("0\n");
}

void solve()
{
	for(int i = 1; i <= n; i++) s[i].clear();
	
	int q;
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 1; i <= n; i++)
	{
		int l;
		scanf("%d", &l);
		for(int j = 1; j <= l; j++)
		{
			int x;
			scanf("%d", &x);
			s[i].push_back(x);
		}
	}
	
	for(int i = 1; i <= q; i++) work();
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	
	while(t--) solve();
}
