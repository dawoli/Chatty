#include<bits/stdc++.h>
using namespace std;
int cnt, d;
int n, m, k;
char c[1010][1010];
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int judge(int x, int y) {
	int nx = x + dir[d][0];
	int ny = y + dir[d][1];
	if(c[nx][ny] == '.') {
		return 2;
	}
	return 1;
}

bool bj(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int t) {
	if(t <= 0) {
		return;
	}
	for(int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		int num;
		if(i >= d) {
			num = i - d;
		} else {
			num = 4 - d + i;
		}
		if(bj(nx, ny) && c[nx][ny] != 'x') {
			d = i;
			cnt++;
			num++;
			c[nx][ny] = 'x';
			dfs(nx, ny, t - num);
		}
	}
	return;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a;
	int sx, sy;
	cin >> a;
	while(a--) {
		cin >> n >> m >> k;
		cin >> sx >> sy >> d;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> c[i][j];
			}
		}
		if(k == 1) {
			cout << judge(sx, sy) << "\n";
			continue;
		}
		c[sx][sy] = 'x';
		cnt = 1;
		dfs(sx, sy, k);
		cout << cnt << "\n";
	}
	return 0;
}

