#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int dict[5000005][20], a[5000005];
int n, k;
map <int, int> mp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		for (int j = 1; j <= x; j<<=1)
		{
			if (x & j) dict[i][cnt] = 1;
			cnt++;
		}
	}
	for (int i = 0; i < 20; i++)
		for (int j = 1; j <= n; j++)
			dict[j][i] = (dict[j][i] + dict[j - 1][i]) & 1;
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << dict[j][i] << " ";
//		}
//		cout << "\n";
//	}
	for (int i = 1; i <= n; i++)
	{
		int now = 0;
		for (int j = 0; j < 20; j++)
		{
			now += dict[i][j] * (1 << j);
		}
		a[i] = now;
	}
//	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	int now_right = -1, ans = 0;
	mp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (mp.find(a[i] ^ k) != mp.end() && mp[a[i] ^ k] >= now_right)
		{
			now_right = i;
//			cout << i << " " << now_right << " ";
			ans++;
		}
		mp[a[i]] = i;
	}
	cout << ans;
}
