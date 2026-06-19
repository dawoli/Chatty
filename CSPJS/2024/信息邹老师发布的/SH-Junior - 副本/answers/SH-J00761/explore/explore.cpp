// explore.cpp
#include <iostream>
#include <cstdio>
using namespace std;
int t;
bool grid[1005][1005];
// vst: wether { i, j } has been visited
bool vst[1005][1005];
struct rbt {
	int x, y, d;
	void read() { cin >> x >> y >> d; }
	// rbt::NxtPos: the expected position after the next movement
	rbt NxtPos() {
		rbt ans;
		switch (d) {
		case 0:
			ans = { x, y + 1, d };
			break; 
		case 1:
			ans = { x + 1, y, d };
			break;
		case 2:
			ans = { x, y - 1, d };
			break;
		case 3:
			ans = { x - 1, y, d };
			break;
		}
		return ans;
	}
	// rbt::update: to commit the actual movement and get wether 
	// the robot has moved to a new position in the grid
	bool update() {
		rbt nxt = NxtPos();
		if (grid[nxt.x][nxt.y]) *this = nxt;
		else d = (d + 1) % 4;
		if (!vst[x][y]) {
			vst[x][y] = true;
			return true;
		}
		else return false;
	}
};
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	while (t--) {
		// query
		int n, m, k;
		rbt cur;
		cin >> n >> m >> k;
		cur.read();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				char c;
				cin >> c;
				grid[i][j] = (c == '.');
				vst[i][j] = false;
			}
		}
		// processing
		vst[cur.x][cur.y] = true;
		int cnt = 1;
		while (k--) cnt += cur.update();
		// output
		cout << cnt << endl;
	}
	return 0;
} 
