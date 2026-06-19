#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, d, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, cnt = 1;
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	long long t;
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		cin >> n >> m >> k;
		char map[1001][1001];
		bool explored[1001][1001];
		cin >> x >> y >> d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> map[j][i];
			}
		}
		explored[x][y] = 1;
		while(k)
		{
			if(x + dx[d] > m || y + dy[d] > n || x + dx[d] <= 0 || y + dy[d] <= 0 || map[x + dx[d]][y + dy[d]] == 'x')
			{
				d = (d + 1) % 4;
			}
			else
			{
				x += dx[d];
				y += dy[d];
				if(!explored[x][y])
				{
					cnt++;
					
					explored[x][y] = 1;
				}
			}
			k--;
		}
		cout << cnt << endl;
	}	
	return 0;
}
