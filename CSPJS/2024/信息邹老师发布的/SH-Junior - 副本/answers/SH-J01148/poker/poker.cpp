#include<bits/stdc++.h>
using namespace std;
long long n, p[5][15], ans;
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>> n;
	for(int i = 1; i <= n; i++)
	{
		char a, b;
		cin >> a >> b;
		int t;
		if(a == 'S')
			t = 1;
		else if(a == 'H')
			t = 2;
		else if(a == 'D')
			t = 3;
		else
			t = 4;
		if(b == 'T')
			p[t][10] += 1;
		else if(b == 'A')
			p[t][1] += 1;
		else if(b == 'J')
			p[t][11] += 1;
		else if(b == 'Q')
			p[t][12] += 1;
		else if(b == 'K')
			p[t][13] += 1;
		else
			p[t][b - '0'] += 1;
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 13; j++)
		{
			if(p[i][j] != 0)
				ans++;
		}
	}
	cout << 52 - ans;
	return 0;
} 
