#include <bits/stdc++.h>
using namespace std;
int n, m, nw, ps;
struct mark
{
	int pos, mk;
} marks[100];
int rw, ln;
bool cmp(mark a, mark b)
{
	return a.mk > b.mk;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%d", &marks[0].mk);
	marks[0].pos = 0;
	nw = marks[0].mk;
	for (int i = 1; i < n * m; i++)
	{
		scanf("%d", &marks[i].mk);
		marks[i].pos = i;
	}
	sort(marks, marks + n * m, cmp);
	for (int i = 0; i < n * m; i++)
	{
		if (marks[i].mk == nw)
		{
			ps = i;
		}
	}
	ln = ps / n;
	if (ln & 1)
	{
		rw = n - 1 - (ps % m);
	}
	else
	{
		rw = ps % n;
	}
	printf("%d %d", ln + 1, rw + 1);
	return 0;
}
