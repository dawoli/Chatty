#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], cur;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int c = a[1];
	sort(a+1, a+n*m+1);
	for(int i = 1; i <= n*m; i++)
		if(a[i] == c)
			cur = n*m-i+1;
	cout << cur << endl;
	int x = (cur-1)/m+1;
	int y = (cur-1)%m;
	if(x % 2 == 1)
	{
		cout << x << " " << y+1;
	}
	else
	{
		cout << x << " " << m-y;
	}
	return 0;
}
