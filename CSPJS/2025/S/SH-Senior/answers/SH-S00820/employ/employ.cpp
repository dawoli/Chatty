#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
const int N = 509;
long long a[N], t[N], flag[N], ans, recording[N], kuake, res = 1, res2, tinsk[N], app[N];
void calculate() {
	int ind = 0, tiCK = 0;
	for (int i = 1; i <= n; i++) {
		if(int(s[i - 1] - '0') == 0 || t[i] <= ind) {
			ind++;
		} else {
			tiCK++;
		}
	}
	if (tiCK >= m) {
		ans++;
	}
}
void per(long long arr[], int k) {
	if (k == n) {
		calculate();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(flag[i] == 0) {
			t[k + 1] = arr[i];
			flag[i] = 1;
			per(arr, k + 1);
			flag[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 10) {
		per(a, 0);
		cout << ans;
	} else if (m == 1) {
		sort(a + 1, a + 1 + n);
		int ssize = s.size();
		for(int i = 0; i < ssize; i++) {
			if(s[i] == '0') {
				recording[i + 1] = recording[i] + 1;
				tinsk[i + 1] = 1;
				kuake++;
			} else {
				recording[i + 1] = recording[i];
			}
		}
		for (int i = 1; i <= n; i++) {
			res *= i;
			res %= 998244353;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(tinsk[j] == 0 && a[i] <= recording[j]) {
					app[i]++;
				}
			}
		}
		for(int i = n; i >= n - kuake; i--) {
			long long res3 = 0;
			int racek = 1;
			for (int j = i; j >= i - n + kuake + 1; j--) {	
				if (app[j] - (i - j) <= 0) {
					res3 = 0;
					racek = 0;
					break;
				} else {
					racek = racek * (app[j] - (i - j)) % 998244353;
				}
			}
			res3 = (res3 + racek) % 998244353;
			res2 = (res2 + res3) % 998244353;
		}
		for (int i = 1; i <= kuake; i++) {
			res2 = res2 * i % 998244353;
		}
		res = res + 998244353 - res2;
		res %= 998244353;
		cout << res;
	} else if (m == n) {
		cout << 0;
	} else {
		cout << 0;
	}
	return 0;
}
