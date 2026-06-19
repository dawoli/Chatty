#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int T,n,a[N][3],cnt[3],ans,c[N];
vector<int> costs;
int cal_max(int x,int y,int z)
{
	return max(x,max(y,z));
}
int cal_mid(int x,int y,int z)
{
	return x+y+z-max(x,max(y,z))-min(x,min(y,z));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		costs.clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			int maxn=0;
			maxn=cal_max(a[i][0],a[i][1],a[i][2]);
			for(int j=0;j<3;j++)
			{
				if(maxn==a[i][j])
				{
					c[i]=j;
					cnt[j]++;
					break;
				}
			}
			ans+=maxn;
		}
		//cout<<"ans="<<ans<<endl;
		for(int j=0;j<3;j++)
		{
			if(cnt[j]>n/2)
			{
				int res=cnt[j]-n/2;
				//cout<<"res:"<<res<<endl;
				for(int i=1;i<=n;i++)
				{
					if(c[i]==j)
						costs.push_back(cal_max(a[i][0],a[i][1],a[i][2])-cal_mid(a[i][0],a[i][1],a[i][2]));
				}
				sort(costs.begin(),costs.end());
				//cout<<"costs:";
				//for(auto i:costs) cout<<i<<" ";
				//cout<<endl;
				for(int i=0;i<res;i++)
				    ans-=costs[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
