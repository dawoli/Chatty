#include <iostream>
using namespace std;
int t, n, m, k;
bool grid[1000][1000], unvisited[1000][1000];
pair<int, int> dir2ofst[4];
int x, y, d, c, nx, ny;
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    dir2ofst[0].first = 0, dir2ofst[0].second = 1;
    dir2ofst[1].first = 1, dir2ofst[1].second = 0;
    dir2ofst[2].first = 0, dir2ofst[2].second = -1;
    dir2ofst[3].first = -1, dir2ofst[3].second = 0;
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n >> m >> k
            >> x >> y >> d;
        x--, y--, c = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char statement;
                cin >> statement;
                grid[i][j] = (statement == '.');
                unvisited[i][j] = true;
            }
        for (int opc = 0; opc < k; opc++) {
            unvisited[x][y] = false;
            nx = x + dir2ofst[d].first,
            ny = y + dir2ofst[d].second;
            if (
                nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                grid[nx][ny]
            ) {
                if (unvisited[nx][ny])
                    c++;
                x = nx, y = ny;
            } else d = (d + 1) % 4;
        }
        cout << c << endl;
    }
    return 0;
}
