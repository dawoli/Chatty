#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 200009;

int n, a[N];

signed main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans =0;
	for (int i = 1; i <= n;)
	{
		int x = a[i], j = i;
		while(a[j] == x && j <= n) j ++;
		ans = max(ans, j-i);
		i=j;
	}
	cout << ans << endl;
	return 0;
}

