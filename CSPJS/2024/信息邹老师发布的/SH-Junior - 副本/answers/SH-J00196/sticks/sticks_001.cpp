#include <bits/stdc++.h>
using namespace std;

void testIO()
{
	int n;
	cin >> n;
	cout << n << endl;
}

const int INF = 0x3f3f3f3f;
int T;
int n;

int s[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//         0  1  2  3  4  5  6  7  8  9

int a[] = {-1, -1, 1, 7, 4, 2, 0, 8, -1, -1};
//          0   1  2  3  4  5  6  7   8   9
int minn = INF;

void dfs(int step, int sum, int num)
{
	// cout << "step=" << step << " sum=" << sum << " num=" << num << endl;
	if (sum > n) return;
	if (sum == n)
	{
		minn = min(minn, num);
		return;
	}
	for (int i = 1; i <= 9; ++i)
	{
		int now = a[i];
		if (now == -1) continue;
		if (step == 1 && i == 6)
		{
			now = 6;
		}
		dfs(step + 1, sum + i, num * 10 + now);
	}
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	// testIO();
	cin >> T;
	while (T--)
	{
		minn = INF;
		cin >> n;
		if (n % 7 == 0 && n > 100)
		{
			for (int i = 1; i <= n / 7; ++i) cout << 8;
			cout << endl;
			continue;
		}
		if ((n - 1) % 7 == 0 && n > 100)
		{
			cout << 222;
			for (int i = 1; i <= (n - 1) / 7 - 1; ++i)
			{
				cout << 8;
			}
			cout << endl;
			continue;
		}
		dfs(1, 0, 0);
		if (minn == INF) cout << -1 << endl;
		else cout << minn << endl;
	}
	return 0;
}