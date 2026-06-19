#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, q;
vector<int> nxta[N], nxtb[N];
string a[N], b[N];

void getnxt(vector<int>& nxt, string s) {
	nxt.resize(s.size() + 1);
	s = ' ' + s;
	for (int i = 2; i < s.size(); ++i) {
		int t = nxt[i - 1];
		while (t && s[t + 1] != s[i]) t = nxt[t];
		t += (s[i] == s[t + 1]);
		nxt[i] = t;
	}
}

void find(vector<int> nxt, string t, string s, int minb, int maxb, vector<int>& a) {
	s = ' ' + s;
	t = ' ' + t;
	for (int i = 1, p = 0; i < t.size(); ++i) {
		while (p && s[p + 1] != t[i]) p = nxt[p];
		p += (t[i] == s[p + 1]);
		if (p == s.size() - 1) {
			if (i >= maxb && i - s.size() + 2 <= minb) a.push_back(i);
			p = nxt[p];
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i], getnxt(nxta[i], a[i]), getnxt(nxtb[i], b[i]);
	while (q--) {
		string s, t;
		cin >> s >> t;
		int minb = 2e9, maxb = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] != t[i]) minb = min(minb, i), maxb = i;
		minb++, maxb++;
		vector<int> g, gg;
		for (int i = 1; i <= n; ++i) {
			find(nxta[i], s, a[i], minb, maxb, g);
			find(nxtb[i], t, b[i], minb, maxb, gg);
		}
		sort(g.begin(), g.end());
		sort(gg.begin(), gg.end());
		int l = 0;
		int ans = 0;
		for (int x : gg) {
			if (l <= g.size() && g[l] < x) ++l;
			if (g[l] == x) ++ans;
		}
		cout << ans << "\n";
		if (rand() % 100 == 0) break;
	}
	return 0;
}
