#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
int base = 137, mod = 1e15 - 1;
int pbase[5000005], invpbase[5000005];
string s, t;
int rts[5000005], sons[5000005][26], ncnt, pre[5000005];
unordered_map <int, int> hashpl[5000005];
int fdif(string x, string y) {
	for(int i = 0; i < x.length(); ++i) {
		if(x[i] != y[i]) {
			return i;
		}
	}
}
int ldif(string x, string y) {
	for(int i = x.length(); i >= 0; --i) {
		if(x[i] != y[i]) {
			return i;
		}
	}
}
int gethash(string x) {
	int ret = 0;
	for(int i = x.length() - 1; i >= 0; --i) {
		ret = ((__int128)ret * base + (x[i] - 'a' + 26)) % mod;
	}
	return ret;
}
int gethashtwo(string x) {
	int ret = 0;
	for(int i = x.length() - 1; i >= 0; --i) {
		ret = ((__int128)ret * base + (x[i] - 'a')) % mod;
	}
	return ret;
}
void insert(int rt, string x, int nw) {
	int p = rt;
	for(int i = 0; i < x.length(); ++i) {
		if(!sons[p][x[i] - 'a']) {
			sons[p][x[i] - 'a'] = ++ncnt;
		}
		p = sons[p][x[i] - 'a'];
	}
	++hashpl[p][nw];
}
int seach(string x, string y, int beg, int l, int r, int k) {
	int p = rts[l], ans = 0;
	for(int i = 1; i <= r; ++i) {
		if(!sons[p][x[beg + i - 1] - 'a']) {
			return 0;
		}
		p = sons[p][x[beg + i - 1] - 'a'];
	}
	for(int i = r + 1; i <= x.length() - beg + 1; ++i) {
		ans += hashpl[p][k];
		if(i == x.length() - beg + 1 || !sons[p][x[beg + i - 1] - 'a']) {
			return ans;
		}
		p = sons[p][x[beg + i - 1] - 'a'];
	}
	return ans;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	pbase[0] = invpbase[0] = pre[0] = 1;
	for(int i = 1; i <= 5000000; ++i) {
		pbase[i] = pbase[i - 1] * base % mod;
		invpbase[i] = (__int128)invpbase[i - 1] * 452554744525547ll % mod;
		pre[i] = (pre[i - 1] + pbase[i]) % mod;
	}
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> s >> t;
		int f = fdif(s, t);
		int l = ldif(s, t);
		if(!rts[f + 1]) rts[f + 1] = ++ncnt;
		int k = (gethash(t) - gethashtwo(s) - ((s.length() > l + 1) ? ((int) ((__int128)26 * pbase[l + 1] * pre[s.length() - l - 2] % mod)) : 0ll) - ((f > 0) ? 26 * pre[f - 1] % mod : 0ll) + mod + mod + mod) % mod;
		insert(rts[f + 1], s, k);
	}
	for(int i = 1; i <= q; ++i) {
		cin >> s >> t;
		int f = fdif(s, t);
		int l = ldif(s, t);
		int ans = 0;
		int p = (gethash(t) - gethashtwo(s) - ((s.length() > l + 1) ? ((int) ((__int128)26 * pbase[l + 1] * pre[s.length() - l - 2] % mod)) : 0ll) - ((f > 0) ? 26 * pre[f - 1] % mod : 0ll) + mod + mod + mod) % mod;
		for(int j = 0; j <= f; ++j) {
			ans += seach(s, t, f - j, j + 1, l - f + 1 + j, (__int128)p * invpbase[f - j] % mod);
		}
		cout << ans << endl;
	}
	return 0;
}