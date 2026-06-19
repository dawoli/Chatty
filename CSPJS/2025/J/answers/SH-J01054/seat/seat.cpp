#include <bits/stdc++.h>
using namespace std;

int seat[110];
int n, m, a, sc;
int r, c;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n*m; i++) scanf("%d", &seat[i]);
	a = seat[1];
	sort(seat+1, seat+n*m+1, cmp);
	for (int i = 1; i <= n*m; i++)
	{
		if (seat[i] == a)
		{
			sc = i;
			break;
		}
	}
	r = (sc-1)/n+1;
	c = (sc-1)%n+1;
	if (r % 2 == 0) printf("%d %d", r, n-c+1);
	else printf("%d %d", r, c);
	return 0;
}
