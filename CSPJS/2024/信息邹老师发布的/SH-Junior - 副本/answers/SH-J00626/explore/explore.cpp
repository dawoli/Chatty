#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m, k;
		char map[1001][1001] = {};
		cin >> n >> m >> k;
		int x, y, d;
		cin >> x >> y >> d;
		for (int j = 0; j < n; j++) cin >> map[j];
		set<pair<int, int>> went;
		went.emplace(make_pair(x, y));
		for (int moves = 0; moves < k; moves++) {
			int x1 = x, y1 = y;
			if (d == 0) y1++;
			else if (d == 1) x1++;
			else if (d == 2) y1--;
			else if (d == 3) x1--;
			if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && map[x1-1][y1-1] == '.') {
				x = x1, y = y1;
				went.emplace(make_pair(x, y));
			} else {
				d = (d+1) % 4;
			}
		}
		cout << went.size() << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
