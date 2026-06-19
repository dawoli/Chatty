#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("2.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, math[10];
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		fill(math, math+10, 0);
		string s;
		for(int j = 0; j < 8; j++)
		{
			for(int i = 1; i <= 5; i++)
			{
				cin >> s;
				if(s=="math")
				{
					math[i]++;
				}
			}
		}
		int cnt = 0;
		int a, b;
		cin >> a >> b;
		for(int i = b, j = 0; j < a; i++, j++)
		{
			if(i > 7)
			{
				i %= 7;
			}
			cnt += math[i];
		}
		cout << cnt << '\n';
	}
	return 0;
}
