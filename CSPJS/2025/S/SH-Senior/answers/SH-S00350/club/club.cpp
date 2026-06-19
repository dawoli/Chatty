#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int t,n;
pair<int,int> a[maxn][4];
priority_queue<int> q[4];
int cnt[4];
int ans;

void init()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=3;i++)
	{
		while(!q[i].empty())
		{
			q[i].pop();
		}
	}
	ans=0;
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t-->0)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j].first; 
				a[i][j].second=j;
			}
			sort(a[i]+1,a[i]+3+1);
			reverse(a[i]+1,a[i]+3+1);
		}
		for(int i=1;i<=n;i++)
		{
			int cha=a[i][1].first-a[i][2].first;//ÊÕÒæ 
			if(cnt[a[i][1].second]<(n/2))
			{
				cnt[a[i][1].second]++;
				q[a[i][1].second].push(-cha);
				ans+=a[i][1].first;
			}
			else
			{
				if(-q[a[i][1].second].top()<cha)
				{
					ans+=a[i][1].first+q[a[i][1].second].top();
					q[a[i][1].second].pop();
					q[a[i][1].second].push(-cha);
				}
				else
				{
					ans+=a[i][2].first;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
