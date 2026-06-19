#include <bits/stdc++.h>
using namespace std;

char exp_map[1001][1001];
int t, x, y, k, x_now, y_now, d;

void move()
{
	k -= 1;
	if (d == 0)
	{
		if (exp_map[x_now][y_now+1] == '.' || exp_map[x_now][y_now+1] == 'o')
		{
			y_now += 1;
			exp_map[x_now][y_now] = 'o';
		}
		else
		{
			d = (d+1)%4;
		}
	}
	else if (d == 1)
	{
		if (exp_map[x_now+1][y_now] == '.' || exp_map[x_now+1][y_now] == 'o')
		{
			x_now += 1;
			exp_map[x_now][y_now] = 'o';
		}
		else
		{
			d = (d+1)%4;
		}
	}
	else if (d == 2)
	{
		if (exp_map[x_now][y_now-1] == '.' || exp_map[x_now][y_now-1] == 'o')
		{
			y_now -= 1;
			exp_map[x_now][y_now] = 'o';
		}
		else
		{
			d = (d+1)%4;
		}
	}
	else if (d == 3)
	{
		if (exp_map[x_now-1][y_now] == '.' || exp_map[x_now-1][y_now] == 'o')
		{
			x_now -= 1;
			exp_map[x_now][y_now] = 'o';
		}
		else
		{
			d = (d+1)%4;
		}
	}
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> t;
	for (int i=1; i<=t; i++)
	{
		int ans = 0;
		cin >> x >> y >> k >> x_now >> y_now >> d;
		for (int ii=1; ii<=x; ii++)
		{
			string temp;
			cin >> temp;
			for (int iii=1; iii<=y; iii++)
			{
				exp_map[ii][iii] = temp[iii-1];
			}
		}
		exp_map[x_now][y_now] = 'o';
		while (k > 0)
			move();
		for (int ii=1; ii<=x; ii++)
		{
			for (int iii=1; iii<=y; iii++)
			{
				if (exp_map[ii][iii] == 'o')
					ans += 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
