// 8pts

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans = 0;
char a[15];
int p[15], t[15], n, m;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "r", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) p[i] = i;
	do
	{
		int temp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == '0' || temp >= t[p[i]]) temp++;
		}
		if (n - temp >= m) ans++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans;
}
