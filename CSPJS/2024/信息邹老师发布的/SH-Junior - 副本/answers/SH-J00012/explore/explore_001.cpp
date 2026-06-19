#include <fstream>
#include <string>
const int maxn = 1e3 + 5;

bool flag[maxn][maxn];
std::string map[maxn];

std::ifstream fin("explore.in");
std::ofstream fout("explore.out");
int main()
{
	long long time;
	fin >> time;

	for(int t = 1; t <= time; ++t) {
		int n, m, k;
		int x, y, d;

		fin >> n >> m >> k;
		fin >> x >> y >> d;

		y -= 1;
		for(int i = 1; i <= n; ++i)
			fin >> map[i];

		flag[x][y] = 1;
		for(int step = 1; step <= k; ++step) {
			if(d == 0) {
				if(map[x][y + 1] == '.' && y + 1 < m) {
					y = y + 1;
				} else d = (d + 1) % 4;
			}

			else if(d == 1) {
				if(map[x + 1][y] == '.' && x + 1 <= n) {
					x = x + 1;
				} else d = (d + 1) % 4;
			}

			else if(d == 2) {
				if(map[x][y - 1] == '.' && y - 1 >= 0) {
					y = y - 1;
				} else d = (d + 1) % 4;
			}

			else if(d == 3) {
				if(map[x - 1][y] == '.' && x - 1 >= 1) {
					x = x - 1;
				} else d = (d + 1) % 4;
			}
			flag[x][y] = 1;
		}

		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			map[i] = "";
			for(int j = 0; j < m; j++) {
				if(flag[i][j]) ans++;
				flag[i][j] = 0;
			}
		}

		fout << ans << std::endl;
	}
}
