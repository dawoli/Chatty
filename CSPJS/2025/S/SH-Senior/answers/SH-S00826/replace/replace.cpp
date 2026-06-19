#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;
struct trans { ull from, to; };
constexpr int BASE = 131, MAXN = 1e6;
ull Hash(const string& str, int l, int r) {
	ull ans = 0;
	for (int i = l; i <= r; ++i)
		ans = ans * BASE + (str[i] - 'a' + 1);
	return ans;
}
int n, q;
string s1, s2, t1, t2;
int len1, len2, ans;
vector<trans> p[1000005];
int solve() {
	cin >> t1 >> t2;
	len1 = t1.size();
	if (len1 != t2.size())
		return 0;
	ans = 0;
	for (int i = 0; i < len1; ++i) {
		if (i && t1[i - 1] != t2[i - 1]) break;
		ull hash1 = Hash(t1, i, len1 - 1);
		ull hash2 = Hash(t2, i, len1 - 1);
		for (int j = len1 - 1; j >= i; --j) {
			if (j < len1 - 1 && t1[j + 1] != t2[j + 1])
				break;
			const int idx = hash1 % MAXN;
			for (int k = 0; k < p[idx].size(); ++k)
				ans += (p[idx][k].from == 
					hash1 && p[idx][k].to == hash2);
			hash1 /= BASE;
			hash2 /= BASE;
		}
	}
	return ans;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		const ull hash1 = Hash(s1, 0, s1.size() - 1);
		const ull hash2 = Hash(s2, 0, s2.size() - 1);
		p[hash1 % MAXN].push_back({ hash1, hash2 });
	}
	while (q--)
		cout << solve() << endl;
	return 0;
}
