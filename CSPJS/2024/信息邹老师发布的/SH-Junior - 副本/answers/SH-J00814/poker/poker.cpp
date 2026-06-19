#include <iostream>
#include <cstdio>
using namespace std;
int n,idx,idy,vis[20][20],ans = 52;
char x,y;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> x >> y;
		if (x == 'D') idx = 1;
		else if (x == 'C') idx = 2;
		else if (x == 'H') idx = 3;
		else idx = 4;
		if (y == 'A') idy = 1;
		else if ('2'<=y && y<='9') idy = y-'0';
		else if (y == 'T') idy = 10;
		else if (y == 'J') idy = 11;
		else if (y == 'Q') idy = 12;
		else idy = 13;
		vis[idx][idy] = 1;
	}
	for (int i = 1;i <= 4;i++)
	{
		for (int j = 1;j <= 13;j++)
		{
			if (vis[i][j]) ans--;
		}
	}
	cout << ans;
	return 0;
}
