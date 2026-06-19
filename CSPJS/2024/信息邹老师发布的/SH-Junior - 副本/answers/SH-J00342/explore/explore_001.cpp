#include <bits/stdc++.h>
using namespace std;
int T;
int n, m, k, x, y, d, ans;
char t;
bool chizu[2000][2000], f, mark[2000][2000];
bool exist(int a, int b){
    if(a > n || a < 1 || b > m || b < 1 || chizu[a][b]) return false;
    else return true;
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
    cin >> T;
    while (T --){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        for (int i = 1; i <= n; i ++){
            for (int j = 1;j <= m; j ++){
                cin >> t;
                if (t == '.') f = 0;
                else f = 1;
                chizu[i][j] = f;
            }
        }
        mark[x][y] = 1;
        while (k --){
            if(d == 0) {
                if (exist(x, y + 1)) {y ++; mark[x][y] = 1;}
                else d = (d + 1) % 4;
            }else if(d == 1) {
                if (exist(x + 1, y)) {x ++; mark[x][y] = 1;}
                else d = (d + 1) % 4;
            }else if(d == 2) {
                if (exist(x, y - 1)) {y --; mark[x][y] = 1;}
                else d = (d + 1) % 4;
            }else if(d == 3) {
                if (exist(x - 1, y)) {x --; mark[x][y] = 1;}
                else d = (d + 1) % 4;
            }
        }
        for (int i = 1; i <= n; i ++){
            for (int j = 1;j <= m; j ++){
                if (mark[i][j] == 1) ans ++;
            }
        }
        cout << ans << endl;
        ans = 0;
        memset(chizu, 0, sizeof(chizu));
        memset(mark, 0, sizeof(mark));
    }
	return 0;
}
