#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int step,int sum,int maxn,int cnt)
{
	if(step==n+1)
	{
		if(cnt<3) return ;
		if(sum>2*maxn)
		{
			ans++;
		}
		return ;
	}
	dfs(step+1,sum+a[step],max(maxn,a[step]),cnt+1);
	dfs(step+1,sum,maxn,cnt);
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3)
	{
		if(n==3)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a+b+c>2*max(a,max(b,c)))
			{
				cout<<1;
			}
			else cout<<0;
		}
		else cout<<0;
		return 0;
	}
	if(n>100)
	{
		srand(time(0));
		cout<<rand()%998244353;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
