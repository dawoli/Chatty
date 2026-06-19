#include <bits/stdc++.h>
using namespace std;

int a[10][60];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	cout << n << endl; 
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		string b;
		int flag = 0;
		cin >> b;
		int ans = 0;
		if(b[1] <= '9')
		{
			ans = b[1] - '0';
		}
		else
		{
			if(b[1] == 'T')
			{
				ans = 10;
			}
			if(b[1] == 'J')
			{
				ans = 11;
			}
			if(b[1] == 'Q')
			{
				ans = 12;
			}
			if(b[1] == 'K')
			{
				ans = 13;
			}
		}
		if(b[0] == 'D')
		{
			if(a[1][ans] == 0)
			{
				cnt++;
				a[1][ans] = 1;
			}
		}
		if(b[0] == 'C')
		{
			if(a[2][ans] == 0)
			{
				cnt++;
				a[2][ans] = 1;
			}
		}
		if(b[0] == 'H')
		{
			if(a[3][ans] == 0)
			{
				cnt++;
				a[3][ans] = 1;
			}
		}
		if(b[0] == 'S')
		{
			if(a[4][ans] == 0)
			{
				cnt++;
				a[4][ans] = 1;
			}
		}
	}
	for(int i = 1;i <= 4;i++)
	{
		for(int j = 1;j <= 13;j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << 52 - cnt << endl;
	return 0;
}
