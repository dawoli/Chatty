#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string s;
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	long long res = 1;
	bool flag = 1;
	for (int i = 1; i <= n; i++)
		cin >> c[i], res = (res * i) % mod, flag = flag && (c[i] != 0);
	cout << ((flag && m != n) ? res % mod : 0);
	return 0;
}
