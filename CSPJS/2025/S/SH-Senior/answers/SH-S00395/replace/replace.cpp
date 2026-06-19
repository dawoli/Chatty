#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, M = 5e6 + 5, B = 29;
int n, q, l[N], r[N], p[M];
string s[N][2], t1, t2;
vector<int> hs[N][2];

int cl(string &s1, string &s2) {
	int l1 = s1.size(), l2 = s2.size();
	for (int j = 0; j < min(l1, l2); j++)
		if (s1[j] != s2[j])
			return j;
	return -1;
}

int cr(string &s1, string &s2) {
	int l1 = s1.size(), l2 = s2.size();
	for (int j = 1; j <= min(l1, l2); j++)
		if (s1[l1 - j] != s2[l2 - j])
			return j - 1;
	return -1;
}

int find(vector<int> &Hs, int L, int R) {
	if (!L)
		return Hs[R];
	return Hs[R] - Hs[L - 1] * p[R - L + 1];
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		int len0 = s[i][0].size(), len1 = s[i][1].size();
		hs[i][0].resize(len0), hs[i][1].resize(len1);
		for (int j = 0; j < len0; j++) {
			if (j)
				hs[i][0][j] = hs[i][0][j - 1] * B + (s[i][0][j] - 'a' + 1);
			else
				hs[i][0][j] = s[i][0][j] - 'a' + 1;
		}
		for (int j = 0; j < len1; j++) {
			if (j)
				hs[i][1][j] = hs[i][1][j - 1] * B + (s[i][1][j] - 'a' + 1);
			else
				hs[i][1][j] = s[i][1][j] - 'a' + 1;
		}
		l[i] = cl(s[i][0], s[i][1]); 
		r[i] = cr(s[i][0], s[i][1]);
	}
	p[0] = 1;
	for (int i = 1; i <= M; i++)
		p[i] = p[i - 1] * B;
	while (q--) {
		cin >> t1 >> t2;
		int l1 = t1.size(), l2 = t2.size(), l0 = cl(t1, t2), r0 = cr(t1, t2);
		vector<int> hs1(l1), hs2(l2);
		for (int j = 0; j < l1; j++) {
			if (j)
				hs1[j] = hs1[j - 1] * B + (t1[j] - 'a' + 1);
			else
				hs1[j] = t1[j] - 'a' + 1;
		}
		for (int j = 0; j < l2; j++) {
			if (j)
				hs2[j] = hs2[j - 1] * B + (t2[j] - 'a' + 1);
			else
				hs2[j] = t2[j] - 'a' + 1;
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (l[i] == -1 || l0 < l[i] || r0 < r[i])
				continue;
			int L1 = l0 - l[i], R1 = l1 - r0 - 1 + r[i];
			int L2 = l0 - l[i], R2 = l2 - r0 - 1 + r[i];
			if (find(hs1, L1, R1) != find(hs[i][0], 0, s[i][0].size() - 1))
				continue;
			if (find(hs2, L2, R2) != find(hs[i][1], 0, s[i][1].size() - 1))
				continue;
			res++;
		}
		printf("%lld\n", res);
	}
	return 0;
}

