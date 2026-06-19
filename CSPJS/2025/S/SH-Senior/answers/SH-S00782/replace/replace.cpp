#include <iostream>
#include <string>
using namespace std;
using i64 = long long;
const int MAXN = 5e6 + 5;
string s[MAXN][5], t[MAXN][5];
int pi[MAXN], ans[MAXN], tot;
int prefix[MAXN][5];
void solve(string c) {
	for (int i = 1; i < c.size(); ++i) {
		int j = pi[i - 1];
		while (j > 0 && c[i] != c[j]) j = pi[j - 1];
		if (c[i] == c[j]) ++j;
		pi[i] = j;
	}
	return ;
}
void kmp(string text, string pattern) {
	int sz1 = pattern.size(), sz2 = text.size();
	string c = pattern + '#' + text;
	solve(c);
	for (int i = sz1; i <= sz1 + sz2; ++i)
		if (pi[i] == sz1) ans[++tot] = i - sz1 * 2; 
}
signed main() {
	/*string a = "12312312";
	string b = "12";
	kmp(a, b);
	for (int i = 1; i <= tot; ++i) cout << ans[i] << " ";
	cout << "\n"; 
	for (int i = 1; i <= 10; ++i) cout << pi[i] << " ";
	cout << "\n";*/
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; ++i) cin >> t[i][1] >> t[i][2];
	for (int i = 1; i <= q; ++i) {
		i64 ans = 0;
		for (int j = 1; j <= n; ++j) {
			kmp(t[i][1], s[j][1]);
			tot = 0;
			for (int k = 1; k <= tot; ++k) {
				string tmp = t[i][1];
				for (int i = ans[k]; i <20; ++i); 
				for (int h = ans[k]; h < ans[k] + (i64)s[i][1].size(); ++h) tmp[h] = s[i][2][h - ans[k]];
				bool flag = 1;
				for (int m = 0; m < tmp.size(); ++m)
					if (tmp[m] != s[i][2][m]) {
						flag = 0;
						break;
					}
				if (flag) ++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
