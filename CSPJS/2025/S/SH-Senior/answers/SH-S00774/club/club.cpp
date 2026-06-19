#include<bits/stdc++.h>
using namespace std;
int a[100005][5],n,ans,nw[100005];
void dfs(int now,int num,int sum,int an,int bn,int cn)
{
	if(num==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=now;i<=n;i++)
	{
		if(an<n/2) dfs(i+1,num+1,sum+a[i][1],an+1,bn,cn);
		if(bn<n/2) dfs(i+1,num+1,sum+a[i][2],an,bn+1,cn);
		if(cn<n/2) dfs(i+1,num+1,sum+a[i][3],an,bn,cn+1);
	}
}
void solve()
{
	ans=0;
	bool thr=0,two=0,one=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]) one=1;
		if(a[i][2]) two=1;
		if(a[i][3]) thr=1;
	}
	if(!two&&!thr)
	{
		int cnt=0;
		for(int i=1;i<=n;i++) nw[++cnt]=a[i][1];
		sort(nw+1,nw+1+cnt);
		for(int i=1;i<=n/2;i++) ans+=nw[n-i+1];
		cout<<ans<<'\n';
		return;
	}
	else if(n<=14)
	{
		dfs(1,0,0,0,0,0);
		cout<<ans<<'\n';
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans+=max({a[i][1],a[i][2],a[i][3]});
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

