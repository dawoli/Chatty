#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5007];
int flag = 0;
int dp(int x,int y,int m,int z,int k)
{
	if(k == 1)
	{
		if(m >= 3)
		{
			if(x > z*2)
			{
				flag++;
			}
		}
	}
	if(y >= n)
	{
		return 0;
	}
	dp(x,y+1,m,z,0);
	z = max(z,a[y]);
	dp(x+a[y],y+1,m+1,z,1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	dp(0,0,0,0,0);
	cout << flag%998244353;
	return 0;
}
