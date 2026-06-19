#include <bits/stdc++.h>
using namespace std;
int n, m;
struct STR{
	int sc, id;
} a[100005];
bool cmp(STR a, STR b) {
	return a.sc > b.sc;
}

int main() {
	freopen("seat.in", "r", stdin);	
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[(i - 1) * n + j].id == 1) {
				if (i % 2 == 1) cout << i << " " << j << "\n";
				else cout << i << " " << n - j + 1 << "\n";
				return 0;
			}
		}
	}
	return 0;
}

