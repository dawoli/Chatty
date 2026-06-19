#include <iostream>
#include <cstdio>
using namespace std;
bool f[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char a,b;
		cin >> a >> b;
		if (a == 'D')
		{
			if (b == 'A') f[1][1] = 1;
			if (isdigit(b)) f[1][b-'0'] = 1;
			if (b == 'T') f[1][10] = 1;
			if (b == 'J') f[1][11] = 1;
			if (b == 'Q') f[1][12] = 1;
			if (b == 'K') f[1][13] = 1;
		}
		if (a == 'C')
		{
			if (b == 'A') f[2][1] = 1;
			if (isdigit(b)) f[2][b-'0'] = 1;
			if (b == 'T') f[2][10] = 1;
			if (b == 'J') f[2][11] = 1;
			if (b == 'Q') f[2][12] = 1;
			if (b == 'K') f[2][13] = 1;
		}
		if (a == 'H')
		{
			if (b == 'A') f[3][1] = 1;
			if (isdigit(b)) f[3][b-'0'] = 1;
			if (b == 'T') f[3][10] = 1;
			if (b == 'J') f[3][11] = 1;
			if (b == 'Q') f[3][12] = 1;
			if (b == 'K') f[3][13] = 1;
		}
		if (a == 'S')
		{
			if (b == 'A') f[4][1] = 1;
			if (isdigit(b)) f[4][b-'0'] = 1;
			if (b == 'T') f[4][10] = 1;
			if (b == 'J') f[4][11] = 1;
			if (b == 'Q') f[4][12] = 1;
			if (b == 'K') f[4][13] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			if (f[i][j]) ans++;
	cout << 52-ans << endl;
	return 0;
}
