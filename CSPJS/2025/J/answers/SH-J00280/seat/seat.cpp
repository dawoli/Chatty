#include <bits/stdc++.h>
using namespace std;

int n, m, a, q;
int s[105];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int l = n * m;
	for (int i = 1; i <= l; i++)
	{
		cin >> s[i];
	}
	int a = s[1];
	sort(s + 1, s + l + 1, cmp);
	for (int i = 1; i <= l; i++)
	{
		if (s[i] == a)
		{
			q = i;
			break;
		}
	}
	int t = q / n;
	int r = q % n;
	if ((q / n) % 2 == 0)
	{
		if (r == 0)
		{
			cout << t << " " << 1 << endl;
			return 0;
		}
		else 
		{
			cout << t + 1 << " " << r << endl;
			return 0;
		}
	}
	else 
	{
		if (r == 0)
		{
			cout << t << " " << n << endl;
			return 0;
		}
		else
		{
			cout << t + 1 << " " << n - r + 1 << endl;
			return 0;
		}
	}
	return 0;
} 
