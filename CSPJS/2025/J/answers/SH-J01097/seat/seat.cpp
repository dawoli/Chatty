#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200];
bool cmp(int a, int b)
{
	return a > b;
}
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int R = a[1];
	sort(a + 1, a + n + 1, cmp);
	int R_position;
	for(int i = 1; i <= n * m; i++) if(a[i] == R) R_position = i;
	int c = R_position / n;	
	int r;
	if(c % 2 == 1)
	{
		if(R_position % n == 0) r = n;
		else r = R_position % n;
	}
	else
	{
		if(R_position % n == 0) r = 1;
		else r = n - R_position % n + 1;
	}
	cout << c << " " << r;
	return 0;
}
