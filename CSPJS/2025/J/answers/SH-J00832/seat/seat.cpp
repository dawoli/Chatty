#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[110], score, ans1, ans2;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	score = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++)
	{
		if (score == a[i])
		{
			score = i;
			break;
		}
	}
	ans1 = (score - 1) / n + 1;
	cout << ans1 << " ";
	if (ans1 % 2)
	{
		cout << score - n * (ans1 - 1) << endl;
	}
	else
	{
		ans2 = score - n * (ans1 - 1);
		cout << n + 1 - ans2 << endl;
	}
	return 0;
}
