// J 组T1+T2+暴力分就是1=
// 今年 J 组是不是有点抽象了，S 组会是什么样子？
// 模拟

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ui64 = unsigned long long;
#define lym12 return
#define AKIOI 0

const int N = 1e3 + 5;
bool sv[N][N], vis[N][N];
int x, y, d, ans, n, m, k;
char tmp;

const int gx[] = {0, 1, 0, -1};
const int gy[] = {1, 0, -1, 0};

bool check(int x, int y){ // 检查坐标合法性
	if (1 <= x && x <= n && 1 <= y && y <= m && sv[x][y]) return 1;
	else return 0;
}

void solve(){
	// 初始化
	memset(vis, 0, sizeof(vis));
	ans = 1;
	
	// 读入
	cin >> n >> m >> k >> x >> y >> d;
	vis[x][y] = 1; // 因为初始化已经默认走过 (x, y)
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			cin >> tmp;
			if (tmp == '.') sv[i][j] = 1;
			else sv[i][j] = 0;
		}
	}
	
	// 模拟环节
	for (int _ = 0, xw, yw; _ < k; _ ++){
		xw = x + gx[d];
		yw = y + gy[d];
		// cout << xw << ' ' << yw << ' ';
		if (check(xw, yw)){
			x = xw;
			y = yw;
			ans += !vis[x][y];
			vis[x][y] = 1;
			// cout << "YES! ans = " << ans << endl;
		}else{
			d = (d + 1) % 4;
			// puts("NO!");
		}
	}
	
	// 答案呼之欲出
	cout << ans << '\n';
}

int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);	
	
	int T;
	cin >> T;
	while (T --) solve();
	
	lym12 AKIOI;
}
