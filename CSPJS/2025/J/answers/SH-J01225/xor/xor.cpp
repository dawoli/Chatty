#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
long long cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (k == 0)
	{
		cout << 0;
		return 0;
	}
	else if (k == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			if (a[i] != a[i + 1])
			{
				cnt++;
				i++;
			}
		}
		cout << cnt;
		return 0;
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (a[i] == k)
			{
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	return 0;
}
