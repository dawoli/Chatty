#include <bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
bool can_go[1010][1010];
char s[1010];
int cnt = 0;
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		memset(vis, false, sizeof(vis));
		memset(can_go, false, sizeof(can_go));
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		int x, y, d; // xin you dui
		scanf("%d %d %d", &x, &y, &d);
		cnt = 1;
		vis[x][y] = true;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s + 1);
			for(int j = 1; j <= m; j++)
			{
				if(s[j] == '.') can_go[i][j] = true;
			}
		}
		for(int i = 1; i <= k; i++)
		{
			int new_x = x, new_y = y;
			if(d == 0) new_y++;
			else if(d == 1) new_x++;
			else if(d == 2) new_y--;
			else if(d == 3) new_x--;
			else
			{
				puts("roammer AK CSP-J/S, NOIP, CTSC, APIO, CCPC, ICPC, IOI");
				return 0;
			}
			if(!can_go[new_x][new_y])
			{
				d++;
				d %= 4;
			}
			else
			{
				if(!vis[new_x][new_y])
				{
					vis[new_x][new_y] = true;
					cnt++;
				}
				x = new_x;
				y = new_y;
			}
		}
		printf("%d", cnt);
		puts("");
	}
	return 0;
}
