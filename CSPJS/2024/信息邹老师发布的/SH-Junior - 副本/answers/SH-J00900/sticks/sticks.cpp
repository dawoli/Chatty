#include <bits/stdc++.h>
using namespace std;
vector <int> v[11];
int sticks[11];
int ans[51];
int a[100009];
int cache[100009];
bool mem[100009];
void initarray()
{
	sticks[0] = 6;
	sticks[1] = 2;
	sticks[2] = 5;
	sticks[3] = 5;
	sticks[4] = 4;
	sticks[5] = 5;
	sticks[6] = 6;
	sticks[7] = 3;
	sticks[8] = 7;
	sticks[9] = 6;
}
int count_sticks(int x)
{
	initarray();
	int cnt = 0;
	while (x)
	{
		cnt += sticks[x % 10];
		x /= 10;
	}
	return cnt;
}
void initans()
{
	for (int i = 0; i <= 100001; i++)
		a[i] = count_sticks(i);
}
int find(int x)
{
	initans();
	if (mem[x])
		return cache[x];
	mem[x] = true;
	if (x < 2)
		return cache[x] = -1;
	for (int i = 0; i <= 100001; i++)
	{
		if (a[i] == x)
			return cache[x] = i;
	}
	return cache[x] = -1;
}
int main ()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	initarray();
	initans();
	int t;
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		int n;
		cin >> n;
		ans[q] = find(n);
	}
	for (int i = 1; i <= t; i++)
		cout << ans[i] << "\n";
	return 0;
}
