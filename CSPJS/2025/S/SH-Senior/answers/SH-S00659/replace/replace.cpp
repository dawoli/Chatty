#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str1 t[z][1]
#define str2 t[z][2]
const int N=2e5+5, Q=2e5+5;
ll n, q;
struct Str {
	string s1, s2;
} s[N];
bool cmp (Str a, Str b) {
	return a.s1.size() > b.s1.size();
}
string t[Q][3];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	sort (s+1, s+n+1, cmp);
	for (int z = 1; z <= q; z++) {
		cin >> str1 >> str2;
		ll len1 = str1.size(), len2 = str2.size();
		
		if (len1 != len2) {
			cout << 0 << endl;
			continue;
		}
		//льеп 
		
		ll l, r;
		for (int i = 0; i < len1; i++) {
			if (str1[i] != str2[i]) {
				l = i;
				break;
			}
		}
		for (int i = len1-1; i >= 0; i--) {
			if (str1[i] != str2[i]) {
				r = i;
				break;
			}
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			ll leng = s[i].s1.size();
			if (leng > len1) continue;
			if (leng < r-l+1) break;
			for (int j = max(r-leng+1, (ll)0); j <= l; j++) {
				if (str1.substr(j, leng) == s[i].s1 && str2.substr(j, leng) == s[i].s2) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
