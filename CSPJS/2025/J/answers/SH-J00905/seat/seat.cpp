#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int fen[110];


bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int r;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> fen[i];
	}
	r = fen[1];
	sort(fen + 1, fen + n * m + 1, cmp);
	int ans;
	for(int i = 1; i <= n * m; i++)
	{
		if(fen[i] == r) 
		{
			ans = i;
			break;
		}
	}
	int lie = ceil(ans* 1.0 / n);
	cout << lie << " ";
	if(lie % 2 == 0)
	{
		if(ans % n == 0) cout << 1;
		else cout << n - ans % n + 1;
	}
	else
	{
		if(ans % n == 0) cout << n;
		else cout << ans % n;
	}
	return 0;
}
