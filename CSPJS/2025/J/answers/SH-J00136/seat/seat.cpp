#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int y = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == y)
		{
			int h = n * m - i + 1;
			int u = (h - 1) / n + 1;
			if(u % 2 == 1)
			{
				cout << u << ' ';
				if(h % n == 0)
				{
					cout << n;
				}
				else
				{
					cout << h % n;
				}
			}
			else
			{
				cout << u << ' ' << n - h % n + 1;
			}
		}
	}
	return 0;
} 
/*
freopen(".in","r",stdin);
freopen(".out","w",stdout);

*/
