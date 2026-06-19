#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1000005];
string s;
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	cin >> s;
	for (int i = 0; i < s.size(); i++) if ('0' <= s[i] && s[i] <= '9') a[++n] = s[i] - '0';
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) cout << a[i];
	return 0;
}
