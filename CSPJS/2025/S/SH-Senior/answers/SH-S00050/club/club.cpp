#include<bits/stdc++.h>
using namespace std;
const int N=210;
int sto[N][4];
long long dp[N][N][N];
int n;
vector<int>s;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			s.push_back(a); 
		}
	}
	sort(s.begin(),s.end());
	long long ans=0;
	for(int i=n/2+1;i<=n;i++)
	{
		ans+=s[i-1];
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		if(n>200)
		{
			solve();
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>sto[i][j];
				//cout<<sto[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(j>n/2)break;
				for(int k=0;k<=i-j;k++)
				{
					if(k>n/2)break;
					if(i-j-k>n/2)continue;
					if(j>0)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+sto[i][1]);
					}
					if(k>0)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+sto[i][2]);
					}
					if(i-j-k>0)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+sto[i][3]);
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
			}
		}
		long long ans=0;
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
			{
				if(j+k<n/2)continue;
				//cout<<j<<" "<<k<<" "<<n-j-k<<" "<<dp[n][j][k]<<endl;
				ans=max(ans,dp[n][j][k]);				
			}
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
