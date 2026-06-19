// Problem URL: https://www.luogu.com.cn/problem/P11247
// Finish Time: 2026/3/1 10:03:25 AC（结构体）
// Finish Time: 2026/2/28 18:22:26 AC(sort有greater比较器)
// Finish Time: 2026/2/28 18:15:44 AC(sort无比较器)
// Finish Time: 2026/2/28 17:36:00 WA 45pts
// Start Time: 2026/2/28 17:12:21

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Problem
{
	int a,b;
	bool operator<(const Problem &comp)const
	{
		return a>comp.a;
	}
}p[100001];
int m,n,k,ans=0,over=0,mxc=INT_MIN,mxn,lrt[100001],chs[100001],prb[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].b;
		prb[p[i].a]++;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		if(lrt[p[i].a]>=k)continue;
		ans++;
		lrt[p[i].a]+=p[i].b;
		chs[p[i].a]++;
		if(lrt[p[i].a]>=k)over++;
		if(chs[p[i].a]>mxc)
		{
			mxc=chs[p[i].a];
			mxn=prb[p[i].a];
		}
		else if(mxc==chs[p[i].a])mxn=min(mxn,prb[p[i].a]);
	}
	if(over<m||2*mxc-1>n||mxc>n-mxn+1)cout<<-1;
	else cout<<max(ans,2*mxc-1);
	return 0;
}