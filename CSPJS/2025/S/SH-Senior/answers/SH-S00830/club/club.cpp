#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=100010;
int t,n,a[Maxn][5],f[210][210][210];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
			}
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					for(int k=0;k<=n/2;k++)
					{
						if(i-j-k>n/2||i-j-k<0) continue;
						if(j>=1)
						{
							f[i][j][k]=max(f[i][j][k],a[i][1]+f[i-1][j-1][k]);
						}
						if(k>=1)
						{
							f[i][j][k]=max(f[i][j][k],a[i][2]+f[i-1][j][k-1]);
						}
						if(i-j-k>=1)
						{
							f[i][j][k]=max(f[i][j][k],a[i][3]+f[i-1][j][k]);
						}
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					if(n-j-k>n/2) continue;
					ans=max(ans,f[n][j][k]);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		else{
			bool f1=1,f2=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					cin>>a[i][j];
				}
				if(a[i][2]==1) f1=0;
				if(a[i][3]==1) f2=0;
			}
			if(f2)
			{
				if(f1)
				{
					priority_queue<int> q;
					for(int i=1;i<=n;i++)
					{
						q.push(a[i][1]);
					}
					int ans=0;
					for(int i=1;i<=n/2;i++)
					{
						ans+=q.top();
						q.pop();
					}
					cout<<ans<<endl;
					continue;
				}
//				int ans=0;
//				priority_queue< pair<int,int> > q;
//				for(int i=1;i<=n;i++)
//				{
//					if(i<=n/2){
//						if()
//					}q.push({-a[i][2],a[i][1]}),ans+=a[i][1]+a[i][2];
//					else{
//						if(a[i][1]-q.top().first>q.top().second+a[i][2])
//						{
//							ans=ans-q.top().second-q.top().first;
//						}
//						else ans+=
//					}
//				}
			}
		}
	}
	return 0;
}
