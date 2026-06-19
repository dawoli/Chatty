#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
};
node a[1005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		if(n==2)
		{
			int a[4];
			int b[4];
			for(int i=1;i<=3;i++)
				cin>>a[i];
			for(int i=1;i<=3;i++)
				cin>>b[i];
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j)continue;
					ans=max(ans,a[i]+b[j]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==4)
		{
			int a[4];
			int b[4];
			int c[4];
			int d[4];
			for(int i=1;i<=3;i++)
				cin>>a[i];
			for(int i=1;i<=3;i++)
				cin>>b[i];
			for(int i=1;i<=3;i++)
				cin>>c[i];
			for(int i=1;i<=3;i++)
				cin>>d[i];
			int ans=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=1;k<=3;k++)
					{
						for(int l=1;l<=3;l++)
						{
							if(i==j&&i==k||i==j&&i==l||i==k&&i==l||j==k&&j==l)
								continue;
							ans=max(ans,a[i]+b[j]+c[k]+d[l]);
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==10)
		{
			int a[4],b[4],c[4],d[4],e[4],aa[4],bb[4],cc[4],dd[4],ee[4];
			for(int i=1;i<=3;i++)
				cin>>a[i];
			for(int i=1;i<=3;i++)
				cin>>b[i];
			for(int i=1;i<=3;i++)
				cin>>c[i];
			for(int i=1;i<=3;i++)
				cin>>d[i];
			for(int i=1;i<=3;i++)
				cin>>e[i];
			for(int i=1;i<=3;i++)
				cin>>aa[i];
			for(int i=1;i<=3;i++)
				cin>>bb[i];
			for(int i=1;i<=3;i++)
				cin>>cc[i];
			for(int i=1;i<=3;i++)
				cin>>dd[i];
			for(int i=1;i<=3;i++)
				cin>>ee[i];

			int ans=0;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=1;k<=3;k++)
					{
						for(int l=1;l<=3;l++)
						{
							for(int m=1;m<=3;m++)
							{
								for(int o=1;o<=3;o++)
								{
									for(int p=1;p<=3;p++)
									{
										for(int q=1;q<=3;q++)
										{
											for(int r=1;r<=3;r++)
											{
												for(int s=1;s<=3;s++)
												{
													if(i==j&&i==k&&i==l&&i==m&&i==o||i==j&&i==k&&i==l&&i==m&&i==p||i==j&&i==k&&i==l&&i==m&&i==q||i==j&&i==k&&i==l&&i==m&&i==r||i==j&&i==k&&i==l&&i==m&&i==s||i==j&&i==k&&i==l&&i==o&&i==p||i==j&&i==k&&i==l&&i==o&&i==q||i==j&&i==k&&i==l&&i==o&&i==r||i==j&&i==k&&i==l&&i==o&&i==s||i==j&&i==k&&i==l&&i==p&&i==q||i==j&&i==k&&i==l&&i==p&&i==r||i==j&&i==k&&i==l&&i==p&&i==s||i==j&&i==k&&i==l&&i==q&&i==r||i==j&&i==k&&i==l&&i==q&&i==s||i==j&&i==k&&i==l&&i==r&&i==s||i==j&&i==k&&i==m&&i==o&&i==p||i==j&&i==k&&i==m&&i==o&&i==q||i==j&&i==k&&i==m&&i==o&&i==r||i==j&&i==k&&i==m&&i==o&&i==s||i==j&&i==k&&i==m&&i==p&&i==q||i==j&&i==k&&i==m&&i==p&&i==r||i==j&&i==k&&i==m&&i==p&&i==s||i==j&&i==k&&i==m&&i==q&&i==r||i==j&&i==k&&i==m&&i==q&&i==s||i==j&&i==k&&i==m&&i==r&&i==s||i==j&&i==k&&i==o&&i==p&&i==q||i==j&&i==k&&i==o&&i==p&&i==r||i==j&&i==k&&i==o&&i==p&&i==s||i==j&&i==k&&i==o&&i==q&&i==r||i==j&&i==k&&i==o&&i==q&&i==s||i==j&&i==k&&i==o&&i==r&&i==s||i==j&&i==k&&i==p&&i==q&&i==r||i==j&&i==k&&i==p&&i==q&&i==s||i==j&&i==k&&i==p&&i==r&&i==s||i==j&&i==k&&i==q&&i==r&&i==s||i==j&&i==l&&i==m&&i==o&&i==p||i==j&&i==l&&i==m&&i==o&&i==q||i==j&&i==l&&i==m&&i==o&&i==r||i==j&&i==l&&i==m&&i==o&&i==s||i==j&&i==l&&i==m&&i==p&&i==q||i==j&&i==l&&i==m&&i==p&&i==r||i==j&&i==l&&i==m&&i==p&&i==s||i==j&&i==l&&i==m&&i==q&&i==r||i==j&&i==l&&i==m&&i==q&&i==s||i==j&&i==l&&i==m&&i==r&&i==s||i==j&&i==l&&i==o&&i==p&&i==q||i==j&&i==l&&i==o&&i==p&&i==r||i==j&&i==l&&i==o&&i==p&&i==s||i==j&&i==l&&i==o&&i==q&&i==r||i==j&&i==l&&i==o&&i==q&&i==s||i==j&&i==l&&i==o&&i==r&&i==s||i==j&&i==l&&i==p&&i==q&&i==r||i==j&&i==l&&i==p&&i==q&&i==s||i==j&&i==l&&i==p&&i==r&&i==s||i==j&&i==l&&i==q&&i==r&&i==s||i==j&&i==m&&i==o&&i==p&&i==q||i==j&&i==m&&i==o&&i==p&&i==r||i==j&&i==m&&i==o&&i==p&&i==s||i==j&&i==m&&i==o&&i==q&&i==r||i==j&&i==m&&i==o&&i==q&&i==s||i==j&&i==m&&i==o&&i==r&&i==s||i==j&&i==m&&i==p&&i==q&&i==r||i==j&&i==m&&i==p&&i==q&&i==s||i==j&&i==m&&i==p&&i==r&&i==s||i==j&&i==m&&i==q&&i==r&&i==s||i==j&&i==o&&i==p&&i==q&&i==r||i==j&&i==o&&i==p&&i==q&&i==s||i==j&&i==o&&i==p&&i==r&&i==s||i==j&&i==o&&i==q&&i==r&&i==s||i==j&&i==p&&i==q&&i==r&&i==s||i==k&&i==l&&i==m&&i==o&&i==p||i==k&&i==l&&i==m&&i==o&&i==q||i==k&&i==l&&i==m&&i==o&&i==r||i==k&&i==l&&i==m&&i==o&&i==s||i==k&&i==l&&i==m&&i==p&&i==q||i==k&&i==l&&i==m&&i==p&&i==r||i==k&&i==l&&i==m&&i==p&&i==s||i==k&&i==l&&i==m&&i==q&&i==r||i==k&&i==l&&i==m&&i==q&&i==s||i==k&&i==l&&i==m&&i==r&&i==s||i==k&&i==l&&i==o&&i==p&&i==q||i==k&&i==l&&i==o&&i==p&&i==r||i==k&&i==l&&i==o&&i==p&&i==s||i==k&&i==l&&i==o&&i==q&&i==r||i==k&&i==l&&i==o&&i==q&&i==s||i==k&&i==l&&i==o&&i==r&&i==s||i==k&&i==l&&i==p&&i==q&&i==r||i==k&&i==l&&i==p&&i==q&&i==s||i==k&&i==l&&i==p&&i==r&&i==s||i==k&&i==l&&i==q&&i==r&&i==s||i==k&&i==m&&i==o&&i==p&&i==q||i==k&&i==m&&i==o&&i==p&&i==r||i==k&&i==m&&i==o&&i==p&&i==s||i==k&&i==m&&i==o&&i==q&&i==r||i==k&&i==m&&i==o&&i==q&&i==s||i==k&&i==m&&i==o&&i==r&&i==s||i==k&&i==m&&i==p&&i==q&&i==r||i==k&&i==m&&i==p&&i==q&&i==s||i==k&&i==m&&i==p&&i==r&&i==s||i==k&&i==m&&i==q&&i==r&&i==s||i==k&&i==o&&i==p&&i==q&&i==r||i==k&&i==o&&i==p&&i==q&&i==s||i==k&&i==o&&i==p&&i==r&&i==s||i==k&&i==o&&i==q&&i==r&&i==s||i==k&&i==p&&i==q&&i==r&&i==s||i==l&&i==m&&i==o&&i==p&&i==q||i==l&&i==m&&i==o&&i==p&&i==r||i==l&&i==m&&i==o&&i==p&&i==s||i==l&&i==m&&i==o&&i==q&&i==r||i==l&&i==m&&i==o&&i==q&&i==s||i==l&&i==m&&i==o&&i==r&&i==s||i==l&&i==m&&i==p&&i==q&&i==r||i==l&&i==m&&i==p&&i==q&&i==s||i==l&&i==m&&i==p&&i==r&&i==s||i==l&&i==m&&i==q&&i==r&&i==s||i==l&&i==o&&i==p&&i==q&&i==r||i==l&&i==o&&i==p&&i==q&&i==s||i==l&&i==o&&i==p&&i==r&&i==s||i==l&&i==o&&i==q&&i==r&&i==s||i==l&&i==p&&i==q&&i==r&&i==s||i==m&&i==o&&i==p&&i==q&&i==r||i==m&&i==o&&i==p&&i==q&&i==s||i==m&&i==o&&i==p&&i==r&&i==s||i==m&&i==o&&i==q&&i==r&&i==s||i==m&&i==p&&i==q&&i==r&&i==s||i==o&&i==p&&i==q&&i==r&&i==s||j==k&&j==l&&j==m&&j==o&&j==p||j==k&&j==l&&j==m&&j==o&&j==q||j==k&&j==l&&j==m&&j==o&&j==r||j==k&&j==l&&j==m&&j==o&&j==s||j==k&&j==l&&j==m&&j==p&&j==q||j==k&&j==l&&j==m&&j==p&&j==r||j==k&&j==l&&j==m&&j==p&&j==s||j==k&&j==l&&j==m&&j==q&&j==r||j==k&&j==l&&j==m&&j==q&&j==s||j==k&&j==l&&j==m&&j==r&&j==s||j==k&&j==l&&j==o&&j==p&&j==q||j==k&&j==l&&j==o&&j==p&&j==r||j==k&&j==l&&j==o&&j==p&&j==s||j==k&&j==l&&j==o&&j==q&&j==r||j==k&&j==l&&j==o&&j==q&&j==s||j==k&&j==l&&j==o&&j==r&&j==s||j==k&&j==l&&j==p&&j==q&&j==r||j==k&&j==l&&j==p&&j==q&&j==s||j==k&&j==l&&j==p&&j==r&&j==s||j==k&&j==l&&j==q&&j==r&&j==s||j==k&&j==m&&j==o&&j==p&&j==q||j==k&&j==m&&j==o&&j==p&&j==r||j==k&&j==m&&j==o&&j==p&&j==s||j==k&&j==m&&j==o&&j==q&&j==r||j==k&&j==m&&j==o&&j==q&&j==s||j==k&&j==m&&j==o&&j==r&&j==s||j==k&&j==m&&j==p&&j==q&&j==r||j==k&&j==m&&j==p&&j==q&&j==s||j==k&&j==m&&j==p&&j==r&&j==s||j==k&&j==m&&j==q&&j==r&&j==s||j==k&&j==o&&j==p&&j==q&&j==r||j==k&&j==o&&j==p&&j==q&&j==s||j==k&&j==o&&j==p&&j==r&&j==s||j==k&&j==o&&j==q&&j==r&&j==s||j==k&&j==p&&j==q&&j==r&&j==s||j==l&&j==m&&j==o&&j==p&&j==q||j==l&&j==m&&j==o&&j==p&&j==r||j==l&&j==m&&j==o&&j==p&&j==s||j==l&&j==m&&j==o&&j==q&&j==r||j==l&&j==m&&j==o&&j==q&&j==s||j==l&&j==m&&j==o&&j==r&&j==s||j==l&&j==m&&j==p&&j==q&&j==r||j==l&&j==m&&j==p&&j==q&&j==s||j==l&&j==m&&j==p&&j==r&&j==s||j==l&&j==m&&j==q&&j==r&&j==s||j==l&&j==o&&j==p&&j==q&&j==r||j==l&&j==o&&j==p&&j==q&&j==s||j==l&&j==o&&j==p&&j==r&&j==s||j==l&&j==o&&j==q&&j==r&&j==s||j==l&&j==p&&j==q&&j==r&&j==s||j==m&&j==o&&j==p&&j==q&&j==r||j==m&&j==o&&j==p&&j==q&&j==s||j==m&&j==o&&j==p&&j==r&&j==s||j==m&&j==o&&j==q&&j==r&&j==s||j==m&&j==p&&j==q&&j==r&&j==s||j==o&&j==p&&j==q&&j==r&&j==s||k==l&&k==m&&k==o&&k==p&&k==q||k==l&&k==m&&k==o&&k==p&&k==r||k==l&&k==m&&k==o&&k==p&&k==s||k==l&&k==m&&k==o&&k==q&&k==r||k==l&&k==m&&k==o&&k==q&&k==s||k==l&&k==m&&k==o&&k==r&&k==s||k==l&&k==m&&k==p&&k==q&&k==r||k==l&&k==m&&k==p&&k==q&&k==s||k==l&&k==m&&k==p&&k==r&&k==s||k==l&&k==m&&k==q&&k==r&&k==s||k==l&&k==o&&k==p&&k==q&&k==r||k==l&&k==o&&k==p&&k==q&&k==s||k==l&&k==o&&k==p&&k==r&&k==s||k==l&&k==o&&k==q&&k==r&&k==s||k==l&&k==p&&k==q&&k==r&&k==s||k==m&&k==o&&k==p&&k==q&&k==r||k==m&&k==o&&k==p&&k==q&&k==s||k==m&&k==o&&k==p&&k==r&&k==s||k==m&&k==o&&k==q&&k==r&&k==s||k==m&&k==p&&k==q&&k==r&&k==s||k==o&&k==p&&k==q&&k==r&&k==s||l==m&&l==o&&l==p&&l==q&&l==r||l==m&&l==o&&l==p&&l==q&&l==s||l==m&&l==o&&l==p&&l==r&&l==s||l==m&&l==o&&l==q&&l==r&&l==s||l==m&&l==p&&l==q&&l==r&&l==s||l==o&&l==p&&l==q&&l==r&&l==s||m==o&&m==p&&m==q&&m==r&&m==s)continue;
													ans=max(ans,a[i]+b[j]+c[k]+d[l]+e[m]+aa[o]+bb[p]+cc[q]+dd[r]+ee[s]);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
 } 
