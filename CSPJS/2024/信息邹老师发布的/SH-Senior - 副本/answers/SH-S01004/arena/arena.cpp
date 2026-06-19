#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, K, T;
int A[N] = {};
int _a[N] = {};
int a[N] = {};
int c[N] = {};
char d[30][50000000] = {};
int b[260][5] = {};
int e[5] = {};

int main()
{
	freopen("arena5.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> _a[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	for (int i = 1; i <= 30; i++)
	{
		if (pow (2, i) >= n)
		{
			K = i;
			break;
		}
	}
	for (int i = 1; i <= K; i++)
	{
		for (int j = 1; j <= pow (2, K - i); j++)
			cin >> d[i][j];
	}
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= 3; j++)
			cin >> e[j];
		for (int j = 1; j <= n; j++)
			a[j] = _a[j] ^ e[j % 4];
		int s = a[1];
		for (int j = 2; j <= n; j++)
			s ^= j * a[j];
		cout << s << endl;
	}
	return 0;
}
