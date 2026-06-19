#include <bits/stdc++.h>
using namespace std;

const int N = 505, mod = 998244353;
int n, m, ans, c[N];
bool use[N], A = 1;
string s;

void dfs(int pos, int cnt, int fail) {
	if(cnt >= m)  {
		ans ++;
		ans %= mod;
	}
	if(pos > n) {
		return;
	}
	//cout << pos << " " << cnt << " " << fail << endl;
	for(int i = 1; i <= n; i++) {
		if(use[i]) continue;
		if(fail >= c[i]) continue;
		use[i] = 1;
		if(s[pos] == '1') dfs(pos + 1, cnt + 1, fail);
		else dfs(pos + 1, cnt, fail + 1); 
		use[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if(s[i] != '1') A = 0;
	}
	if(A) {
		int cnt = n;
		for(int i = 1; i <= n; i++) if(!c[i]) cnt--;
		if(cnt + 1 < m) {
			cout << 0;
			return 0;
		}
		if(cnt + 1 == m) {
			long long res = 1;
			for(int i = 1; i < n; i++)
				(res *= (n - i)) %= mod;
			cout << res;
			return 0;
		}
		long long res = 1;
		for(int i = 0; i < n; i++)
			(res *= (n - i)) %= mod;
		cout << res;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
}
