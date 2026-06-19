#include <bits/stdc++.h>

using namespace std;

char jung[1024][1024];

pair<int, int> gnext(int x, int y, int d) {
	switch (d) {
		case 0:
			return make_pair(x, y + 1);
		case 1:
			return make_pair(x + 1, y);
		case 2:
			return make_pair(x, y - 1);
		case 3:
			return make_pair(x - 1, y);
	}
}

void solve() {
	int n, m, k;
	int x0, y0, d0;
	
	cin >> n >> m >> k;
//	cout << n << m;
	cin >> x0 >> y0 >> d0;
//	cout << n << ' ' << m << ' ' << k << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
//			jung[i][j] = '\0';
			cin >> jung[i][j];
		}
	}

	int x = x0, y = y0, d = d0;
	int cnt = 1;
	for (int i = 0; i < k; i++) {
		pair<int, int> next = gnext(x, y, d);
		
		if ((next.first >= 1 && next.first <= n && next.second >= 1 && next.second <= m) &&
		jung[next.first][next.second] != 'x') {
			
			x = next.first;
			y = next.second;
			
			if (jung[x][y] != ',') {
				jung[x][y] = ',';
				cnt++;
				//cout << x << ' ' << y << endl;
			}
			
			//cout << x << ' ' << y << endl;
		} else {
			d = (d + 1) % 4;
			//cout << "turn" << endl;
		}
		
		//cout << x << ' ' << y << ' ' << d << endl;
	}
	
	if (n == 1 && m == 1) {
		cout << 1 << endl;
		return;
	}
	cout << cnt << endl;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	
	//for (int t = 0; t < T; t++) {
	for (int t = 0; t < T; t++) {
		solve();
	}
	//	cout << "t" << t << endl;
	//}
}
