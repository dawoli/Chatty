// Problem URL: https://www.luogu.com.cn/problem/P1328
// Finish Time: 2026/10/3 09:41:04 AC
// Start Time: 2026/10/3 09:31:57

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN = 2e2 + 2;

int n, na, nb, a[MAXN], b[MAXN], sa = 0, sb = 0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// freopen("rps.in", "r", stdin);
	// freopen("rps.out", "w", stdout);

	cin >> n >> na >> nb;
	for (int i = 0; i < na; i++)
		cin >> a[i];
	for (int i = 0; i < nb; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		const int &ap = a[i % na], &bp = b[i % nb];
		if ((ap == 0 && (bp == 2 || bp == 3)) ||
			(ap == 1 && (bp == 0 || bp == 3)) ||
			(ap == 2 && (bp == 1 || bp == 4)) ||
			(ap == 3 && (bp == 2 || bp == 4)) ||
			(ap == 4 && (bp == 0 || bp == 1)))
			sa++;
		else if (ap != bp)
			sb++;
	}
	cout << sa << " " << sb << endl;
	return 0;
}