#include<bits/stdc++.h>
using namespace std;


const int N = 1e3 + 2;

int T;
int n, m, k;
bool ok[N][N], vst[N][N];
int lct[6] = {0, 1, 0, -1, 0};


bool chk(int x, int y) {
	return (1 <= x and x <= n and 1 <= y and y <= m and ok[x][y]);
}

void test() {
	cin >> n >> m >> k;
	memset(ok, 0, sizeof(ok));
	memset(vst, 0, sizeof(vst));
	int nx, ny, d;
	cin >> nx >> ny >> d;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
		char c;
		cin >> c;
		ok[i][j] = (c == '.');
	}
	vst[nx][ny] = true;
	for(int i=1; i<=k; i++) {
		int n_nx = nx + lct[d], n_ny = ny + lct[d+1];
		if(chk(n_nx, n_ny)) nx = n_nx, ny = n_ny, vst[nx][ny] = true;
		else d = (d + 1) % 4, n_nx = nx + lct[d], n_ny = ny + lct[d+1];
	}
	int cnt = 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cnt += vst[i][j];
	cout << cnt << endl;
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--) test();
	return 0;
}

/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

3
13
*/
 
