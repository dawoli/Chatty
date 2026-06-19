#include<bits/stdc++.h>
using namespace std;
int v,n,a[31],f[31][20001];
int main()
{
	cin>>v>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=v;j++)
		{
			if (j<a[i])
				f[i][j]=f[i-1][j];
			else
			{
				f[i][j]=max(f[i-1][j],f[i][j-a[i]]+a[i]);
			}
		}
	cout<<v-f[n][v]<<endl;
	return 0;
}