// Problem URL: https://www.luogu.com.cn/problem/P3137
// Finish Time: 2026/9/1 16:31:51 AC
// Start Time: 2026/9/1 16:16:40

#include <bits/stdc++.h>
#define int ll
#define endl '\n'
using namespace std;
typedef long long ll;
const int		  MAXN = 1e3 + 3;

struct Node
{
	int nxt, lft = 0, d = 0;
} b[MAXN * 2];

int n, ans = 0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i].lft;
		b[i].nxt = i + 1;
	}
	b[n].nxt = 1;
	int p	 = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		if (b[p].lft > 1)
		{
			b[b[p].nxt].lft += b[p].lft - 1;
			b[b[p].nxt].d += b[p].lft - 1;
			b[p].lft = 1;
		}
		p = b[p].nxt;
	}
	for (int i = 1; i <= n; i++)
		ans += b[i].d * b[i].d;
	cout << ans << endl;
	return 0;
}

// Deep in the dark, I don't need the light
// There's a ghost inside me
// It all belongs to the other side
// We live, we love, we lie