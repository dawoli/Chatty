#include<bits/stdc++.h>
using namespace std;
int a[5][14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(a,0,sizeof(a));
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		char x[2];
		int hua = 0;
		int shu = 0;
		cin >> x[0] >> x[1];
		if (x[0] == 'D') hua = 1;
		if (x[0] == 'C') hua = 2;
		if (x[0] == 'H') hua = 3;
		if (x[0] == 'S') hua = 4;
		if (x[1] == 'A') shu = 1;
		if (x[1] == 'T') shu = 10;
		if (x[1] == 'J') shu = 11;
		if (x[1] == 'Q') shu = 12;
		if (x[1] == 'K') shu = 13;
		if (not(x[1] == 'A'||x[1] == 'T'||x[1] == 'J'||x[1] == 'Q'||x[1] == 'K'))
		{
			shu = x[1] - 48;
		}
		a[hua][shu]++;
	}
	for (int i = 1;i <= 4;i++)
		for (int j = 1;j <= 13;j++)
		{
			if (a[i][j] == 0) ans++;
		}
	cout << ans;
	return 0;
} 
