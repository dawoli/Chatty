#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 10;
ll n, len1, len2, q;
string s1[N], s2[N];
vector<ll> nxt1[N], nxt2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int idx = 1; idx <= n; idx ++) {
		cin >> s1[idx] >> s2[idx];
		s1[idx] = " " + s1[idx];
		s2[idx] = " " + s2[idx];
		nxt1[idx].reserve(s1[idx].size() + 1);
		nxt1[idx].push_back(0);
		nxt1[idx].push_back(0);
		for (int i = 2, j = 0; i < s1[idx].size(); i ++) {
			while (j && s1[idx][i] != s1[idx][j + 1]) j = nxt1[idx][j];
			if (s1[idx][i] == s1[idx][j + 1]) j ++;
			nxt1[idx].push_back(j);
		}
		nxt2[idx].reserve(s2[idx].size() + 1);
		nxt2[idx].push_back(0);
		nxt2[idx].push_back(0);
		for (int i = 2, j = 0; i < s2[idx].size(); i ++) {
			while (j && s2[idx][i] != s2[idx][j + 1]) j = nxt2[idx][j];
			if (s2[idx][i] == s2[idx][j + 1]) j ++;
			nxt2[idx].push_back(j);
		}
	}
	while (q --) {
		string st, ed; cin >> st >> ed;
		st = " " + st; ed = " " + ed;
		len1 = st.size(); len2 = ed.size();
		int l = -1, r = 0;
		while (l + 1 < len1 && l + 1 < len2
		&& st[l + 1] == ed[l + 1]) l ++;
		while (len1 - r - 1 >= 0 && len2 - r - 1 >= 0 &&
		st[len1 - r - 1] == ed[len2 - r - 1]) r ++;
		
		ll ans = 0;

		for (int idx = 1; idx <= n; idx ++) {
			if (len1 - s1[idx].size() + s2[idx].size() != len2) continue;
			set<int> sucidx;
			for (int i = 1, j = 0; i <= len1; i ++) {
				while (j && st[i] != s1[idx][j + 1]) j = nxt1[idx][j];
				if (st[i] == s1[idx][j + 1]) j ++;
				if (j == s1[idx].size() - 1) sucidx.insert(i - s1[idx].size() + 2);
			}
			for (int i = 1, j = 0; i <= len2; i ++) {
				while (j && ed[i] != s2[idx][j + 1]) j = nxt2[idx][j];
				if (ed[i] == s2[idx][j + 1]) j ++;
				if (j == s2[idx].size() - 1
				&& sucidx.count(i - s2[idx].size() + 2)) {
					if (i - s2[idx].size() + 2 <= l + 1 && i + 1 + r >= ed.size())
						ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
