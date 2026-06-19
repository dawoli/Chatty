#include <bits/stdc++.h>
using namespace std;
int T,n,m,kt,xt,yt,d,cnt;
char a[1010][1010];
char b[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	for (int i = 1;i <= T;i++)
	{
		cnt = 0;
		cin >> n >> m >> kt;
		cin >> xt >> yt >> d;
		for (int j = 1;j <= n;i++)
		{
			for (int k = 1;k <= m;k++)
			{
				cin >> a[j][k];
				cout << a[1]; 
			}
		}
	
		b[xt][yt] = 1;
		for (int j = 1;j <= kt;i++)
		{
			if (d == 0)
			{
				if (yt + 1 > m || a[xt][yt + 1] == 'x')
				{
					d = 1;
				}
				else
				{
					yt = yt + 1;
					b[xt][yt + 1] = 1;
				}
			}
			if (d == 1)
			{
				if (xt + 1 > n || a[xt + 1][yt] == 'x')
				{
					d = 2;
				}
				else
				{
					xt = xt + 1;
					b[xt + 1][yt] = 1;
				}
			}
			if (d == 2)
			{
				if (yt - 1 < 1 || a[xt][yt - 1] == 'x')
				{
					d = 3;
				}
				else
				{
					yt = yt - 1;
					b[xt][yt - 1] = 1;
				}
			}
			if (d == 3)
			{
				if (xt - 1 < 1 || a[xt - 1][yt] == 'x')
				{
					d = 0;
				}
				else
				{
					xt = xt - 1;
					b[xt - 1][yt] = 1;
				}
			}
		}
		for (int j = 1;j <= n;i++)
		{
			for (int k = 1;k <= m;j++)
			{
				if (b[j][k] == 1)
				{
					b[j][k] = 0;
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}
