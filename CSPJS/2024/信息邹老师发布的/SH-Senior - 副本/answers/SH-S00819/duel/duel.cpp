#include<bits/stdc++.h>
# define rep(i, j, k) for (int i = j; i <= k; ++i)
using namespace std;

int n, r[100005], pos = 1;

signed main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> r[i];
	sort(r + 1, r + n + 1);
	rep(i, 1, n) if (r[pos] < r[i]) ++pos;
	cout << n - pos + 1 << '\n';
	return 0;
}
