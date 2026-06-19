#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+10;
int n, ans = 0;
int a[N], s[N];

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	if (n < 3)
		cout << "0\n";
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	
	sort(a+1, a+n+1);
		
	// 特判：12pts 
	if (n == 3)
	{
		if (a[1] + a[2] > a[3])
			cout << "1\n";
		else
			cout << "0\n"; 
		return 0;
	}
	
	// 我们关心的只有一个区间和一个数，即最大值，其他的都是无关的 
	// 搓一个滑动窗口，在里面找到最小的最大值就行了 
	for (int i = 1; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			int sum = s[j] - s[i-1];
			// 找到最小的最大值，即第一个小于sum的数 
			for (int k = j+1; k <= n; k++)
			{
				if (a[k] < sum)
					ans += (n - k + 1);
			}
		}
	}

	cout << ans << '\n';	
	return 0;
}
