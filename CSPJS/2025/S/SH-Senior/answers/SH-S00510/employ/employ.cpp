#include <bits/stdc++.h>
using namespace std;
long long n, m, c[505], ans = 1, p;
string s;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if(c[i] == 0)  p++;
	}
	if(n-p < m) {
		cout << 0;
		return 0;
	} 
	for(int i = n-p; i >= 1; i--) ans = ans * i % 998244353;
	cout << n-p << ' ' << ans;
	return 0;
} 

