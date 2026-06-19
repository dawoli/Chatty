//#include <iostream>
//#include <cstdio>
//using namespace std;
//int ans = 0;
//int n, a[505];
//void dfs(int step, int nowmax, int nowsum, int nowcnt)
//{
//	if (step == n + 1)
//	{
//		if (nowcnt < 3) return ;
//		if (nowmax * 2 >= nowsum) return ;
//		ans++, ans %= 998244353;
////		cout << nowmax << " " << nowsum << " " << nowcnt << "\n";
//		return ;
//	}
//	dfs(step + 1, nowmax, nowsum, nowcnt);
//	dfs(step + 1, max(nowmax, a[step]), nowsum + a[step], nowcnt + 1);
//}
//int main()
//{
//	freopen("polygon4.in", "r", stdin);
////	freopen("polygon.out", "w", stdout);
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//	dfs(1, 0, 0, 0);
//	cout << ans;
// } 

/* 68pts */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
const int mod = 998244353;
using namespace std;
map <int, long long> mp;
int n, a[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long ans = 0;
	map <int, long long> temp;
	mp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int max_now = a[i] * (i - 1);
		for (int j = a[i] + 1; j <= max_now; j++)
		{
			ans += mp[j];
			ans %= mod;
		}
		temp.clear();
		for (auto v : mp) temp[v.first + a[i]] = v.second;
		for (auto v : temp)	mp[v.first] = (mp[v.first] + v.second) %= mod;
	}
	cout << ans;
}
