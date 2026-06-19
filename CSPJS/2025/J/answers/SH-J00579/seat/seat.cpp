#include<bits/stdc++.h>
using namespace std;
int a[102];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int q = a[1];
	int t;
	sort(a + 1, a + n * m + 1);
	for(int i = n * m; i >= 1; i--)
	{
		if(a[i] == q)
		{
			t = i;
			break;
		}
	}
	t = n * m - t + 1;
	int c, s;
	if(t % n != 0) c++;
	c += t / n;
	if(c % 2 == 0)
	{
		t %= n;
		if(t == 0)
		{
			t = n;
		}
		s = n - t + 1;
	}
	else
	{
		t = t % n;
		if(t == 0)
		{
			t = n;
		}
		s = t;
	}
	cout << c << " " << s;
	return 0;
 } 
