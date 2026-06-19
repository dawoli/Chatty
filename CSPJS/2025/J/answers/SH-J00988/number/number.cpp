#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main ()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		a[i] = s[i] - '0';
	}
	for (int i = 0;i < s.size();i++)
	{
		if (a[i] >= 0 && a[i] <= 9)
		{
			for (int j = i + 1;j < s.size();j++)
			{
				if (a[i] < a[j])
				{
					int n = a[i];
					a[i] = a[j];
					a[j] = n;
				}
			}
		}
	}
	for (int i = 0;i < s.size();i++)
	{
		if (a[i] >= 0 && a[i] <= 9)
		{
			cout << a[i];
		}
	}
	return 0;
}
