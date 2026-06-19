#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int T, n;
int a[N] = {};
bool b[N] = {};
long long ans = 0;

long long sc ()
{
	long long tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 1; j--)
		{
			if (b[i] == b[j] && a[i] == a[j])
			{
				tmp += a[i];
				break;
			}
		}
	}
	return tmp;
}

void calc (int s)
{
	if (s > n)
	{
		if (sc() > ans)
			ans = sc();
	}
	else
	{
		for (int i = 0; i <= 1; i++)
		{
			b[s] = i;
			calc(s + 1);
		}
	}
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		ans = 0;
		calc(1);
		cout << ans << endl;
	}
	return 0;
}
