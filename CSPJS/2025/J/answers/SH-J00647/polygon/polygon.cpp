/*
当最后一根长度为k时，需满足其余长度相加 > k
也就是说，a + b + c + ...... > k
只要满足 a + b > k
则 a + b + c > k
以此类推
且左边单项最大值不大于 k
即a <= b <= c <= d <= ...... <= k
当 a + b == k时
有 a + b + c > k
且有 a + b + c + ...... > k (最大项不大于k)
当 a + b > k时
有 n! + n! / 2! + n! / 3! + ......种成立情况 (n为小于k的不为{a, b}项数)

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int mod = 998244353;
int n, a[5005]; 
int dfs200(int pos, int mx, int sum, int num)
{
	int ans = 0;
	if (mx * 2 < sum && num >= 3)
	{
		ans = 1;
	}
	for (int i = pos + 1; i <= n; i++){
		ans += dfs200(i, max(mx, a[i]), sum + a[i], num + 1);
		ans %= mod;
	}
	return ans;
}
int p[5005][5005];
int dfs300(int x)
{
	if (x == n) return n;
	int ans = 0;
	for (int i = x + 1; i <= n; i++)
	{
		if (p[x][i]) ans = (ans + p[x][i]) % mod;
		else
		{
			p[x][i] = dfs300(i);
			ans = (ans + p[x][i]) % mod;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool bflag = true;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] != 1) bflag = false;
	}
	if (n < 3)
	{
		cout << 0;
		return 0;
	}
	if (n == 3)
	{
		if (min(min(a[1] + a[2], a[2] + a[3]), a[1] + a[3]) > max(max(a[1], a[2]), a[3]))
		{
			cout << 1;
		} 
		else cout << 0;
		return 0;
	}
	if (n <= 20)
	{
		cout << dfs200(0, 0, 0, 0);
		return 0;
	}
	if (bflag)
	{
		cout << dfs300(0);
		return 0;
	} 
	//特判完成后，还有11~14、21~25几个测试点未解决，目前没想法 
	 return 0;
}
