#include <iostream>
#include <algorithm>
using namespace std;

const long long N = 998244353;

long long a[5010], s[5010], tol, n;

bool cmp(long long x, long long y)
{
	return (x < y);
}

void dfs(long long x, long long cnt, long long last)
{
	if(x > n)
	{
		if(cnt > 2 * last)
		{
			tol = (tol + 1) % N;
			for(int i = 1; i <= n; i++)
			{
				if(s[i] == 1)
					cout << a[i] << ' ';
			}
			cout << endl;
		}
		return;
	}
	s[x] = 0;
	dfs(x + 1, cnt, last);
	s[x] = 1;
	dfs(x + 1, cnt + a[x], a[x]);
	return;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	tol = 0;
	dfs(1, 0, 0);
	cout << tol << endl;
	return 0;
}
