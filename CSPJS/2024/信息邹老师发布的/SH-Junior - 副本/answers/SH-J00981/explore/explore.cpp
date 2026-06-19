#include <cstdio>
#include <cstring>
using namespace std;

int bot_move(int& x, int& y, int d) {
	if (d == 0) y += 1;
	if (d == 1) x += 1;
	if (d == 2) y -= 1;
	if (d == 3) x -= 1;
	return 0;
}
bool bot_valid(int x, int y, int n, int m) {
	if (x < 1) return false;
	if (y < 1) return false;
	if (x > n) return false;
	if (y > m) return false;
	return true;
}
char explore_map[1005][1005];
char explored[1005][1005];
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 0; ti < T; ti++) {
		int n,m,k;
		int x,y,d;
		scanf("%d%d%d%d%d%d", &n, &m, &k, &x, &y, &d);
		int cnt = 1;
		memset(explore_map, 0, 1005*1005); 
		memset(explored, 0, 1005*1005); 
		explored[x][y] = 1;
		for (int i = 0; i < n; i++) {
			scanf("%s", explore_map[i]);
		}
		for (int c = 0; c < k; c++) {
			int x_=x,y_=y;
			bot_move(x_, y_, d);
			if (bot_valid(x_, y_, n, m) && explore_map[x_-1][y_-1] == '.') {
				x = x_; y = y_;
				if (explored[x][y] == 0) {
					cnt++;
					explored[x][y] = 1;
				}
			}
			else d = (d+1)%4;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
