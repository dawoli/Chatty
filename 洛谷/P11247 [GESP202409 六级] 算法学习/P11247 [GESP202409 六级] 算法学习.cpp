// Problem URL: https://www.luogu.com.cn/problem/P11247
// Finish Time: 2026/2/28 18:22:26 AC(sort有greater比较器)
// Finish Time: 2026/2/28 18:15:44 AC(sort无比较器)
// Finish Time: 2026/2/28 17:36:00 WA 45pts
// Start Time: 2026/2/28 17:12:21

#include <bits/stdc++.h>
#define ft first
#define sd second
using namespace std;
typedef long long int ll;
pair<int,int> p[100001];
int m,n,k,ans=0,over=0,mxc=INT_MIN,mxn,lrt[100001],chs[100001],prb[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].sd;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].ft;
		prb[p[i].sd]++;
	}
	sort(p+1,p+n+1,greater<pair<int,int>>());
	for(int i=1;i<=n;i++)
	{
		if(lrt[p[i].sd]>=k)continue;
		ans++;
		lrt[p[i].sd]+=p[i].ft;
		chs[p[i].sd]++;
		if(lrt[p[i].sd]>=k)over++;
		if(chs[p[i].sd]>mxc)
		{
			mxc=chs[p[i].sd];
			mxn=prb[p[i].sd];
		}
		else if(mxc==chs[p[i].sd])mxn=min(mxn,prb[p[i].sd]);
	}
	if(over<m||2*mxc-1>n||mxc>n-mxn+1)cout<<-1;
	else cout<<max(ans,2*mxc-1);
	return 0;
}