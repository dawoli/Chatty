#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
}a[100005];
int t,n;
int dp1[205][205][205];//to i time a->j,b->k,(c->i-j-k)
int dp[100005][5];
int ans=0;
bool cmp(node x,node y)
{
	return x.a>y.a||x.a==y.a&&x.b<y.b;
}
bool cmp2(node x,node y)
{
	return x.b>y.b||x.b==y.b&&x.a<y.a;
}
bool fa=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0)
			{
				fa=0;
			}
		}
		if(n<=200)
		{
			memset(dp,0,sizeof(dp));
			dp1[1][1][0]=a[1].a;
			dp1[1][0][1]=a[1].b;
			dp1[1][0][0]=a[1].c;
			for(int i=2;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2&&j+k<=i;k++)
					{
						if(i-j-k>n/2)
						{
							continue;
						}
						if(j==0)
						{
							if(k==0)
							{
								dp1[i][j][k]=dp1[i-1][j][k]+a[i].c;
							}
							else if(i==k)
							{
								dp1[i][j][k]=dp1[i-1][j][k-1]+a[i].b;
							}
							else
							{
								dp1[i][j][k]=max(dp1[i-1][j][k]+a[i].c,dp1[i-1][j][k-1]+a[i].b);
							}
						}
						else
						{
							if(i==j)
							{
								dp1[i][j][k]=dp1[i-1][j-1][k]+a[i].a;
							}
							else if(k==0)
							{
								dp1[i][j][k]=max(dp1[i-1][j-1][k]+a[i].a,dp1[i-1][j][k]+a[i].c);
							}
							else
							{
								dp1[i][j][k]=max(dp1[i-1][j-1][k]+a[i].a,max(dp1[i-1][j][k-1]+a[i].b,dp1[i-1][j][k]+a[i].c));
							}
						}
//						cout<<i<<" "<<j<<" "<<k<<" "<<i-j-k<<" "<<dp1[i][j][k]<<endl;
					}
				}
			}
			for(int i=1;i<=n/2;i++)
			{
				for(int j=1;j<=n/2;j++)
				{
					ans=max(ans,dp1[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			if(fa)
			{
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
				{
					ans+=a[i].a;
				}
				for(int j=n/2+1;j<=n;j++)
				{
					ans+=a[j].b;
				}
				cout<<ans<<endl;
			}
			else
			{
				int ans1=0,ans2=0;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++)
				{
					ans1+=a[i].a;
				}
				for(int j=n/2+1;j<=n;j++)
				{
					ans1+=a[j].b;
				}
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++)
				{
					ans2+=a[i].a;
				}
				for(int j=n/2+1;j<=n;j++)
				{
					ans2+=a[j].b;
				}
				ans=max(ans1,ans2);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
/*
1
10
4 0 0
5 0 0
6 0 0
9 0 0
10 0 0
1000 0 0
1 0 0
1 0 0
1 0 0
1000000 0 0
*/
