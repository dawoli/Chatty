#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[100001][4];
vector<int>v[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin>>ttt;
	while(ttt--)
	{
		int ans=0;
		for(int j=1;j<=3;j++)v[j].clear();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			int maxn=0,smax=0;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>maxn)
				{
					smax=maxn;
					maxn=a[i][j];
				}
				else if(a[i][j]>smax)smax=a[i][j];
			}
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]==maxn)
				{
					v[j].push_back(maxn-smax);
					break;
				}
			}
			ans+=maxn;
		}
		for(int j=1;j<=3;j++)sort(v[j].begin(),v[j].end());
		int t=0;
		for(int j=1;j<=3;j++)
		{
			if(v[j].size()>n/2)t=j;
		}
		if(t==0)
		{
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<v[t].size()-n/2;i++)ans-=v[t][i];
		cout<<ans<<endl;
	}
}