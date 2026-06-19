#include <bits/stdc++.h>
using namespace std;
int n, m;
bool cmp(int a, int b)
{
	return a > b;
}
pair<int, int> next_seat(pair<int, int> pos)
{
	int x = pos.first, y = pos.second;
	if (x % 2 && y == n)
		return {x + 1, y};
	if (!(x % 2) && y == 1)
		return {x + 1, y};
	if (x % 2)
		return {x, y + 1};
	return {x, y - 1};
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a = n * m;
	int sc[102];
	for (int i = 0; i < a; ++i)
		cin >> sc[i];
	int r = sc[0];
	sort(sc, sc + a, cmp);
	pair<int, int> pos = {1, 1};
	for (int i = 0; i < a; ++i)
	{
		if (sc[i] == r)
			break;
		pos = next_seat(pos);
	}
	cout << pos.first << " " << pos.second;
	return 0;
}

