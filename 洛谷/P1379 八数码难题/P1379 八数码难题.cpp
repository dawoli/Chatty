#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int bg, ed = 123804765;
int a[10];
map<int, int>rec[2];
queue<pair<int, bool>> q;

int change(int x, int op)
{
	for (int i = 9; i; i--)
	{
		a[i] = x % 10, x /= 10;
	}
	int p;
	for (int i = 1; i <= 9; i++)
	{
		if (a[i] == 0)
		{
			p = i;
			break;
		}
	}
	if (op == 1)
	{
		if (p <= 3) return - 1;
		swap(a[p], a[p - 3]);
	}
	else if (op == 2)
	{
		if (p >= 7) return - 1;
		swap(a[p], a[p + 3]);
	}
	else if (op == 3)
	{
		if ((p % 3) == 1) return - 1;
		swap(a[p], a[p - 1]);
	}
	else if (op == 4)
	{
		if ((p % 3) == 0) return - 1;
		swap(a[p], a[p + 1]);
	}
	x = 0;
	for (int i = 1; i <= 9; i++)
	{
		x *= 10;
		x += a[i];
	}
	return x;
}

void check(int x, pair<int, bool> h)
{
	if (x != -1)
	{
		if (rec[h.second ^ 1].count(x) == true)
		{
			cout << rec[h.second ^ 1][x] + rec[h.second][h.first] + 1;
			exit(0);
		}
		else
		{
			rec[h.second][x] = rec[h.second][h.first] + 1;
			q.push({x, h.second});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> bg;
	if (bg == ed)
	{
		cout << 0;
		return 0;
	}
	q.push({bg, 0});
	q.push({ed, 1});

	while (!q.empty())
	{
		auto h = q.front();
		q.pop();
		int x = change(h.first, 1);
		check(x, h);
		x = change(h.first, 2);
		check(x, h);
		x = change(h.first, 3);
		check(x, h);
		x = change(h.first, 4);
		check(x, h);
	}
	return 0;
}