#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, c, r;
struct node
{
	int sc;
	int id;
}a[105];

bool cmp(node x, node y)
{
	return x.sc > y.sc;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	s = n * m;
	for(int i = 1; i <= s; i++)
	{
		cin >> a[i].sc;
		a[i].id = i;
	}
	sort(a + 1, a + s + 1, cmp);
	for(int i = 1; i <= s; i++)
		if(a[i].id == 1)
		{
			t = i;
			break;
		}
	c = (t + n - 1) / n;
	if(c % 2)
		r = t - (c - 1) * n;
	else
		r = c * n + 1 - t;
	printf("%d %d", c, r);
	return 0;
}
