#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n, k, a[N], s[N], lst, ans;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j > lst; j--)
			if ((s[i] ^ s[j - 1]) == k)
				lst = i, ans++;
	cout << ans; 
	return 0;
}
// ÉÙÓðÅ£±Æ
