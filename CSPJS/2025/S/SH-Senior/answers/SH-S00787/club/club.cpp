#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define x first
#define y second
#define PII pair<int,int>
const int N=1e5+10,mod=1e9+7;
int a[N][4],m[N][4];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			m[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int maxx=0;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>=maxx)
			{
				maxx=a[i][j];
				m[i][3]=m[i][2];
				m[i][2]=m[i][1];
				m[i][1]=j;
			} 
			else
			{
				if(a[i][j]<=a[i][m[i][2]]) m[i][3]=j;
				else m[i][3]=m[i][2],m[i][2]=j;
			}
		}
	}
	long long ans=0;
	priority_queue<PII,vector<PII>,greater<PII> > q[4];
	for(int i=1;i<=n;i++)
	{
		int m1=m[i][1],m2=m[i][2],m3=m[i][3];
		if(q[m1].size()+1<=n/2)
		{
			ans+=a[i][m1];
			q[m1].push({a[i][m1]-a[i][m2],i});
		}
		else
		{
			auto it=q[m1].top();
			int t=it.x,id=it.y;
				if(a[i][m1]-a[i][m2]>=a[id][m[id][1]]-a[id][m[id][2]])
				{
					ans-=a[id][m[id][1]];
					ans+=a[id][m[id][2]];
					q[m[id][1]].pop();
					q[m[id][2]].push({a[id][m[id][2]]-a[id][m[id][3]],id});
					ans+=a[i][m1];
					q[m1].push({a[i][m1]-a[i][m2],i});
					m[id][1]=m[id][2];
					m[id][2]=m[id][3];
				}
				else
				{
					ans+=a[i][m2];
					q[m2].push({a[i][m2]-a[i][m3],i});
					m[i][1]=m2;
					m[i][2]=m3;
				}	
		}
	}
	cout<<ans<<endl;
	return ;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
}
