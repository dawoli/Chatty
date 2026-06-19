// CSP-S 打满暴力就是一等奖
/* 做法
 * (1)
 * 模拟
 * 
 * (2)
 * 结论：
 * 一辆车要么在最左边最快，要么在最右边最快
 * right_most: a_i <= 0
 * left_most: a_i >= 0
 * ---
 * 记录一辆车是否在 x 处超速
*/ /* 嘀咕
* 推出来之后感觉不会了
* 先把模拟写了先
* 模拟没有优化好像也是 nm
* 那就奔着 nm 写 (约 70pts)
* 调了半天结果发现距离计算写反了😡
*/

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

double speed_calc(int v, int a, int s){
	//if (v * v + 2 * a * s < 0) return -1;
	return sqrt(v * v + 2 * a * s);
}

const int N = 1e5 + 5;
const int M = 1e5 + 5;
int d[N], v[N], a[N];
int p[M]; int n, m, L, V;
bool vis[N], vs[N]; int aas;
int l[N], r[N];

bool check(vector <int> chs){
	for (int i = 0; i < chs.size(); i ++){
		for (int j = 0; j < n; j ++){
			vs[j] = 0;
			if (!vis[j]) continue;
			if (l[i] <= chs[i] && r[i] >= chs[i]) vs[j] = 1;
		}
	}
	
	//for (int i = 0; i < n; i ++) cout << vs[i];
	
	for (int i = 0; i < n; i ++){
		if (vis[i] != vs[i]) return 0;
	}
	return 1;
}

void dfs(int now, int chosen, vector <int> chs){
	if (now > m) return;
	if (chosen > aas) return;
	//printf("%d %d |", now, chosen); for (auto x : chs) cout << x << ' ';
	if (check(chs)){
		//puts("yes");
		aas = min(aas, chosen);
		return ;
	}//else puts("no");
	
	dfs(now + 1, chosen, chs);
	chs.push_back(now);
	dfs(now + 1, chosen + 1, chs);
	chs.pop_back();
}

void solve(){
	memset(l, 0x3f, sizeof(l));
	memset(r, 0, sizeof(r));
	
	cin >> n >> m >> L >> V;
	for (int i = 0; i < n; i ++) cin >> d[i] >> v[i] >> a[i];
	for (int i = 0; i < m; i ++) cin >> p[i];
	//puts("============================");
	// (1)
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	for (int i = 0; i < m; i ++){
		for (int j = 0; j < n; j ++){
			if (d[j] > p[i]) continue;
			else if (speed_calc(v[j], a[j], - d[j] + p[i]) > V){
				ans += !vis[j], vis[j] = 1;
				l[j] = min(l[j], i);
				r[j] = max(r[j], i);
			}
			//cout << "i" << i + 1 << "(" << p[i] << ") j" << j + 1;
			//printf("(d%d v%d a%d tmp%d)", d[j], v[j], a[j], 2 * a[j] * (- d[j] + p[i]));
			//cout << " speed" << speed_calc(v[j], a[j], d[j] - p[i]) << endl;
		}
		//puts("============================");
	}
	//for (int i = 0; i < n; i ++) cout << vis[i];
	//cout << endl;
	cout << ans << ' ';
	//cout << endl;
	
	// (2)
	//for (int i = 0; i < n; i ++){
	//	printf("edge : l[%d] = %d, r[%d] = %d\n", i, l[i], i, r[i]);
	//}
	
	aas = INT_MAX;
	dfs(0, 0, {});
	cout << m - aas << '\n';
}

int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cout.tie(0);
	
	int T; cin >> T;
	while (T --) solve();

	return 0;
}
