#include <bits/stdc++.h>
using namespace std;
long long t,n;
const long long N=2e5+100;
long long a[N][4];
long long dp[N][4][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0)
	{
		t--;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<3;j++)
				cin>>a[i][j];
//			a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i][0]<a[j][0])
				{
					for(int q=0;q<4;q++)
						swap(a[i][q],a[j][q]);
				}
				else if(a[i][0]==a[j][0]&&a[i][1]<a[j][1])
				{
					for(int q=0;q<4;q++)
						swap(a[i][q],a[j][q]);
				}
				else if(a[i][1]==a[j][1]&&a[i][2]<a[j][2])
				{
					for(int q=0;q<4;q++)
						swap(a[i][q],a[j][q]);
				}
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long q=0;q<i;q++)
			{
				for(int j=0;j<4;j++)
					dp[i][0][j]=dp[q][0][j];
				for(int j=1;j<=3;j++)
				{
					for(int w=0;w<4;w++)
					{
//						if(q==3&&w==1&&i==4&&j==2)
//						{
//							cout<<"q";
//							cout<<dp[q][w][0]+a[i][j-1]<<" "<<dp[i][j][0]<<" "<<dp[q][w][j]<<endl;
//							cout<<dp[q][w][0]<<" "<<dp[q][w][1]<<" "<<dp[q][w][2]<<" "<<dp[q][w][3]<<" "<<endl;
//						}
						if(dp[q][w][0]+a[i][j-1]>dp[i][j][0]&&dp[q][w][j]<n/2)
						{
							for(int jj=0;jj<4;jj++)
								dp[i][j][jj]=dp[q][w][jj];
							dp[i][j][0]+=a[i][j-1];
							dp[i][j][j]++;
//							cout<<i<<" "<<j<<" "<<dp[q][w][0]<<endl;
						}
					}
				}
			}
//				for(int j=0;j<4;j++)
//					cout<<i<<" "<<j<<" "<<dp[i][j][0]<<endl;
		}
		long long int ma=0;
		for(int i=0;i<=3;i++)
			ma=max(dp[n][i][0],ma);
		cout<<ma<<endl; 
	}
} 
