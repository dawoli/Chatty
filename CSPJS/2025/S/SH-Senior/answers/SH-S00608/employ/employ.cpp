#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, X = N / 2;
const int MOD = 998244353;
int n, m, c[N]; // 0<=c[i]<=n
int cnt[N]; 
string s;
int pre[N]; // 第i天后没被录取的人数 
//ll dp[X][X][2]; // dp[i][j][0/1]: 出了i套简单，j套难，今天出的是简单1/困难0 时录取的人数 
int xingzhiA = 1, xingzhiB = 0; // 满足性质A性质B 
bool vst[N];
int ans = 0;
void dfs(int cur = 1, int failed = 0) {
	if (cur > n) {
		if (n - failed >= m) ++ans;
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vst[i]) {
			vst[i] = 1;
			if (failed >= c[i] || s[cur] == '0') dfs(cur + 1, failed + 1);
			else dfs(cur + 1, failed);
			vst[i] = 0;
		}
	}
}
int main()
{ 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin.ignore();
	getline(cin, s);
	s = '#' + s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		++cnt[c[i]];
		pre[i] = pre[i - 1];
		if (s[i] == '0') {
			++pre[i];
			xingzhiA = 0; 
		}
		else {
			++xingzhiB;
		}
	}
	if (xingzhiB <= 18) xingzhiB = 1;
	sort(c + 1, c + n + 1);
	// 骗1~2: 8分
	dfs();
	cout << ans << '\n';
	return 0;
}

