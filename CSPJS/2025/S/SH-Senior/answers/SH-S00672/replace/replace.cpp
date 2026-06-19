#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MX = 2e5 + 10;

int n;
struct hsh {
	string *src;
	ll len, p1, mod1, p2, mod2;
	vector<ll> dat1, pp1, dat2, pp2;
	hsh(string *_src, ll _p1, ll _mod1, ll _p2, ll _mod2): src(_src) {
		p1 = _p1;
		mod1 = _mod1;
		p2 = _p2;
		mod2 = _mod2;
	}
	void init() {
		len = (*src).length();
		dat1.resize(len);
		pp1.resize(len + 1);
		pp1[0] = 1;
		for (ll i = 1; i <= len; ++i) {
			pp1[i] = pp1[i - 1] * p1 % mod1;
		}
		dat1[0] = (*src)[0];
		for (ll i = 1; i < len; ++i) {
			dat1[i] = dat1[i - 1] * p1 + (*src)[i];
			dat1[i] %= mod1;
		}
		dat2.resize(len);
		pp2.resize(len + 1);
		pp2[0] = 1;
		for (ll i = 1; i <= len; ++i) {
			pp2[i] = pp2[i - 1] * p2 % mod2;
		}
		dat2[0] = (*src)[0];
		for (ll i = 1; i < len; ++i) {
			dat2[i] = dat2[i - 1] * p2 + (*src)[i];
			dat2[i] %= mod2;
		}
	}
	ll get(ll l, ll r) { // src[l, r]
		return ((dat1[r] - dat1[l] * pp1[r - l + 1] % mod1 + mod1) % mod1)
			  *((dat2[r] - dat2[l] * pp2[r - l + 1] % mod2 + mod2) % mod2)
			  % 998244353;
	}
};
struct term {
	string s1, s2;
	hsh hsh1{&s1, 131, 998244353, 13331, 998234353},
		hsh2{&s2, 131, 998244353, 13331, 998234353};
} s[MX], t[MX];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].s1 >> s[i].s2;
		s[i].hsh1.init();
		s[i].hsh2.init();
		cout << s[i].hsh1.get(0, s[i].hsh1.len - 1) << ' ';
		cout << s[i].hsh2.get(0, s[i].hsh2.len - 1) << '\n';
	}
	for (int i = 1; i <= q; ++i) {
		cin >> t[i].s1 >> t[i].s2;
		t[i].hsh1.init();
		t[i].hsh2.init();
	}
	
	for (int i = 1; i <= q; ++i) {
		
	
	cout.flush();

	return 0;
}

