#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
using namespace std;

int t, n, m, k, x, y, d, a[1000][1000];
char map[1000][1000];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
    cin >> t; while (t--) {
    	cin >> n >> m >> k >> x >> y >> d; x--; y--; int cnt = 0;
    	for (int i = 0; i < n; i++) {cin >> map[i]; for (int j = 0; j < m; j++) a[i][j] = 0;}
        a[x][y] = 1;
        while (k--) {
        	int x_ = x, y_ = y;
        	if (d == 0) y_++; else if (d == 1) x_++; else if (d == 2) y_--; else x_--;
        	if (!(0 <= x_ && x_ < n && 0 <= y_ && y_ < m)) {d = (d + 1) % 4; continue;}
        	if (map[x_][y_] == 'x') {d = (d + 1) % 4; continue;}
        	x = x_; y = y_; a[x][y] = 1;
        }
    	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt += a[i][j];
    	cout << cnt << endl;
    }
	return 0;
}