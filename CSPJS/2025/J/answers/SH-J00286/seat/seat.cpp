#include<bits/stdc++.h>
using namespace std;

const int _ = 100 + 9;
bool cmp(int x, int y)
{
	return x > y;
}
int n, m, aim, a[_], b[_][_];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	aim = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int nw = 1;
	for(int j = 1;j <= m;j++)
		for(int i = (j % 2) ? 1 : n; (j % 2) ? (i <= n) : (i >= 1); (j % 2) ? i++ : i--)
			b[i][j] = a[nw++];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(b[i][j] == aim)
			{
				cout << j << ' ' << i;
				return 0;
			}
	
	return 0;
}
