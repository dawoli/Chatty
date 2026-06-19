#include <bits/stdc++.h>
using namespace std;

int solvef(char a)
{
	if(a == 'D')
	{
		return 0;
	}
	if(a == 'C')
	{
		return 1;
	}
	if(a == 'H')
	{
		return 2;
	}
	if(a == 'S')
	{
		return 3;
	}
}


int solven(char a)
{
	if(a >= '2' && a <= '9')
	{
		return (int)(a - 49);
	}
	if(a == 'A')
	{
		return 0;
	}
	if(a == 'T')
	{
		return 9;
	}
	if(a == 'J')
	{
		return 10;
	}
	if(a == 'Q')
	{
		return 11;
	}
	if(a == 'K')
	{
		return 12;
	}
}


int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n, all[4][13] = {0}, cnt = 0;

	string x;
	cin >> n;
	
	for (int i = 0;i < n;i ++ )
	{
		cin >> x;
		all[solvef(x[0])][solven(x[1])] = 1;
	}
	for(int i = 0;i < 4;i ++ )
	{
		for(int j = 0;j < 13;j ++ )
		{
			if(all[i][j] == 0)
			{
				cnt ++ ;
			}
		}
	}
	cout << cnt;
	return 0;
}
