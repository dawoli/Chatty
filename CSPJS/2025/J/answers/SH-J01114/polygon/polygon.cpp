#include <bits/stdc++.h>
using namespace std;
int n, a[5003], sum[5003], lans, jj;
long long ans;
const long long mod = 998244353;
void dfs(int u, int l, int flag) {
	if (l > flag) {//边界，如果现在可行，小于当前数值的数可以随便加 
		ans = (ans + (u + 1) * u % mod / 2 + 1) % mod;
		return;
	}
	if (l + sum[u] <= flag) return;//边界，如果后面全加上都不行，直接回退
	dfs(u - 1, l + a[u], flag);//选 
	dfs(u - 1, l, flag);//不选 
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
//没调好的暴力代码保存一下，以防万一。 
//	for (int i = 1; i <= n - 2; ++i) {
//		for (int j = i + 1; j <= n - 1; ++j) {
//			for (int k = j + 1; k <= n; ++k) {
//				if (check(a[i], a[j], sum[k] - sum[j])) {
//					ans = (ans + (n - k + 1) * (n - k) / 2 + 1) % mod;
//					cout << a[i] << " " << a[j] << " " << sum[k] - sum[j] << " " << ans << "\n";
//				}
//			}
//		}
//	}
	for (int i = 3; i <= n; ++i) {//枚举最大值 
		if (sum[i - 1] <= a[i]) continue;//如果不可能做到，直接跳过 
		//a数组下标1到i-1中有多少个组合大于a[i]
		//把必须选的选上
		lans = 0, jj = i - 1;
		for (int j = i - 1; j >= 0; --j) {
			jj = j;
			if (sum[i - 1] - a[j] <= a[i]) lans += a[j];
			else break;
		} 
		if (lans > a[i]) {
			++jj;
			ans = (ans + jj * (jj - 1) % mod / 2 + 1) % mod;
		} else { 
			int jjj = 1;
			while (sum[jjj] + lans <= a[i]) ++jjj;//判断从前几个数中进行选择是可行的
			for (int j = jjj; j <= jj; ++j) {//开始枚举，在前j个数中进行选择 
				if (j > 1) dfs(j - 1, lans + a[j], a[i]);//绝望的dfs（我知道这很可能会TLE）
				else if (lans + a[j] > a[i]) ++ans;
			} 
		}
	}
	cout << ans % mod << "\n";
	return 0;
}

