#include <bits/stdc++.h> 
using namespace std;
#define int unsigned long long
const int N = 2e5 + 7, M = 5e6 + 7, P = 31;
bool st;
int n, q, tot, hsA[N], hsB[N];
string s[N][3];
int hs1[N], hs2[N], ct1[N], ct2[N];
map<int, int> mp;
int hs(string s) {
	int x = 0;
	for (auto c : s) x = x * P + c - 'a';
	return x;
}
int hsX[M], hsY[M];
bool en;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	cout << (&en - &st) / 1024. / 1024 << endl;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][1] >> s[i][2];
		int len = s[i][1].size();
		s[i][1] = " " + s[i][1];
		s[i][2] = " " + s[i][2];
		int Mn = 1e18, Mx = 0;
		for (int j = 1; j <= len; ++j)
			if (s[i][1][j] != s[i][2][j])
				Mn = min(Mn, j), Mx = max(Mx, j);
		if (Mx == 0) continue; 
		for (int j = Mn - 1; j; --j)
			hs1[i] = hs1[i] * P + s[i][1][j] - 'a';
		for (int j = Mx + 1; j <= len; ++j)
			hs2[i] = hs2[i] * P + s[i][1][j] - 'a';
		ct1[i] = Mn - 1, ct2[i] = len - Mx;
		for (int j = Mn; j <= Mx; ++j)
			hsA[i] = hsA[i] * P + s[i][1][j] - 'a';
		for (int j = Mn; j <= Mx; ++j)
			hsB[i] = hsB[i] * P + s[i][2][j] - 'a';
	}
	while (q--) {
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size(), hsa = 0, hsb = 0;
		s1 = " " + s1;
		s2 = " " + s2;
		int Mn = 1e18, Mx = 0;
		for (int j = 1; j <= len; ++j)
			if (s1[j] != s2[j])
				Mn = min(Mn, j), Mx = max(Mx, j);
		for (int j = Mn; j <= Mx; ++j)
			hsa = hsa * P + s1[j] - 'a';
		for (int j = Mn; j <= Mx; ++j)
			hsb = hsb * P + s2[j] - 'a';
		int t1 = 0, t2 = 0, cur1 = 0;
		for (int j = Mn - 1; j; --j) {
			t1 = t1 * P + s1[j] - 'a';
			hsX[++cur1] = t1;
		}
		int cur2 = 0;
		for (int j = Mx + 1; j <= len; ++j) {
			t2 = t2 * P + s2[j] - 'a';
			hsY[++cur2] = t2;
		}
		int ct = 0;
		for (int i = 1; i <= n; ++i) {
			bool f1 = hsa == hsA[i] && hsb == hsB[i];
			bool f2 = ct1[i] <= cur1 && hsX[ct1[i]] == hs1[i];
			bool f3 = ct2[i] <= cur2 && hsY[ct2[i]] == hs2[i];
			if (f1 && f2 && f3) ++ct;
		}
		cout << ct << endl;
	}
}
