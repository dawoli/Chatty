#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int h1[1010][2010], h2[1010][2010], hh1[2010], hh2[2010], cf[1010];
string s[1010][5], t[1010][5];
int n, q;
void solve1() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < s[i][1].size(); j++) {
			h1[i][j] = (h1[i][j - 1] * 233ll + s[i][1][j] - 'a') % mod;
		}
		for(int j = 1; j < s[i][2].size(); j++) {
			h2[i][j] = (h2[i][j - 1] * 233ll + s[i][2][j] - 'a') % mod;
		}
	}
	for(int i = 1; i <= q; i++) {
		int cnt = 0;
		for(int j = 1; j < t[i][1].size(); j++) {
			hh1[j] = (hh1[j - 1] * 233ll + t[i][1][j] - 'a') % mod;
			hh2[j] = (hh2[j - 1] * 233ll + t[i][2][j] - 'a') % mod;
		}
		for(int j = 1; j < t[i][1].size(); j++) {
			for(int k = 1; k <= n; k++) {
				int len = s[k][1].size() - 1;
				if(j < len) continue;
				if((hh1[j] - hh1[j - len] * 1ll * cf[len] % mod + mod) % mod == h1[k][len] && (hh2[j] - hh2[j - len] * 1ll * cf[len] % mod + mod) % mod == h2[k][len]) {
					int ll = t[i][1].size() - 1, lll = ll - j;
					if(hh1[j - len] == hh2[j - len] && (hh1[ll] - hh1[j] * 1ll * cf[lll] % mod + mod) % mod == (hh2[ll] - hh2[j] * 1ll * cf[lll] % mod + mod) % mod) {
						cnt++;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	int l1 = 0, l2 = 0;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		l1 += s[i][1].size() + s[i][2].size();
		s[i][1] = '#' + s[i][1];
		s[i][2] = '#' + s[i][2];
	}
	for(int i = 1; i <= q; i++) {
		cin >> t[i][1] >> t[i][2];
		l2 += t[i][1].size() + t[i][2].size();
		t[i][1] = '#' + t[i][1];
		t[i][2] = '#' + t[i][2];
	}
	cf[0] = 1;
	for(int i = 1; i <= n; i++) cf[i] = cf[i - 1] * 233ll % mod; 
	if(n <= 1000 && q <= 1000 && l1 <= 2000 && l2 <= 1000) {
		solve1();
	}
}
