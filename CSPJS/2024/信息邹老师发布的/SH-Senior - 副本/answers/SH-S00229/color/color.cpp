#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int t,a[200010];
long long b[30],s[33000][20],ans;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		if(n<=15)
		{
			int x=1<<n;
			for(int j=1;j<=x;j++)
			{
				int y=n,z=j;
				while(z>0)
				{
					s[j][y]=z%2;
					y--;
					z=z/2;
				}
			}
			for(int j=1;j<=x;j++)
			{
				long long sum=0;
				for(int k=2;k<=n;k++)
				{
					for(int l=k-1;l>=1;l--)
					{
						if(s[j][k]==s[j][l])
						{
							if(a[k]==a[l])
							{
								sum+=a[k];
							}
							break;
						}
					}
				}
				ans=max(sum,ans);
			}
			b[i]=ans;
			ans=0;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=j-1;k>=1;k--)
				{
					if(a[j]==a[k])
					{
						b[i]+=a[k];
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
