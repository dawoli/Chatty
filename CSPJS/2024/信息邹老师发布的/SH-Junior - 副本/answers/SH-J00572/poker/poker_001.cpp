#include <bits/stdc++.h>
using namespace std;
int n, d[15], c[15], h[15], s[15], ans = 52;
char huase, dianshu;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> huase >> dianshu;
		if (huase == 'D')
		{
			if (dianshu == 'A')
			{
				d[1]++;
			}
			else if ('2' <= dianshu && dianshu <= '9')
			{
				d[dianshu - '0']++;
			}
			else if (dianshu == 'T')
			{
				d[10]++;
			}
			else if (dianshu == 'J')
			{
				d[11]++;
			}
			else if (dianshu == 'Q')
			{
				d[12]++;
			}
			else
			{
				d[13]++;
			}
		}
		else if (huase == 'C')
		{
			if (dianshu == 'A')
			{
				c[1]++;
			}
			else if ('2' <= dianshu && dianshu <= '9')
			{
				c[dianshu - '0']++;
			}
			else if (dianshu == 'T')
			{
				c[10]++;
			}
			else if (dianshu == 'J')
			{
				c[11]++;
			}
			else if (dianshu == 'Q')
			{
				c[12]++;
			}
			else
			{
				c[13]++;
			}
		}
		else if (huase == 'H')
		{
			if (dianshu == 'A')
			{
				h[1]++;
			}
			else if ('2' <= dianshu && dianshu <= '9')
			{
				h[dianshu - '0']++;
			}
			else if (dianshu == 'T')
			{
				h[10]++;
			}
			else if (dianshu == 'J')
			{
				h[11]++;
			}
			else if (dianshu == 'Q')
			{
				h[12]++;
			}
			else
			{
				h[13]++;
			}
		}
		else
		{
			if (dianshu == 'A')
			{
				s[1]++;
			}
			else if ('2' <= dianshu && dianshu <= '9')
			{
				s[dianshu - '0']++;
			}
			else if (dianshu == 'T')
			{
				s[10]++;
			}
			else if (dianshu == 'J')
			{
				s[11]++;
			}
			else if (dianshu == 'Q')
			{
				s[12]++;
			}
			else
			{
				s[13]++;
			}
		}
	}
	for (int i = 1; i <= 13; ++i)
	{
		if (d[i])
		{
			ans--;
		}
		if (c[i])
		{
			ans--;
		}
		if (h[i])
		{
			ans--;
		}
		if (s[i])
		{
			ans--;
		}
	}
	cout << ans;
	return 0;
}
