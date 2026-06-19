#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n,m,T,k;
int a[N][N];
int ds[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int jisuan(int x,int y,int d,int k)
{
	int ans = 1;
	int nx = x,ny = y,nd = d;
	int nnx,nny;
	for (int i = 1;i <= k;i++)
	{
		nnx = nx + ds[nd][0];
		nny = ny + ds[nd][1];
		if (a[nnx][nny] == 1 || nnx > n || nny > m || nnx < 1 || nny < 1)
		{
			nd = (nd + 1) % 4;
		}
		else
		{
			nx = nnx;
			ny = nny;
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> T;
	memset(a,0,sizeof(a));
	for (int p = 1;p <= T;p++)
	{
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
			{
				char c;
				cin >> c;
				if (c == 'x') a[i][j] = 1;
				else a[i][j] = 0;
			}
		cout << jisuan(x,y,d,k) << endl;
	}
	return 0;
} 
