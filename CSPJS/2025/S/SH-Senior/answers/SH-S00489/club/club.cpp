#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define db long long
#define il inline
using namespace std;
const int N=1e5,M=3;
int a[N+10][M+2];
int n,ans=0;
vector<int> b[M+2];
il void work1(int v1)
{
	sort(b[v1].begin(),b[v1].end());
	int len=b[v1].size();
	for(int i=0;i<len-(n>>1);i++) 
	{
		ans-=b[v1][i];
	}
	return;
}
il void work()
{	
	for(int i=1;i<=M;i++) b[i].clear();
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int maxn=0;
		for(int j=1;j<=M;j++) maxn=max(maxn,a[i][j]);
		ans+=maxn;
		int cnt=0;
		for(int j=1;j<=M;j++) cnt+=maxn==a[i][j];
		if(cnt-1) continue;
		for(int j=1;j<=M;j++)
		{
			if(maxn==a[i][j])
			{
				int w1=0;
				for(int k=1;k<=M;k++) w1=max(w1,a[i][k]*(k!=j));
				b[j].push_back(maxn-w1);
				break;
			}
		}
	}
	for(int i=1;i<=M;i++)
	{
		if((b[i].size()<<1)>n)
		{
			work1(i);
			break;
		}
	}
	cout<<ans<<endl;
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}
//1499392690
//1500160377
//1499846353
//1499268379
//1500579370

