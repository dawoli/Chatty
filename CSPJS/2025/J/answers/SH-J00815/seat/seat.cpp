#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Stu
{
	int score, id;
	bool operator < (const Stu &x) const
	{
		return score > x.score;
	}
} a[105];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
	{
		scanf("%d", &a[i].score);
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1);
	int now;
	for (int i = 1; i <= n * m; i++)
		if (a[i].id == 1)
		{
			now = i;
			break;
		}
	int col = (now - 1) / n + 1;
	int row;
	if (col % 2 == 1)
	{
		row = now - col * n + n;
	}
	else
	{
		row = col * n - now + 1;
	}
	printf("%d %d\n", col, row);
	return 0;
}
