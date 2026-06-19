#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1005][1005],f[1005][1005][2];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int j=1;j<=m;j++)
	{
		f[0][j][0]=INT_MIN;
		f[n+1][j][1]=INT_MIN;
	}
	f[0][1][0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i][1][0]=a[i][1]+f[i-1][1][0];
		f[i][1][1]=INT_MIN;
	}
	for(int j=2;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
			f[i][j][0]=max(f[i-1][j][0],max(f[i][j-1][0],f[i][j-1][1]))+a[i][j];
		for(int i=n;i>=1;i--)
			f[i][j][1]=max(f[i+1][j][1],max(f[i][j-1][0],f[i][j-1][1]))+a[i][j];
	}
	cout<<f[n][m][0];
	return 0;
}