#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int t,n,a[100005][4],b[100005];
int c(int m,int n,int p,int q)
{
	return a[1][m]+a[2][n]+a[3][p]+a[4][q];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	bool flag1 = true,flag2 = true;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0) flag1 = false;
			if (a[i][3] != 0)
			{
				flag1 = false;
				flag2 = false;
			}
		}
		if (n == 2)
		{
			cout << min({a[1][1]+a[2][2],a[1][1]+a[2][3],a[1][2]+a[2][1],a[1][2]+a[2][3],a[1][3]+a[2][1],a[1][3]+a[2][2]}) << endl;
		}
		if (n == 4)
		{
			cout << min({c(1,1,2,2),c(1,1,2,3),c(1,1,3,2),c(1,1,3,3),c(1,2,1,2),c(1,2,1,3),c(1,2,2,1),c(1,2,2,3),c(1,2,3,1),c(1,2,3,2),c(1,2,3,3),c(1,3,1,2),c(1,3,1,3),c(1,3,2,1),c(1,3,2,2),c(1,3,2,3),c(1,3,3,1),c(1,3,3,2),c(2,1,1,2),c(2,1,1,3),c(2,1,2,1),c(2,1,2,3),c(2,1,3,1),c(2,1,3,2),c(2,1,3,3),c(2,2,1,1),c(2,2,1,3),c(2,2,3,1),c(2,2,3,3),c(2,3,1,1),c(2,3,1,2),c(2,3,1,3),c(2,3,2,1),c(2,3,2,3),c(2,3,3,1),c(2,3,3,2),c(3,1,1,2),c(3,1,1,3),c(3,1,2,1),c(3,1,2,2),c(3,1,2,3),c(3,1,3,1),c(3,1,3,2),c(3,2,1,1),c(3,2,1,2),c(3,2,1,3),c(3,2,2,1),c(3,2,2,3),c(3,2,3,1),c(3,2,3,2),c(3,3,1,1),c(3,3,1,2),c(3,3,2,1),c(3,3,2,2)}) << endl;
		}
		if (flag1)
		{
			for (int i = 1;i <= n;i++) b[i] = a[i][1];
			sort(b+1,b+n+1);
			int ans = 0;
			for (int i = n;i >= n/2+1;i--)
			{
				ans += b[i];
			}
			cout << ans << endl;
		}
	}
	return 0; 
}
