#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[201],f[201][201],ans=INT_MIN;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)
		f[i][i]=0;
	for(int i=1;i<2*n;i++)
		f[i][i+1]=a[i]*a[i+1]*a[i+2];
	for(int L=3;L<=n;L++)
		for(int i=1;i+L-1<=2*n;i++)
		{
			int j=i+L-1,&fij=f[i][j];
			for(int k=i;k<j;k++)
				fij=max(fij,f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
		}
	for(int i=1;i<=n;i++)
	{
		int j=i+n-1;
		ans=max(ans,f[i][j]);
	}
	cout<<ans;
	return 0;
}
//27min