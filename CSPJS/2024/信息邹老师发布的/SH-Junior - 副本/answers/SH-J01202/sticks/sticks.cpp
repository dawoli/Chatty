#include <iostream>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int t, n, f[10][100005], ans[100005], d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
signed main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> t;
	memset(f, 0x3f, sizeof f);
	memset(ans, 0x3f, sizeof ans);
	for(int i = 0; i <= 9; i++)f[i][d[i]] = i;
	for(int i = 0; i <= 9; i++)
		for(int j = d[i]; j <= 100005; j++)
			for(int k = 0; k <= 9; k++)
			{
				if(k == 0 && j - d[i] - d[k] < 2)continue;
				f[i][j] = min(f[i][j], f[k][j-d[i]] * 10 + i);
			}
	for(int i = 0; i <= 100005; i++)			
		for(int j = 0; j <= 9; j++)
			ans[i] = min(ans[i], f[j][i]);
	while(t--)
	{
		cin >> n;
		if(ans[n] < 0x3f3f3f3f3f3f3f3f)cout << ans[n] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
