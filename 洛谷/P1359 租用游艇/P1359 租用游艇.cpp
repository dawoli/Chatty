#include<bits/stdc++.h>
using namespace std;
int a[201][201],i,j,n,f[201];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
			cin>>a[i][j];
		f[i]=1e9;
	}
	for(i=n-1;i>=1;i--)
		for(j=i+1;j<=n;j++)
			f[i]=min(f[i],a[i][j]+f[j]);
	cout<<f[1];
	return 0;
}