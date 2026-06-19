#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005];
int t,n,m,L,V;
int d[100005],v[100005],a[100005],k,wei,sp,p[100005],sum,cnt[100005],minn=1e9,maxn=-1;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);

	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
		cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			k=d[i];
			sp=v[i];
			while(k<L&&sp>0)
			{
				wei=k;
				k+=sp;
				sp-=a[i]; 
				for(int j=1;j<=m;j++)
				{
					if(wei<=p[j]&&k>=p[j])
					{
					cnt[p[j]]++;
					dp[p[j]][cnt[p[j]]]=i;
					}
				} 
			}
		}
		for(int i=1;i<=m;i++)
		{
		sum+=p[i];
		minn=min(minn,sum);
		maxn=max(maxn,sum);
		}
		cout<<sum/n<<" "<<(maxn+minn)/2;
	}
	return 0;
}
