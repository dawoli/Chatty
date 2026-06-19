#include <bits/stdc++.h>
using namespace std;

void testIO()
{
	int n;
	cin >> n;
	cout << n << endl;
}

const int N = 1e5 + 5;

int T;
int n, m, L, V;
int d[N], v[N], a[N];
int p[N];

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	// testIO();
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> L >> V;
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> d[i] >> v[i] >> a[i];
			if (v[i] > V) cnt++;
		}
		int maxn = 0;
		for (int i = 1; i <= m; ++i)
		{
			cin >> p[i];
			maxn = max(maxn, p[i]);
		}
		for (int i = 1; i <= n; ++i) if (d[i] > maxn) cnt--;
		cout << cnt << " " << m - 1 << endl;
	}
	return 0;
}