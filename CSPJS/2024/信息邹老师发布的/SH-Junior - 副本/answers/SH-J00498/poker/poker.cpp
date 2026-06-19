#include <bits/stdc++.h>
#define ll long long

using namespace std; 

int n; 
bool a[5][14]; 

int main()
{
	freopen("poker.in", "r", stdin); 
	freopen("poker.out", "w", stdout); 
	cin >> n; 
	if(n == 1)
	{
		cout << 51; 
		return 0; 
	}
	for(int i = 1; i <= n; i++)
	{
		char c[2]; 
		cin >> c; 
		int x, y; 
		if(c[0] == 'D')
		{
			x = 1; 
		}
		else if(c[0] == 'C')
		{
			x = 2; 
		}
		else if(c[0] == 'H')
		{
			x = 3; 
		}
		else if(c[0] == 'S')
		{
			x = 4; 
		}
		
		if(c[1] >= '2' && c[1] <= '9')
		{
			y = (c[1] - '0'); 
		}
		else if(c[1] == 'A')
		{
			y = 1; 
		}
		else if(c[1] == 'T')
		{
			y = 10; 
		}
		else if(c[1] == 'J')
		{
			y = 11; 
		}
		else if(c[1] == 'Q')
		{
			y = 12; 
		}
		else if(c[1] == 'K')
		{
			y = 13; 
		}
		
		a[x][y] = true; 
		x = 0; 
		y = 0; 
	}
	
	int cnt = 0; 
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 13; j++)
		{
			if(a[i][j])
			{
				cnt++; 
			}
		}
	}
	cout << 52 - cnt; 
	return 0; 
}
