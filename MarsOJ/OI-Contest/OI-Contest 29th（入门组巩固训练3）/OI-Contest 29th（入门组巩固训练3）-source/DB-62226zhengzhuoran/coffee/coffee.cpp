#include <bits/stdc++.h>
using namespace std;
int t, sum=0;
string s[105];
long long n, m;
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","r",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		for (int j = 1;j <= 5;j++)
		{
			for (int k = 1;k <= 8;k++)
			{
				cin >> s[i * j];
			}
		}
		cin >> n >> m;
		for(int j = m;j <= 7;j++)
		{
			n--;
			for (int k = 1;k <= 8;k++)
			{
				if (s[j * k] == "math")
				{
					sum++;
				}
			}
			if (j == 7)
			{
				j = 1;
			}
			if (n < 0)
			{
				break;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

