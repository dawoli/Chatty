#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a[100001];
int c[100], b[100][10010];
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = z;
	}
	int flag = 1;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i] != 0) flag = 0;
		for(int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
			if(b[i][j] != 0) flag = 0;
		}
	}
	if(flag) cout << 0 << endl;
}
