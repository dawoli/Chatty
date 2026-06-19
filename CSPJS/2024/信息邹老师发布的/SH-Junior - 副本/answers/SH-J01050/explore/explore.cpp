#include <bits/stdc++.h>
using namespace std;
int T, n, m, k, x0, y0, d0, a[1005][1005];
bool b[1005][1005];
char tmp, cmp = '.'; 
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		cin >> x0 >> y0 >> d0;
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				a[i][j] = 0;
				b[i][j] = 0;
			}
		}
		b[x0][y0] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> tmp;
				if(tmp == cmp)
				{
					a[i][j] = 0;
				}
				else
				{
					a[i][j] = 1;
				}
			}
		}
		for(int i = 1;i <= k;i++)
		{
			if(d0 == 0)
			{
				y0++;
				if(y0 > m || a[x0][y0] == 1)
				{
					y0--;
					d0 = (d0 + 1) % 4;
				}
			}
			else if(d0 == 1)
			{
				x0++;
				if(x0 > n || a[x0][y0] == 1)
				{
					x0--;
					d0 = (d0 + 1) % 4;
				}			
			}
			else if(d0 == 2)
			{
				y0--;
				if(y0 < 1 || a[x0][y0] == 1)
				{
					y0++;
					d0 = (d0 + 1) % 4;
				}
			}
			else if(d0 == 3)
			{
				x0--;
				if(x0 < 1 || a[x0][y0] == 1)
				{
					x0++;
					d0 = (d0 + 1) % 4;
				}					
			}
			b[x0][y0] = 1;
			//cout << x0 << " " << y0 << " " << d0 << " ";
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				if(b[i][j] == 1)
				{
					ans++;

				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
