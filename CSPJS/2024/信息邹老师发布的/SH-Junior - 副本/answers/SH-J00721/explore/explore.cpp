#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1e3 + 5;
ifstream fin("explore.in");
ofstream fout("explore.out");
char c[MAXN][MAXN];
bool reach[MAXN][MAXN];
int main() {
	int T;
	fin >> T;
	while (T--) {
		int n, m, k;
		fin >> n >> m >> k;
		for (int i = 1; i <= n + 2; ++i)
			for (int j = 1; j <= m + 2; ++j) reach[i][j] = 0; 
		int x, y, d;
		fin >> x >> y >> d;
		reach[x][y] = 1; 
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) fin >> c[i][j];
		for (int i = 1; i <= k; ++i) {
			if (d == 0) {
				if (c[x][y + 1] == '.' && y < m) {
					++y;
					reach[x][y] = 1;
				} else d = 1;
			} else if (d == 1) {
				if (c[x + 1][y] == '.' && x < n) {
					++x;
					reach[x][y] = 1;
				} else d = 2;
			} else if (d == 2) {
				if (c[x][y - 1] == '.' && y > 1) {
					--y;
					reach[x][y] = 1; 
				} else d = 3;
			} else if (d == 3) {
				if (c[x - 1][y] == '.' && x > 1) {
					--x;
					reach[x][y] = 1; 
				} else d = 0;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (reach[i][j]) ++ans;
		fout << ans << "\n";
	}
	return 0;
} 
