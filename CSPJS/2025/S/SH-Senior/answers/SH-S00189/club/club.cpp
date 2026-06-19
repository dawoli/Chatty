#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int t, n;
int64_t cnt;
int cl[3];
vector<int> s[maxn];

bool cmp(vector<int> a, vector<int> b) {
	int am1 = max(a[0], max(a[1], a[2])) - max(min(a[0], a[2]), max(min(a[0], a[1]), min(a[1], a[2])));
	int am2 = max(min(a[0], a[2]), max(min(a[0], a[1]), min(a[1], a[2]))) - min(a[0], min(a[1], a[2]));
	int bm1 = max(b[0], max(b[1], b[2])) - max(min(b[0], b[2]), max(min(b[0], b[1]), min(b[1], b[2])));
	int bm2 = max(min(b[0], b[2]), max(min(b[0], b[1]), min(b[1], b[2]))) - min(b[0], min(b[1], b[2]));
	if (am1 == bm1) {
		return am2 > bm2;
	} else {
		return am1 > bm1;
	}
}

int prf(vector<int> x, int cmd) {
	int tmp;
	if (cmd == 0) {
		tmp = max(x[0], max(x[1], x[2]));
	} else if (cmd == 1) {
		tmp = max(min(x[0], x[2]), max(min(x[0], x[1]), min(x[1], x[2])));
	} else if (cmd == 2) {
		tmp = min(x[0], min(x[1], x[2]));
	}
	for (int i = 0; i < 3; i++) {
		if (x[i] == tmp) {
			return i;
		}
	}
}

int oth(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	if (a == 0) {
		if (b == 1) {
			return 2;
		} else {
			return 1;
		}
	} else if (a == 1) {
		return 0;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cnt = 0;
		memset(cl, 0, sizeof(cl));
		cin >> n;
		for (int i = 0; i < n; i++) {
			s[i].clear();
			s[i].push_back(0);
			s[i].push_back(0);
			s[i].push_back(0);
			cin >> s[i][0] >> s[i][1] >> s[i][2];
		}
		sort(s, s + n, cmp);
		for (int i = 0; i < n; i++) {
			int fp = prf(s[i], 0);
			int sp = prf(s[i], 1);
			int lp = prf(s[i], 2);
			if (fp == sp) sp = oth(fp, lp);
			if (fp == lp) lp = oth(fp, sp);
			if (sp == lp) lp = oth(fp, sp);
			if (cl[fp] < n / 2) {
				cl[fp]++;
				cnt += s[i][fp];
			} else if (cl[sp] < n / 2) {
				cl[sp]++;
				cnt += s[i][sp];
			} else {
				cl[lp]++;
				cnt += s[i][lp];
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
