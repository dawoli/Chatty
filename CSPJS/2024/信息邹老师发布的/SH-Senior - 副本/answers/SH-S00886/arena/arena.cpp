#include <bits/stdc++.h>
#define int long long
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
using namespace std;

typedef long double db;
typedef pair<int, int> PII;
void file_IO(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
}

const int N = 5010;
int T, n, m, k, _a[N], x[5], a[N], d[20][N], c[N];
int dp[20][N][20], pre[20][N][20];

int calc(int x){
	int t = 0;
	while ((1 << t) < x)	++t;
	return t;
}

void solve(){
	cin >> x[0] >> x[1] >> x[2] >> x[3];
	for (int i = 1; i <= n; i++)
		a[i] = _a[i] ^ x[i % 4], a[i] = min(a[i], k + 1);
	int ans = 0;
	for (int _ = 1; _ <= m; _++){
		if (c[_] == 1){
			ans ^= _;
			continue;
		}
		int _k = calc(c[_]);
		for (int i = k; i >= k - _k; i--){
			for (int j = 1; j <= (1 << (_k - k + i)); j++){
				if (i == k){
					if (j <= c[_])
						for (int v = 0; v <= k + 1; v++)
							dp[i][j][v] = (v == a[j] ? 1 : 0);
					else{
						for (int v = 0; v <= k + 1; v++)
							dp[i][j][v] = 1;
					}
				}else{
					int rd = k - i;
					if (d[i][j]){
						for (int v = 1; v < rd; v++)
							dp[i][j][v] = pre[i + 1][j * 2][rd - 1] & dp[i + 1][j * 2 - 1][v];
						for (int v = rd; v <= k + 1; v++){
							dp[i][j][v] = dp[i + 1][j * 2][v];
							dp[i][j][v] |= pre[i + 1][j * 2][rd - 1] & dp[i + 1][j * 2 - 1][v];
						}
					}else{
						for (int v = 1; v < rd; v++)
							dp[i][j][v] = pre[i + 1][j * 2 - 1][rd - 1] & dp[i + 1][j * 2][v];
						for (int v = rd; v <= k + 1; v++){
							dp[i][j][v] = dp[i + 1][j * 2 - 1][v];
							dp[i][j][v] |= pre[i + 1][j * 2 - 1][rd - 1] & dp[i + 1][j * 2][v];
						}
					}
				}
				pre[i][j][0] = dp[i][j][0];
				for (int v = 1; v <= k + 1; v++)
					pre[i][j][v] = pre[i][j][v - 1] | dp[i][j][v];
			}
		}
		int res = 0;
		for (int i = 1; i <= (1 << _k); i++){
			int fl = 1, posx = k, posy = i;
			while (posx != k - _k){
				int nxtx = posx - 1, nxty = (posy + 1) / 2;
				int rd = k - nxtx;
				if (d[nxtx][nxty]){
					if (posy == nxty * 2){
						if (i <= c[_])
							fl &= (a[i] >= rd);
					}else{
						fl &= pre[posx][posy + 1][rd - 1];
					}
				}else{
					if (posy == nxty * 2 - 1){
						if (i <= c[_])
							fl &= (a[i] >= rd);
					}else{
						fl &= pre[posx][posy - 1][rd - 1];
					}
				}
				posx = nxtx, posy = nxty;
			}
			res += (fl ? i : 0);
		}
		ans ^= res * _;
	}
	cout << ans << endl;
}

signed main(){
	file_IO();
	cin >> n >> m;
	k = calc(n);
	for (int i = 1; i <= n; i++)
		cin >> _a[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	for (int i = k - 1; i >= 0; i--)
		for (int j = 1; j <= (1 << i); j++){
			char ch; cin >> ch;
			d[i][j] = ch - '0';
		}
	cin >> T;
	while (T--)
		solve();
	return 0;
}
//IANYEYZ AK IOI
