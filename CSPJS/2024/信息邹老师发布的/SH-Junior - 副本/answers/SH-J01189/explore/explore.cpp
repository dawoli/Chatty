#include <iostream>
using namespace std;
int t,n,k,m,xa,ya,da,x,y,d,b[1005][1005],sum;
char a[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> m >> k;
		cin >> xa >> ya >> da;
		d = da;
		x = xa;
		y = ya;
		sum = 0; 
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				b[i][j] = 0;
			}
		}
		b[x][y] = 1;
		for(int i = 1;i <= k;i++)
		{
			if(d == 1)
			{
				x++;
				if(x >= 1 and x <= n and y >= 1 and y <= m and a[x][y] == '.') 
				{
					b[x][y] = 1;
				}
				else
				{
					x--;
					d++;
				}
			}
			else if(d == 2)
			{
				y--;
				if(x >= 1 and x <= n and y >= 1 and y <= m and a[x][y] == '.') 
				{
					b[x][y] = 1;
				}
				else
				{
					y++;
					d++;
				}
			}
			else if(d == 3)
			{
				x--;
				if(x >= 1 and x <= n and y >= 1 and y <= m and a[x][y] == '.') 
				{
					b[x][y] = 1;
				}
				else
				{
					x++;
					d = 0;
				}
			}
			else
			{
				y++;
				if(x >= 1 and x <= n and y >= 1 and y <= m and a[x][y] == '.') 
				{
					b[x][y] = 1;
				}
				else
				{
					y--;
					d++;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++)
			{
				sum += b[i][j];
			}
		}
		cout << sum << endl;
	}
	return 0;
} 
