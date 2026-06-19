#include <bits/stdc++.h>
using namespace std;

int a[110];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, nn, r, c, d; // n行 m列，c为小r的行，d为小r的列 
	cin >> n >> m;
	nn = n * m;
	
	for(int i = 1; i <= nn; i++)
	{
		cin >> a[i];
		if(i == 1) r = a[i];
	}
	
	sort(a + 1, a + nn + 1, cmp);
	
//	for(int i = 1; i <= nn; i++)
//	{
//		cout << a[i] << " ";
//	}
	
	int p;
	for(int i = 1; i <= nn; i++)
	{
		if(a[i] == r) p = i;
	}
	
//	cout << p;

	if(p % n == 0)
	{
		d = p / n; 
		if(d % 2 != 0)
		{
			c = m;
		}
		else
		{
			c = 1;
		}
		
	}
	else
	{
		d = p / n + 1;
		if(d % 2 != 0)
		{
			c = p % n;
		}
		else
		{
			c = m - (p % n) + 1;
		}
	}
	
	cout << d << " " << c << endl;
	return 0;
}
