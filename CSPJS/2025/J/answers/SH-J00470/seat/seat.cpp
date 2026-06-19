#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105], b[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int r;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> b[i];
		if (i == 1) r = b[i];
	}
	sort(b+1,b+n*m+1);
	for (int i = n*m; i >= 1; i--)
	{
		a[n*m+1-i] = b[i];
	}
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i] == r)
		{
			int c = ceil(i*1.0/n), x;
			if ((i-1)/n %2 == 0)
			{
				x = i%n;
				if (x == 0) x = n;
			}
			else
			{
				x = ((i-1)/n+1)*n+1-i;
			}
			cout << c << " " << x;
			return 0;
		}
	}
	return 0; 
}
