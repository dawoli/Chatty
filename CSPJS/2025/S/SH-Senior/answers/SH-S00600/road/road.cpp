#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10020][10020],b[10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		a[x][y] = z;
		a[y][x] = z;
	}
	for(int i = m + 1;i <= m + 1 + k;i++)
	{
		int x;
		cin >> x;
		b[i - m] = x;
		for(int j = 1;j <= n;j++)
		{
			cin >> a[i][j];
			a[i][j] += x;
			a[j][i] = a[i][j];
		}
	}
	long long cnt = 0;
	for(int i = 1;i <= n + k;i++)
	{
		for(int j = 1;j <= n + k;j++)
		{
			for(int t = 1;t <= n + k;t++)
			{
				if(a[i][j] > a[i][t] + a[t][j] && t >= n) cnt -= b[t - n];
				a[i][j] = min(a[i][j],a[i][t] + a[t][j]);
			}
		}
	}
	/*for(int i = 1;i <= n+k;i++)
	{
		for(int j = 1;j <= n+k;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cnt += a[i][j];
		}
	}
	cout << cnt;
	return 0;
} 


