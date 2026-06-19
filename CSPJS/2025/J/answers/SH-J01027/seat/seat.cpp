#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 2; i <= n * m; i++)
	{
		if(a[i] > a[1])
		{
			cnt++;
		}
	}
	int x = cnt % n;
	int y = cnt / n;
	if(cnt == 0)
	{
		cout << "1 1\n";
	}
	else if(y * n == cnt)
	{
		if((y + 1) % 2 == 0)
		{
			cout << y + 1 << " "<< m << "\n";
		}
		else
		{
			cout << y + 1 << " "<< 1 << "\n";
		}
	}
	else
	{
		y += 1;
		if(y % 2 == 1)
		{
			cout << y << " "<< x + 1 << "\n";
		}
		else
		{
			cout << y << " "<< n - x << "\n";
		}
	}
	return 0;	
} 
