#include <bits/stdc++.h>
using namespace std;
int t,n,a[200005],b[200005],ans;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for (int u=1;u<=t;u++)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int x=1;
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (b[i]==1&&b[j]==1)
				{
					if (a[i]==a[j])
						ans+=a[i];
					continue;
				}
				if (b[j]==1)
				{
					x=0;
				}
				if (a[i]==a[j])
				{
					ans+=a[i];
					if (b[i]==1)
						x=1;
					if (x==1)
					{
						b[i]=b[j]=1;
						x=0;
					}
					else
					{
						int flag=1;
						for (int k=i+1;k<j;k++)
						{/*
							if (b[k]==1&&k!=i+1)
							{
								if (b[k]>b[i])
								{
									ans-=a[i];
									flag=0;
									for (int l=i+1;l<k;l++)
										l=0;
									break;
								}
								else
								{
									ans-=a[k];
								}
							}
							else
							{*/
							b[k]=1;
							//}
						}
						x=1;
					}
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
