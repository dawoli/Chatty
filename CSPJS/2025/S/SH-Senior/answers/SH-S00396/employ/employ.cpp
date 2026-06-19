#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, mod = 998244353;
int n, m, c[N], jc[N];
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	jc[0] = 1;
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	cout << jc[n];
	return 0;
}
