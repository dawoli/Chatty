// 50pts

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, a[100005], b[100005], c[100005];
int ans;
void dfs(int step, int cnta, int cntb, int cntc, int nowsum)
{
	if (step == n + 1)
	{
		if (cnta > n / 2) return ;
		if (cntb > n / 2) return ;
		if (cntc > n / 2) return ;
		ans = max(ans, nowsum);
		return ;
	}
//	cout << step << " " << cnta << " " << cntb << " " << cntc << " " << nowsum << "\n";
	if (cnta > n / 2) return ;
	if (cntb > n / 2) return ;
	if (cntc > n / 2) return ;
	dfs(step + 1, cnta + 1, cntb, cntc, nowsum + a[step]);
	dfs(step + 1, cnta, cntb + 1, cntc, nowsum + b[step]);
	dfs(step + 1, cnta, cntb, cntc + 1, nowsum + c[step]);
}
pair <int, int> arr[100005];
bool checka()
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i]) return false;
	}
	return true;
}
bool checkb()
{
	for (int i = 1; i <= n; i++)
	{
		if (b[i]) return false;
	}
	return true;
}
bool checkc()
{
	for (int i = 1; i <= n; i++)
	{
		if (c[i]) return false;
	}
	return true;
}
void func()
{ 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	bool flaga = checka();
	bool flagb = checkb();
	bool flagc = checkc();
	
	if (flaga && flagc)
	{
		sort(b + 1, b + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += b[i];
		}
		cout << cnt << "\n";
	} else
	if (flaga && flagb)
	{
		sort(c + 1, c + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += c[i];
		}
		cout << cnt << "\n";
	} else
	if (flagc && flagb)
	{
		sort(a + 1, a + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += a[i];
		}
		cout << cnt << "\n";
	} else
	if (flaga)
	{
		for (int i = 1; i <= n; i++) arr[i] = {b[i] - c[i], i};
		sort(arr + 1, arr + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += b[arr[i].second];
		}
		for (int i = 1; i <= n - n / 2; i++)
		{
			cnt += c[arr[i].second];
		}
		cout << cnt << "\n";
	} else
	if (flagb)
	{
		for (int i = 1; i <= n; i++) arr[i] = {a[i] - c[i], i};
		sort(arr + 1, arr + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += a[arr[i].second];
		}
		for (int i = 1; i <= n - n / 2; i++)
		{
			cnt += c[arr[i].second];
		}
		cout << cnt << "\n";
	} else
	if (flagc)
	{
		for (int i = 1; i <= n; i++) arr[i] = {b[i] - a[i], i};
		sort(arr + 1, arr + n + 1);
		int cnt = 0;
		for (int i = n; i >= n - n / 2 + 1; i--)
		{
			cnt += b[arr[i].second];
		}
		for (int i = 1; i <= n - n / 2; i++)
		{
			cnt += a[arr[i].second];
		}
		cout << cnt << "\n";
	} else
	if (n <= 30)
	{
		ans = 0;
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
} 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) func();
 } 
