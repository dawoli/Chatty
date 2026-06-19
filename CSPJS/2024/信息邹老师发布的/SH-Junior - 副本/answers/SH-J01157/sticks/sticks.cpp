#include<bits/stdc++.h>
using namespace std;
long long t,ans;
void dfs(long long sum,int cnt)
{
	if(cnt<0) return;
	if(cnt==0)
	{
		ans=min(ans,sum);
		return;
	}
	if(sum==0)
	{
		dfs(1,cnt-2);
		dfs(2,cnt-5);
		dfs(4,cnt-4);
		dfs(6,cnt-6);
		dfs(7,cnt-3);
		dfs(8,cnt-7);
	}
	else
	{
		dfs(sum*10+0,cnt-6);
		dfs(sum*10+1,cnt-2);
		dfs(sum*10+2,cnt-5);
		dfs(sum*10+4,cnt-4);
		dfs(sum*10+7,cnt-3);
		dfs(sum*10+8,cnt-7);
	}
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		ans=4294967295;
		int n;
		cin>>n;
		dfs(0,n);
		if(n==1) cout<<-1<<endl;
		else     cout<<ans<<endl;
	}
}
