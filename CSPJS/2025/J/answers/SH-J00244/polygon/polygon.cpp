#include <bits/stdc++.h>
using namespace std;
int n,ans,k[10000],sum;//k为选中边的第side条边的下标
double a[10000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)//边数
	{
		for(int r=i;r<=n;r++)//最大值
		{
			for(int side=1;side<i;side++)
			{
				k[side]=side;
			}
			for(int t=n;t<=i;t++)
			{
				for(int j=i;j>=1;j--)
				{
					for(int ce=j;ce<r;ce++)
					{
						k[j]=ce;
						for(int c=1;c<=n;c++)
						{
						sum+=a[k[c]];
						}
						if(sum>a[r])
						{
							ans++;
							ans%=998244353;
						}
						ans=0;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
