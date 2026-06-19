#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> pii;
typedef pair<pii, int> piii;
const int N = 200005, LEN = 5000005;
const ull P = 31;

namespace {
int n, q;
int lenS[N], lenT;
int cnt[2][26];
bool flag;
ull pw[LEN];
vector<ull> hs[N][2], h[2];
string S[N][2], T[2];
piii rk[N];

void MAIN() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	for(int i = 1; i <= LEN - 5; ++i) pw[i] = pw[i - 1]*P;
	for(int i = 1; i <= n; ++i) {
		cin >> S[i][0] >> S[i][1];
		lenS[i] = S[i][0].size();
		hs[i][0].resize(lenS[i]);
		hs[i][1].resize(lenS[i]);
		for(int j = 0; j < 26; ++j) cnt[0][j] = cnt[1][j] = 0;
		for(int j = 0; j < lenS[i]; ++j) {
			hs[i][0][j] = S[i][0][j] - 'a' + (j ? hs[i][0][j - 1] : 0ULL)*P;
			hs[i][1][j] = S[i][1][j] - 'a' + (j ? hs[i][1][j - 1] : 0ULL)*P;
			++cnt[0][S[i][0][j] - 'a'];
			++cnt[1][S[i][1][j] - 'a'];
		}
		if(cnt[0][0] + cnt[0][1] < lenS[i] || cnt[1][0] + cnt[1][1] < lenS[i] || cnt[0][1] > 1 || cnt[1][1] > 1) flag = 1;
		rk[i] = {{hs[i][1][lenS[i] - 1] - hs[i][0][lenS[i] - 1], hs[i][1][lenS[i] - 1] ^ hs[i][0][lenS[i] - 1]}, i};
	}
	sort(rk + 1, rk + n + 1);
	for(int i = 1; i <= q; ++i) {
		int ans = 0;
		cin >> T[0] >> T[1];
		lenT = T[0].size();
		h[0].resize(lenT);
		h[1].resize(lenT);
		for(int j = 0; j < lenT; ++j) {
			h[0][j] = T[0][j] - 'a' + (j ? h[0][j - 1] : 0ULL)*P;
			h[1][j] = T[1][j] - 'a' + (j ? h[1][j - 1] : 0ULL)*P;
		}
		for(int j = lenT - 1; j >= 0; --j) {
			int t = lower_bound(rk + 1, rk + n + 1, mp(mp(h[1][j] - h[0][j], h[1][j] ^ h[0][j]), 0)) - rk;
			for(int k = t; k <= n; ++k) {
				if(rk[k].fi.fi != h[1][j] - h[0][j] || rk[k].fi.se != (h[1][j] ^ h[0][j])) break;
				int id = rk[k].se, l = j - lenS[id] + 1, r = j;
				if(j < lenS[id] - 1) continue;
				if(hs[id][0][lenS[id] - 1] == (h[0][r] - (l ? h[0][l - 1] : 0ULL)*pw[r - l + 1])) ++ans;
			}
			if(T[0][j] != T[1][j]) break;
		}
		cout << ans << '\n';
	}
}
}

int main() {
	MAIN();
	return 0;
}
