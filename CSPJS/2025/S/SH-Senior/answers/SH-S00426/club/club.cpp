#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
using i64=long long;
const int N=1e5+5;
int n,cnt[5];
int a[N][3];
int ans;
void dfs(int x,int sum1,int sum2,int sum3,int cnt1,int cnt2,int cnt3)
{
	if (x==n+1)
	{
		ans=max(ans,sum1+sum2+sum3);
		return ;
	}
	if (cnt1+1<=n/2)
	{
		dfs(x+1,sum1+a[x][1],sum2,sum3,cnt1+1,cnt2,cnt3);
	}
	if (cnt2+1<=n/2)
	{
		dfs(x+1,sum1,sum2+a[x][2],sum3,cnt1,cnt2+1,cnt3);
	}
	if (cnt3+1<=n/2)
	{
		dfs(x+1,sum1,sum2,sum3+a[x][3],cnt1,cnt2,cnt3+1);
	}
}
void solve()
{
	cin>>n;
	bool flag=1,flag2=1;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if ((a[i][1]==0)+(a[i][2]==0)+(a[i][3]==0)<2) flag=0;
		if ((a[i][1]==0)+(a[i][2]==0)+(a[i][3]==0)<1)	flag2=0;
	}
	if (flag)//特殊性质 A
	{
		priority_queue<int> q;
		for (int i=1;i<=n;i++)
		{
			q.push(max(a[i][1],a[i][2],a[i][3]));
		}
		int sum=0;
		for (int i=1;i<=n/2;i++)
		{
			sum+=q.top();
			q.pop();
		}
		cout<<sum<<"\n";
	}else if (n<=30)//暴搜 
	{
		ans=0;
		dfs(1,0,0,0,0,0,0);
		cout<<ans<<"\n";
	}else if (flag2)//特殊性质B 
	{
		cout<<"\n";
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
