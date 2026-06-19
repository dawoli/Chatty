#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef string str;
typedef pair<str, str> ps;

struct Edge {
	int to, l;
	Edge(int x, int y) {
		to = x; l = y;
	}
};

const int N = (int)2e2 + 11;
int n, q;
map<ps, pair<int, vector<ps> > > H;

pair<ps, ps> check_eq(str x, str y, int l) {
	int i = 0, j = l - 1;
	while (i < l && x[i] == y[i])
		++i;
	str qs = x.substr(0, i);
	while (j >= 0 && x[j] == y[j])
		--j;
	str hs = x.substr(j + 1, l - j - 1);
	str mx = x.substr(i, j - i + 1), my = y.substr(i, j - i + 1);
	return {{qs, hs}, {mx, my}};
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string x, y;
		cin >> x >> y;
		if (x == y)
			continue;
		pair<ps, ps> st = check_eq(x, y, (int)x.size());
		H[st.se].fi++;
		(H[st.se].se).push_back(st.fi);
	}
	while (q--) {
		string x, y;
		cin >> x >> y;
		int l = (int)x.size();
		pair<ps, ps> st = check_eq(x, y, l);
		str z = st.fi.fi + st.se.fi;
		int i = (int)st.fi.fi.size(), j = (int)z.size();
		if (H.find({st.se}) == H.end())
			cout << "0\n";
		else {
			int ans = 0;
			int len = H[st.se].fi;
			for (int k = 0; k < len; k++) {
				ps u = H[st.se].se.at(k);
				str qs = u.fi, hs = u.se;
				int lq = (int)qs.size(), lh = (int)hs.size();
				if (lq > i || lh > l - j)
					continue;
				if (x.substr(i - lq, lq) == qs && x.substr(j, lh) == hs)
					++ans;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
