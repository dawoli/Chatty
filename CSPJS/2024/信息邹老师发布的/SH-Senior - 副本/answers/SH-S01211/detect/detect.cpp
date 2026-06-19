#include <bits/stdc++.h>
using namespace std;
int t, n, m, l, V, d[100010], v[100010], a[100010], p[100010], ans1;
bool A = 1, B = 1;
void solveA()
{
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > p[m]) continue;
		if (v[i] > V) ans1++;
	}
	if (ans1 != 0) cout << ans1 << " " << m - 1 << endl;
	else cout << ans1 << " " << m << endl;
}
void solveB()
{
	for (int i = 1; i <= n; i++)
	{
		if (d[i] > p[m]) continue;
		if (v[i] > V) {ans1++; continue;}
		if (V * V - v[i] * v[i] + d[i] * 2 * a[i] >= p[m] * 2 * a[i]) continue;
		ans1++;
	}
	if (ans1 != 0) cout << ans1 << " " << m - 1 << endl;
	else cout << ans1 << " " << m << endl;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios :: sync_with_stdio(false); 
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		ans1 = ans2 = 0;
		cin >> n >> m >> l >> V;
		for (int j = 1; j <= n; j++) 
		{
			cin >> d[j] >> v[j] >> a[j];
			if (a[j] <= 0) B = 0;
			if (a[j] != 0) A = 0;
		}
		for (int j = 1; j <= m; j++) cin >> p[j];
		sort(p + 1, p + m + 1);
		if (A) solveA();
		if (B) solveB();
	}
	return 0;
}
