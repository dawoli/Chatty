#include <bits/stdc++.h>
using namespace std;

const int N = 10 + 5, R = 100 + 5;
int n, m;
int a[R];

struct Score {
	int id, sc;
}s[R];

bool cmp(Score a, Score b) {
	return a.sc > b.sc;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
		s[i].id = i;
		s[i].sc = a[i];
	}
	sort(s + 1, s + n * m + 1, cmp);
	int cur = 0;
	for (int i = 1; i <= m; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; ++j) {
				if (s[++cur].id == 1) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; --j) {
				if (s[++cur].id == 1) {
					cout << i << " " <<  j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
