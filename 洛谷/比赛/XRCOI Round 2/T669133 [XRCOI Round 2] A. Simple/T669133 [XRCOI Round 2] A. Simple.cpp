#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		ll a;
		cin >> a;
		if (a == 1 || a == 2 || a == 4)
		{
			cout <<  "No\n";
			continue;
		}
		cout <<  "Yes\n";
		ll b, c;
		if (a & 1)
		{
			ll m = (a - 1LL) / 2;
			b = m * m;
			c = (1LL * a * a - 1) / 4;
		}
		else
		{
			int lowbit = a &-a;
			int t = a / lowbit;
			if (t > 1)
			{
				ll m = (t - 1LL) / 2;
				ll n = m + 1;
				b = lowbit * m * m;
				c = lowbit * m * n;
			}
			else
			{
				b = a / 8;
				c = 3LL * b;
			}
		}
		cout << b <<  " " << c <<  "\n";
	}
	return 0;
}