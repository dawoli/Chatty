#include <bits/stdc++.h>
using namespace std;

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int answer, mn = INT_MAX;

void dfs(int n)
{
	if (n == 0)
	{
		mn = min(mn, answer);
		return;
	}
	else if (n < 0) return;
	else if (answer > mn) return;
	
	for (int i = 0; i <= 9; i++)
	{	if (answer == 0 && i == 0)
		{
			continue;
		}
		answer = answer * 10 + i;
		dfs(n - a[i]);
		answer /= 10;
	}
}
int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		mn = INT_MAX;
		cin >> n;
		dfs(n);
		if (mn == INT_MAX) mn = -1;
		cout << mn << endl;
	}
	return 0;
}
