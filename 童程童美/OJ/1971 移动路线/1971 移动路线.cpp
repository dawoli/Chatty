#include<bits/stdc++.h>
using namespace std;
long long a[21][21];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i][1]=1;
	for(int j=1;j<=m;j++)a[1][j]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
			a[i][j]=a[i-1][j]+a[i][j-1];
	}
	cout<<a[n][m];
    return 0;
}