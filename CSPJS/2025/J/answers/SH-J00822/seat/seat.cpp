#include <bits/stdc++.h>
using namespace std;
int f[101][101];
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int bi=0;
	q=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=m;)
	{
		for(int j=1;j<=n;j++)
		{
			f[j][i]=a[m*n-bi];
			bi++;
		}
		i++;
		if(i>m)
			break;
		for(int j=n;j>=1;j--)
		{
			f[j][i]=a[m*n-bi];
			bi++;
		}
		i++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(f[j][i]==q)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
	return 0;
}
