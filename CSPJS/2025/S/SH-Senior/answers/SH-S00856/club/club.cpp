#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#define PASS 0
//#define U_USE_MEMORIZED
//#define U_DEBUG
using namespace std;
const int MAXN = 1e5+5, SMAXN = 35;
int T, n, cnt_a, cnt_b, cnt_c;
int fz[MAXN], ans;
int a[3][MAXN];
struct Person {
	int d1, d2, d3;
	bool operator> (Person _cmp) const {
		return d1+d2+d3 > _cmp.d1+_cmp.d2+_cmp.d3;
	}
};
//int mp[SMAXN][SMAXN][SMAXN][SMAXN];
void dfs(int k, int aa, int bb, int cc) {
	if(aa > n/2 || bb > n/2 || cc > n/2) return; // 剪枝
//	if(mp[k][aa][bb][cc]) return; // 已经搜索过的不可能有更好结果
	if(k == n+1) {
		int res = 0;
		for(int i = 1;i <= n;i ++) {
			res += a[fz[i]][i];
		}
		ans = max(ans, res);
		return;
	}
	fz[k] = 0;
	dfs(k+1, aa+1, bb, cc);
	fz[k] = 1;
	dfs(k+1, aa, bb+1, cc);
	fz[k] = 2;
	dfs(k+1, aa, bb, cc+1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		cnt_a = cnt_b = cnt_c = ans = 0;
		memset(fz, 0, sizeof fz);
		for(int i = 1;i <= n;i ++) {
			cin >> a[0][i] >> a[1][i] >> a[2][i];
		}
		if(n <= 30) {
			dfs(0, 0, 0, 0);
			cout << ans << '\n';
		} else { // 特殊性质AB
			Person pp[n+1];
			for(int i = 1;i <= n;i ++) {
				pp[i+1].d1 = a[0][i];
				pp[i+1].d2 = a[1][i];
				pp[i+1].d3 = a[2][i];
			}
			sort(pp+1, pp+n+1, greater<Person>());
			for(int i = 1;i <= n;i ++) {
				if(pp[i].d1 < pp[i].d2 && cnt_a <= n/2) { // 分配到A
					ans += pp[i].d1;
				} else if (cnt_b <= n/2) { // 分配到B
					ans += pp[i].d2;
				}
				// 无法分配
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
