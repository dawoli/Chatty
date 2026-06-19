#include <bits/stdc++.h>
using namespace std;

long long T,n,a[200010],ans;

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if(n <= 15)
		{
			for(int i = 0;i < (1 << n);i++)
			{
				long long sum = 0;
				for(int j = 1;j <= n;j++)
				{
					for(int k = j - 1;k > 0;k--)
					{
						if(bool(i & (1 << (j - 1))) == bool(i & (1 << (k - 1))))
						{
							if(a[j] == a[k])
							{
								sum += a[j];
							}
							break;
						}
					}
				}
				ans = max(ans,sum);
			}
			cout << ans << endl;
			continue;
		}
		cout << 0 << endl;
	}
	return 0;
}

