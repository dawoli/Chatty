#include <bits/stdc++.h>
using namespace std;
int n,m,x,k;
int a[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == x)
		{
			k = n * m - i;
			break;
		}
	}
	if((k/n) % 2 == 0)
	{
		cout << k/n + 1 << " " << k%n + 1;
	}
	else
	{
		cout << k/n + 1 << " " << n - k%n;
	}
	return 0;
}
