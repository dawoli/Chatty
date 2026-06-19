#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1010;
char a[N][N];
bool vst[N][N];

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
    	int n, m, k, r, c, dir;
    	cin >> n >> m >> k >> r >> c >> dir;
    	memset(a, 'x', sizeof(a));
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			cin >> a[i][j];
			}
		}
    	memset(vst, false, sizeof(vst));
    	vst[r][c] = true;
		int dr[4] = {0, 1, 0, -1};
		int dc[4] = {1, 0, -1, 0};
		for (int i = 0; i < k; i++) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];
			if (a[nr][nc] == '.') {
				r = nr; c = nc;
				vst[nr][nc] = true;
			} else {
				dir = (dir + 1) % 4;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cnt += vst[i][j];
			}
		}
		cout << cnt << endl;
	}

    fclose(stdin);
    fclose(stdout);
    return 0;
}
