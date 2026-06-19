#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N][3],num[3],t[N],x[N];
int mian()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	int ans = num[0] = num[1] = num[2] = 0;
	for (int i = 1; i <= n; ++i)
	{
		t[i] = max_element(a[i], a[i] + 3) - a[i];
		++num[t[i]];
		ans += a[i][t[i]];
	}
	if (num[0] <= n / 2 && num[1] <= n / 2 && num[2] <= n / 2) return ans;
	int s = max_element(num, num + 3) - num,s1 = !s,s2 = 3 - s - s1,k = num[s] - n / 2,m = 0;
	for (int i = 1; i <= n; ++i) if (t[i] == s) x[++m] = a[i][s] - max(a[i][s1], a[i][s2]);
	sort(x + 1, x + m + 1);
	for (int i = 1; i <= k; ++i) ans -= x[i];
	return ans;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", mian());
	return 0;
}