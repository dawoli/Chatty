#include <bits/stdc++.h>
using namespace std;

long long n, r[100005], t[100005], smaller;

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
		t[r[i]]++;
	}
	sort(r + 1, r + n + 1);
	int i = 1;
	while (i <= n)
	{
		if (r[i] != r[i - 1])
		{
			smaller = max(0ll, smaller - t[r[i]]) + t[r[i]];
		}
		i++;
	}
	cout << smaller << endl;
	return 0;
}
