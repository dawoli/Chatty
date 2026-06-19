#include <bits/stdc++.h>
using namespace std;
int a[10002] = {};
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int Rscore = 0;
	int Rscore_id = 0;
	for (int i = 1; i <= n * m; i++)
	{
		int k;
		cin >> k;
		if(i == 1) Rscore = k;
		a[i] = k;
	}
	sort(a + 1, a + n * m + 1, [](int x, int y)
	{
		return x > y;
	});
	for (int i = 1; i <= n * m; i++)
		if (a[i] == Rscore)
			Rscore_id = i;
	int lie = ceil(Rscore_id * 1.0 / n);
	cout << lie << ' ';
	int id = 0;
	int hang = 1;
	if (lie % 2 == 1)
	{
		id = (lie - 1) * n + 1;
		hang += (Rscore_id - id);
		cout << hang;
	}
	else 
	{
		id = lie * n;
		hang += abs(Rscore_id - id);
		cout << hang;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
