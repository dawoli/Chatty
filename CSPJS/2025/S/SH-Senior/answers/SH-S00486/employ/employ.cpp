#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
int b[505], c[505], fac[505];
int n, m;
char s[505];
int g[505][505];
int dp[505][505];
/*
dp[i][j]：前 i 个人，有 j 个人拒绝的方案
显然这些拒绝的人耐心度小于 j
并且想让当前人接受，这个人的耐心度一定要大于 j
*/
const int mod = 998244353;
bool use[11];
int a[11], ans;
int f[300005][19];
void check () {
	int jj = 0, ps = 0;
	For (i, 1, n) {
		if (s[i] == '1') {
			if (c[a[i] ] > jj) ++ ps;
			else ++ jj;
		} else ++ jj;
	}
	if (ps >= m) ++ ans;
}
void dfs (int x) {
	if (x == n + 1) {
		check ();
		return;
	}
	For (i, 1, n) {
		if (!use[i]) {
			a[x] = i;
			use[i] = 1;
			dfs (x + 1);
			use[i] = 0;
		}
	}
}
signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m >> s + 1;
	For (i, 1, n) cin >> c[i];
	bool ff = 1;
	For (i, 1, n) if (s[i] == '0') ff = 0;
	fac[0] = 1;
	For (i, 1, n) fac[i] = fac[i - 1] * i % mod;
	if (n <= 10) {
		dfs (1);
		cout << ans;
	} else if (n <= 18) {
		f[0][0] = 1;
		int S = 1 << n;
		For (i, 1, S - 1) {
			int x = 0;
			For (j, 0, n - 1) if (i & (1 << j) ) ++ x;
			For (j, 0, n - 1) {
				if (i & (1 << j) ) {
					int k = j + 1;// 第 k 个人
					int st = i ^ (1 << j);
					For (l, 0, x) {
						int a1 = 0, a2 = 0;
						if (s[x] == '0' || c[k] <= l - 1) a1 = 1;
						if (s[x] != '0' && c[k] > l) a2 = 1;
						f[i][l] = (f[i][l] + f[st][l] * a2) % mod;
						if (l) f[i][l] = (f[i][l] + f[st][l - 1] * a1) % mod;
					}
				}
			}
		}
		ans = 0;
		For (i, 0, n - m) ans = (ans + f[S - 1][i]) % mod;
		cout << ans;
	} else if (m == n) {
		if (!ff) cout << 0;
		else {
			For (i, 1, n) {
				if (c[i] == 0) {
					cout << 0;
					return 0;
				}
			}
			cout << fac[n];
		}
		return 0;
	}
	return 0;
}
/*
dp
由于到第 i 天可以轻松求出有几个人放弃面试
于是就可以求出第 i 天后有哪些人仍然想来面试，显然这个东西只会越来越少
且只能在 si = 1 的天数录用

显然可以倒着做
因为越往前耐心度无所谓
设 f[i][j]，当前是第 i 天，耐心度足够的人还剩 j 个
如果 si = 0 则需要加入新的人



显然如果 si = 1，则表示当前可以录用人
但是录用的这个人的耐心度必须要撑到今天
但是如果 si = 0，那就需要踢出一个人，但是这个人不好找
所以再开一维用来表示现在还有几个人需要踢出
由于耐心度一样的话，这些人可以随便踢
f[i][j][k]：当前是第 i 天，耐心度足够且可以来的人有 j 个，今后有 k 个人会因为做不出题被拒绝

当 si = 1：选择耐心度足够的人加入
当 si = 0：需要踢出一个人，这个人耐心度可以足够也可以不足够
f[i][j][k] -> f[i - 1][j + ?? - 1][k]
f[i][j][k] -> f[i - 1][j + ??][k + 1]
同时每次加入新人时，都可以踢出若干个人，但是始终 
*/
