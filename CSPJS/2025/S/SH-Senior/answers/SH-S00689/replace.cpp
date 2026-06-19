// replace

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10, H = 131, MOD = 998244353;
int gH1[N], gH2[N], gP[N], gT1[N], gT2[N], gLen[N];
string gS[N][2];

inline int Query1(int l, int r) {
	return ((gH1[r] - gH1[l - 1] * gP[r - l + 1] % MOD) % MOD + MOD) % MOD;
}

inline int Query2(int l, int r) {
	return ((gH2[r] - gH2[l - 1] * gP[r - l + 1] % MOD) % MOD + MOD) % MOD;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	
	gP[0] = 1;
	for (int i = 1; i < N; i++)
		gP[i] = (gP[i - 1] * H) % MOD;
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> gS[i][0] >> gS[i][1];
		
		gLen[i] = gS[i][0].size();
		for (int j = 0; j < gLen[i]; j++) {
			gT[i][0] = (gT[i][0] * H + gS[i][0] - 'a' + 1) % MOD;
			gT[i][1] = (gT[i][1] * H + gS[i][1] - 'a' + 1) % MOD;
		}
	}
	
	while (q--) {
		string a, b;
		cin >> a >> b;
		
		int len = a.size();
		
		if (b.size() != a.size()) cout << "0\n";
		else {
			a = " " + a, b = " " + b;
			for (int i = 1; i <= len; i++) {
				gH1[i] = (gH1[i - 1] * H + a[i] - 'a' + 1) % MOD;
				gH2[i] = (gH2[i - 1] * H + b[i] - 'a' + 1) % MOD;
			}
			
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= len - gLen[i] + 1; j++)
					if (Query1(j, j + gLen[i] - 1) == gT1[i] && Query2(j, j + gLen[i] - 1) == gT2[i]) {
						a -= Query1(j, j + gLen[i] - 1) *
					}
		}
		
		for (int i = 0; i <= len + 5; i++)
			gH1[i] = gH2[i] = 0;
	}
	
	return 0;
}
