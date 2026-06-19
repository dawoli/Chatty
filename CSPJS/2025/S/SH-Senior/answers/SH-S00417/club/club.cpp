#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, a[N][4], dif[N], ans;
vector<int> b[4];
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		ans = 0;
		for (int j = 1; j <= 3; j++)
			b[j].clear();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int maxa = 1, mina = 1;
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				if (a[i][j] > a[i][maxa])
					maxa = j;
				if (a[i][j] < a[i][mina])
					mina = j;
			}
			int mida = 6 - maxa - mina;
			dif[i] = a[i][maxa] - a[i][mida];
			b[maxa].push_back(dif[i]);
			ans += a[i][maxa];
		}
		int maxb = 1;
		for (int i = 2; i <= 3; i++)
		{
			if (b[i].size() > b[maxb].size())
				maxb = i;
		}
		if (b[maxb].size() > n / 2)
		{
			sort(b[maxb].begin(), b[maxb].end());
			for (int i = 0; i < b[maxb].size() - n / 2; i++)
				ans -= b[maxb][i];
		}
		cout << ans << "\n";
	}
}
// AC
