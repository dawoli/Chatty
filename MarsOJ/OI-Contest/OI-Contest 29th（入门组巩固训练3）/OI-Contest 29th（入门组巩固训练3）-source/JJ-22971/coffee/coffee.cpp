#include <bits/stdc++.h>
using namespace std;
long long sum;
int t, a[7], n, m;
string s;
int main()
{
	freopen("coffee.in", "r", stdin);
	freopen("coffee.out", "w", stdout);
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		memset(a, 0, sizeof(a));
		for(int j = 0; j < 5; j++)
		{
			for(int k = 0; k < 8; k++)
			{
				cin >> s;
				if(s == "math")
				{
					a[j]++;
				}
			}
		}
		cin >> n >> m;
		m--;
		a[0] += a[1] + a[2] + a[3] + a[4];
		sum += a[0] * (n / 7);
		a[0] -= a[1] + a[2] + a[3] + a[4];
		n %= 7;
		while(n)
		{
			sum += a[m++];
			n--;
			m %= 7;
		}
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
