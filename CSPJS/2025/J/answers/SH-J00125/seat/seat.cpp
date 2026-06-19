#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int xm;
	int a[105] = {};
	for(int i = 0; i < n * m; i++)
	{
		int x;
		cin >> x;
		a[x] = 1;
		if(i == 0) xm = x;
	}
	
	int b[105];
	int bb = 0;
	for(int i = 100; i >= 0; i--)
	{
		if(a[i] == 1)
		{
			b[bb] = i;
			bb++;
		}
	}
	
	int h = 1, l = 1;
	bool f = false;
	for(int i = 0; i < n * m; i++)
	{
		if(b[i] == xm) 
		{
			cout << l << ' ' << h;
			return 0;
		}
		
		if(h == n && l != m && !f)
		{
			f = true;
			l++;
		}
		else if(h == 1 && l != m && i != 0 && f)
		{
			f = false;
			l++;
		}
		else if(f) h--;
		else h++;
	}
	
	return 0;
}
