#include <iostream>
#include <cstdio>
using namespace std;

bool f[20][20];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n,cnt = 0;
	cin >> n;
	while(n--)
	{
		char a,b;
		cin >> a >> b;
		if(a == 'D')
		{
			if(b == 'T')
				f[1][10] = true;
			else if(b == 'J')
				f[1][11] = true;
			else if(b == 'Q')
				f[1][12] = true;
			else if(b == 'K')
				f[1][13] = true;
            else if(b == 'A')
                f[1][1] = true;
			else f[1][b - '0'] = true;
		}
		if(a == 'C')
		{
			if(b == 'T')
				f[2][10] = true;
			else if(b == 'J')
				f[2][11] = true;
			else if(b == 'Q')
				f[2][12] = true;
			else if(b == 'K')
				f[2][13] = true;
            else if(b == 'A')
                f[2][1] = true;
			else f[2][b - '0'] = true;
		}
		if(a == 'H')
		{
			if(b == 'T')
				f[3][10] = true;
			else if(b == 'J')
				f[3][11] = true;
			else if(b == 'Q')
				f[3][12] = true;
			else if(b == 'K')
				f[3][13] = true;
            else if(b == 'A')
                f[3][1] = true;
			else f[3][b - '0'] = true;
		}
		if(a == 'S')
		{
			if(b == 'T')
				f[4][10] = true;
			else if(b == 'J')
				f[4][11] = true;
			else if(b == 'Q')
				f[4][12] = true;
			else if(b == 'K')
				f[4][13] = true;
            else if(b == 'A')
                f[4][1] = true;
			else f[4][b - '0'] = true;
		}
	}
	for(int i = 1;i <= 4;i++)
		for(int j = 1;j <= 13;j++)
			if(!f[i][j]) cnt++;
	cout << cnt;
	return 0;
}
