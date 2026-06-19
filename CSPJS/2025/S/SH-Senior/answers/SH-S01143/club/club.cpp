/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long t, a[N], b[N], c[N], flag, ans;
bool cmp(int a, int b)
{
	return a > b;
 } 
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		long long n;
		cin >> n;
		for(int j = 1; j <= n; ++j)
		{
			cin >> a[j] >> b[j] >> c[j];
			if(b[j] == 0 && c[j] == 0)
			{
				flag++; 
			}
		}
		sort(a + 1, a + n + 1, cmp);
		if(flag == n)
		{
			for(int j = 1; j <= n / 2; ++j)
			{
				ans += a[j];
			}
		}
		cout << ans << '\n';
		ans = 0, flag = 0;
	}
	return 0;
}
