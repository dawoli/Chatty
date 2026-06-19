#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	for(int s=1;s<=t;s++)
	{
		int n,cnt=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int b[2*n+1][n+1],maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{	
				b[2*i-1][i]=1;
				b[2*i][i]=0;
			}
		}
		for(int h=1;h=2*n+1;h++)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=i;j++)
				{
					if(a[i]==a[j]&&b[h][i]==b[h][j])
					{
						sum+=a[i];
					}
				}
			}
			if(sum>=maxn)
			{
				maxn=sum;
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
