#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200001;
const long long mod = 998244353;
int n, q;
string s[N][2];
string t1, t2;
// ll hs[N];
// ll qpow (ll a, ll b) {
	// a %= mod;
	// ll ans = 1;
	// while (b) {
		// if (b&1)
			// ans = (ans * a) % mod;
		// a = (a*a) % mod;
		// b >>= 1;
	// }
	// return a;
// }
// struct Hash {
	// Hash() {}
	// long long operator() (const string &a, const string &b) {
		// ll hsh = 0;
		// for (int i = 0; i < a.length(); i++) {
			// if (a[i] == b[i]) {
				// hsh += 37;
				// continue;
			// }
			// hsh += (3147*((ll)qpow(a[i]*17-b[i]*37, 6453)+442)%mod+673);
			// hsh %= mod;
		// }
		// return hsh;
	// }
// };
// Hash hsh;
// void s5() {
	// int f, l;
	// for (int i = 0; i < t1.length(); i++) {
		// if (t1[i] != t2[i]) {
			// f = i;
			// break;
		// }
	// }
	// for (int i = t1.length()-1; i >= 0; i--) {
		// if (t1[i] != t2[i]) {
			// l = i;
			// break;
		// }
	// }
	// string fs1, fs2;
	// for (int i = f; i <= l; i++)
		// fs1 += t1[i], fs2 += t2[i];
	// int ans = 0;
	// ll fsh = hsh(fs1, fs2);
	// for (int i = 1; i <= n; i++)
		// if (hs[i] == fsh)
			// ++ans;
	// cout << ans << endl;
// }
void solvebf() {
	while (q--) {
		cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x1 = t1.find(s[i][0]);
			int x2 = t2.find(s[i][1]);
			if (x1 == x2 && x1 != string::npos) {
				int x3 = t1.find(s[i][0], x1+1);
				int x4 = t2.find(s[i][0], x2+1);
				ans += (x3 == x4) && (x3 == string::npos);
			}
		}
		cout << ans << endl;
	}
}
int main() {
	 freopen("replace.in", "r", stdin);
	 freopen("replace.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0] >> s[i][1];
	if (n <= 100 || q == 1) 
		solvebf();
	return 0;
}
