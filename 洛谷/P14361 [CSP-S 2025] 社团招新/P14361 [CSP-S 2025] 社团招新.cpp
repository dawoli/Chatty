// Problem URL: https://www.luogu.com.cn/problem/P14361
// Finish Time: 2026/5/16 22:20:31 AC
// Start Time: 2026/5/16 21:08:58

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int t,n,ans,o;
int a[4][100005];
int c[4];
priority_queue<int,vector<int>,greater<int> > q[4];
int second_max(int a,int b,int c)
{
	if(a>=b&&a>=c) return max(b,c);
	if(b>=a&&b>=c) return max(a,c);
	return max(a,b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--)
	{
		cin>>n;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		ans=c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			int x=max({a[1][i],a[2][i],a[3][i]}),y=second_max(a[1][i],a[2][i],a[3][i]);
			if(x==a[1][i])o=1;
			if(x==a[2][i])o=2;
			if(x==a[3][i])o=3;
			c[o]++;
			q[o].push(x-y);
			ans+=x;
		}
		o=0;
		int mx=max({c[1],c[2],c[3]});
		if(mx>n/2)
		{
			if(mx==c[1])o=1;
			if(mx==c[2])o=2;
			if(mx==c[3])o=3;
		}
		if(o==0)goto output;
		for(int i=1;i<=mx-n/2;i++)
		{
			int t=q[o].top();
			q[o].pop();
			ans-=t;
		}
	output:
		cout<<ans<<'\n';
	}
	return 0;
}