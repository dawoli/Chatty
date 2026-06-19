#include <bits/stdc++.h> //60分
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
bool a_0b, a_0d, a_0s;
ll T, n, m, L, V, ans;
ll d[N], v[N], a[N], p[N];

//ll findad(int x, int l, int r) {   //也许和正解有关
//	while (l < r) {
//		ll mid = (l + r) >> 1;
//		if (p[mid] < d[x]) {
//			l = mid;
//			continue;
//		}
//		ll now = v[x] * v[x] + 2 * a[x] * (d[x] - p[mid]); //瞬时速度的平方，不用考虑精度问题
//		ll mx = V * V;
//		if (now > mx) l = mid;
//		else r = mid - 1;
//	}
//	return l;
//}

void solve_A() {
	ll  pmxr = 0;
	for (int i = 1; i <= m; ++ i)
		pmxr = max(pmxr, p[i]);
	for (int i = 1; i <= n; ++ i)
		if (v[i] > V && d[i] <= pmxr) ans ++;
	if (ans == 0) m ++;
	cout << ans << " " << m - 1 << endl;
}

void solve_B() {
	ll limv = V * V, pmx = 0;
	for (int i = 1; i <= m; ++ i)
		pmx = max(pmx, p[i]);
	for (int i = 1; i <= n; ++ i) {
		if (d[i] > pmx) continue;
		ll maxv = v[i] * v[i] + 2 * a[i] * (pmx - d[i]);
		if (maxv > limv) ans ++;
	}
	if (ans == 0) m ++;
	cout << ans << " " << m - 1 << endl;
}

const int baoli_N = 550;
ll cnt;
bool cho[N], pp[baoli_N][baoli_N];
void dfs(int x) {
	if (x == m + 1) {
		bool cbc[N];
		ll usesum = 0;
		memset(cbc, 0 ,sizeof(cbc));
		for (int i = 1; i <= m; ++ i) {
			if (cho[i]) {
				usesum ++;
				for (int j = 1; j <= n; ++ j)
					cbc[j] = cbc[j] | pp[j][i];
			}
		}
		ll sum = 0;
		for (int i = 1; i <= n; ++ i)
			if (cbc[i]) sum ++;
		if (sum == ans) cnt = min(cnt, usesum);
		return;
	}
	dfs(x + 1);
	cho[x] = 1;
	dfs(x + 1);
	cho[x] = 0;
	return;
}

void baoli() {
	memset(cho, 0, sizeof(cho));
	memset(pp, 0, sizeof(pp));
	ll limv = V * V;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (d[i] > p[j]) continue;
			ll maxv = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
			if (maxv <= 0) break;
			if (maxv > limv)
				pp[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j)
			if (pp[i][j]) {
				ans ++;
				break;
			}
	}
	cout << ans << " ";
	cnt = m;
	dfs(1);
	cout << m - cnt << endl;
}

//void solve_C() {   //没想好怎么写
//	ll limv = V * V, pmn = L;
//	for (int i = 1; i <= m; ++ i)
//		pmn = min(pmn, p[i]);
//	for (int i = 1; i <= n; ++ i)
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while (T --) {
		a_0b = true;
		a_0d = true;
		a_0s = true;
		ans = 0;

		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; ++ i) {
			cin >> d[i] >> v[i] >> a[i];
			if (a[i] <= 0) a_0b = false;
			if (a[i] >= 0) a_0s = false;
			if (a[i] != 0) a_0d = false;
		}
		for (int i = 1; i <= m; ++ i)
			cin >> p[i];

		if (a_0d) solve_A();
		else if (a_0b) solve_B();
//		else if (a_0s) solve_C();
		else if (n * m <= 400) baoli();

	}
	return 0;
}
