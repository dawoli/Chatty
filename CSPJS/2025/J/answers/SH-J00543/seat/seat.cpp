#include <bits/stdc++.h>
#define ui unsigned int
#define ull unsigned long long
#define ll long long
using namespace std;
int p[105], n, m, a, rk;
bool cmp(int a, int b){return a > b;};
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> p[i];
	a = p[1];
	sort(p + 1, p + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
		if(p[i] == a)
			rk = i;
	int x = (rk - 1) / n + 1;
	int y = rk % n;
	if(!y)
		y = n;
	if(!(x % 2))
		y = n - y + 1;
	cout << x << " " << y;
	return 0;
}
//please put me on the QIPADASHANG (LG UID: 1029108)
//100pts
