#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
priority_queue<int> q1, q2;
int n;
int r[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
	}
	sort(r + 1, r + 1 + n);
	for (int i = n - 1; i >= 1; --i) {
		q1.push(r[i]);
		q2.push(r[i]);
	}
	q1.push(r[n]);
	int cnt = 0;
	while (q1.size() && q2.size()) {
		int m1 = q1.top(), m2 = q2.top();
		// cerr << m1 << ' ' << m2 << endl;
		if (m1 > m2) {
			q1.pop();
			q2.pop();
			++cnt;
		} else if (m1 == m2) {
			q2.pop();
		} else if (m1 < m2) {
			break;
		}
	}
	cout << n - cnt << endl;
	// ------------------------
	// #ifdef LOCAL
	// cerr << "\n[Finished]" << endl;
	// getchar();
	// #endif
	return 0;
}