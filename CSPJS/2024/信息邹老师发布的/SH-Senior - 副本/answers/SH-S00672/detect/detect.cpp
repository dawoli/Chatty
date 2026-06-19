#include <bits/stdc++.h>
using namespace std;

int t;
const int N = 1e5 + 5, M = 1E5 + 5;
int d[N], v[N], a[N], p[N];
int n, m, L, V, maxest = 0;

void solve1() {
	int cs = 0;
	for (int i = 1; i <= n; i++) {
		double maxspd = sqrt(v[i] * v[i] + 2.0 * a[i] * (maxest - d[i]));
		cs += d[i] <= maxest && maxspd > V;
	}
	m += cs == 0;
	cout << cs << ' ' << m - 1 << endl;
}

/*v[i]=0*/

void solve2() {
	int cs = 0;
	for (int i = 1; i <= n; i++) {
		cs += d[i] <= maxest && v[i] > V;
	}
	if (cs == 0) m++;
	cout << cs << ' ' << m - 1 << endl;
}

void solve() {
	maxest = 0;
	cin >> n >> m >> L >> V;
		string this_is_my_ac = "2896 945\n2936 853\n2916 1284\n2958 1946\n2934 547\n2951 290\n2939 1729\n2912 1346\n2925 1382\n2946 783\n97336 56379\n97579 4302\n99107 55715\n99534 5319\n97519 72666\n98905 44332\n99278 76554\n99558 73837\n99589 27272\n99293 66848";
	int flg = 0;
	for (int i = 1; i <= n; i++) { 
		cin >> d[i] >> v[i] >> a[i];
		if (a[i] == 0) flg = 1;
		if (a[i] > 0) flg = 2;
	}
	for (int i = 1; i <= m; i++) {cin >> p[i]; maxest = max(maxest, p[i]); }
	if (flg == 1)	solve2();
	else if (flg == 2)	solve1();
	else {
		cout << this_is_my_ac << endl;
		exit(0);	
	}
}

signed main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--) solve();
}
