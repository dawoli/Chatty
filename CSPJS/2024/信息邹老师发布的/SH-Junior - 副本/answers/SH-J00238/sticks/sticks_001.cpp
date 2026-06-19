#include<bits/stdc++.h>
using namespace std;
const char min_num[8]={0,0,1,7,4,2,6,8};
struct DP
{
	int len,nxt;
	char l;
}dp[100001];
int T,n[51],i,j,max_n=0;
void giv_dp(int a,int b)
{
	dp[a].l=dp[b].l;
	dp[a].len=dp[b].len;
	dp[a].nxt=dp[b].nxt;
}
bool cmp(int a,int b)
{
	if(dp[a].len!=dp[b].len)
		return dp[a].len<dp[b].len;
	while(a!=-1)
	{
		if(dp[a].l!=dp[b].l)
			return dp[a].l<dp[b].l;
		a=dp[a].nxt;
		b=dp[b].nxt;
	}
}
void print(int a)
{
	bool f=true;
	while(a!=-1)
	{
		if(!f)
		{
			if(dp[a].l=='6')cout<<0;
			else cout<<dp[a].l;
		}
		else cout<<dp[a].l;
		a=dp[a].nxt;
		f=false;
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>n[i];
		max_n=max(max_n,n[i]);
	}
	for(i=2;i<=7;i++)
	{
		dp[i].l='0'+min_num[i];
		dp[i].len=1;
		dp[i].nxt=-1;
	}
	for(i=8;i<=max_n;i++)
	{
		dp[i].l='0'+min_num[2];
		dp[i].len=dp[i-2].len+1;
		dp[i].nxt=i-2;
		for(j=3;j<=7;j++)
		{
			if(i-j<2)continue;
			dp[0].l='0'+min_num[j];
			dp[0].len=dp[i-j].len+1;
			dp[0].nxt=i-j;
			if(cmp(0,i))
				giv_dp(i,0);
		}
	}
	for(i=1;i<=T;i++)
	{
		if(n[i]==1)cout<<-1<<endl;
		else
		{
			print(n[i]);
			cout<<endl; 
		}
	}
	return 0;
}
