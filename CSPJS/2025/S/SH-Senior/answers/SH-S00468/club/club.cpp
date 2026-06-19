#include <bits/stdc++.h>
using namespace std;
const int N=100010;
long long dp[4][N];
long long ans=0;
int a[N][4];
int shen[4];
int t,n,flag=1;
void dfs(int num,long long s)
{
	if(num==n+1){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(shen[i]>=1)
		{
			shen[i]--;
			dfs(num+1,s+a[num][i]);
			shen[i]++;
		}
	}
}
int main(){
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;flag=1;
		for(int i=1;i<=3;i++)
		{
			shen[i]=n/2;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==2&&a[i][j]!=0)flag=0;
				if(j==3&&a[i][j]!=0)flag=0;
			}
		}
		if(flag==1)
		{
			priority_queue<int> q;
			for(int i=1;i<=n;i++)
			{
				q.push(a[n][1]);
			}
			for(int i=1;i<=n/2;i++)
			{
				ans+=q.top();
				q.pop();
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	
	return 0;
}
