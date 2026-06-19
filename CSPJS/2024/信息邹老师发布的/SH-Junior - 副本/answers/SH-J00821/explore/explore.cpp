#include <bits/stdc++.h> 
using namespace std;
const int f[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool passing[1145][1145];
char mmap[1145][1145];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	vector<int> stream;
	while(T--) {
		memset(passing, 0, sizeof(passing));
		int n, m, k;
		cin >> n >> m >> k;
		int x, y, dir;
		int ans = 0;
		cin >> x >> y >> dir;
		passing[x][y] = 1, ans++;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= m; j++) {
				mmap[i][j] = s[j-1];
			}
		}
		for (int i = 1; i <= k; i++) {
			int x_nxt = x + f[dir][0], y_nxt = y + f[dir][1];
			if ((1 <= x_nxt && x_nxt <= n) && (1 <= y_nxt && y_nxt <= m) && mmap[x_nxt][y_nxt] == '.') {
				x = x_nxt, y = y_nxt;
				if(passing[x][y] == 0) ans++;
				passing[x][y] = 1;
			}
			else dir = (dir + 1) % 4;
		}
		stream.push_back(ans);
	}
	for (int x : stream) {
		cout << x << endl;
	}
	return 0;
}
