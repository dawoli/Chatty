#include<bits/stdc++.h>
using namespace std;
char mp[1010][1010];
int walk[1010][1010];
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				cin >> mp[i][j];
			}
		}
		walk[x][y] = 1;
		for(int i = 1; i <= k; i++)
		{
			int x1 = x, y1 = y;
			if(d == 0) y1++;
			if(d == 1) x1++;
			if(d == 2) y1--;
			if(d == 3) x1--;
			if(1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && mp[x1][y1] == '.')
			{
				x = x1;
				y = y1;
				walk[x][y] = 1;
			}
			else d = (d + 1) % 4;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(walk[i][j]) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
} 
