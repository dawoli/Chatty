// Problem URL: https://www.luogu.com.cn/problem/P1065 [NOIP 2006 提高组] 作业调度方案
// Finish Time: 2026/10/5 11:33:55 AC
// Start Time: 2026/10/5 11:04:54

#include <bits/stdc++.h>
#define int int
#define endl '\n'
using namespace std;
typedef long long	   ll;
typedef pair<int, int> pii;
constexpr int		   MAXN	 = 50;
constexpr int		   MAXMN = MAXN * MAXN;


int	 n, m;
int	 ans = 0;
int	 lst[MAXN * MAXN];
int	 num[MAXN][MAXN];
int	 t[MAXN][MAXN];
int	 cnt[MAXN];
int	 lt[MAXN];
bool tl[MAXN * MAXN][MAXN * MAXN];

bool check(int s, int e, int x)
{
	for (int i = s; i <= e; i++)
		if (tl[x][i])
			return false;
	return true;
}

signed main()
{
	cin >> m >> n;
	for (int i = 1; i <= n * m; i++)
		cin >> lst[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> num[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> t[i][j];
	for (int i = 1; i <= n * m; i++)
	{
		int x = lst[i];
		cnt[x]++;
		int xm = num[x][cnt[x]];
		int ct = t[x][cnt[x]];
		for (int i = lt[x] + 1;; i++)
			if (check(i, i + ct - 1, xm))
			{
				for (int j = i; j <= i + ct - 1; j++)
					tl[xm][j] = true;
				lt[x] = i + ct - 1;
				break;
			}
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, lt[i]);
	cout << ans << endl;
	return 0;
}