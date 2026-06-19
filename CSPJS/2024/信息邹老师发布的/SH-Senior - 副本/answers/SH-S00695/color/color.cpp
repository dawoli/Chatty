#include<bits/stdc++.h>
using namespace std;
long long t, n, a[200005], ans;
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(a[i] == a[j])
				{
					ans += a[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
