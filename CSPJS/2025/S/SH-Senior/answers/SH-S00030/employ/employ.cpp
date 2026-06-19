#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 505
#define MOD 998244353

int n, m;
int s[N];
int c[N];

int p[N];

bool flagA; 

void bf() {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		int cnt0 = 0;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 1) {
				if (cnt0 < c[p[i]]) {
					res++;
				} else {
					cnt0++;
				}
			} else {
				cnt0++;
			}
		}
		if (res >= m) {
			ans++;
		}
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
}

int mul[N];

void A() {
	mul[1] = 1;
	for (int i = 2; i <= n; i++) {
		mul[i] = mul[i - 1] * i % MOD;
	}
	
	int cntc0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			cntc0++;
		}
	}
	if (n - cntc0 >= m) {
		cout << mul[n] << endl;
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string ss;
	cin >> ss;
	flagA = 1;
	for (int i = 1; i <= n; i++) {
		s[i] = ss[i - 1] - '0';
		if (s[i] == 0) {
			flagA = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n <= 10) {
		bf();
	} else if (flagA) {
		A();
	}
}
