// Problem Url: https://www.luogu.com.cn/problem/T747253?contestId=318072
// Finish Time: 2026/6/20 17:19:13 WA 44pts
// Finish Time: 2026/6/20 16:19:59 WA 20pts
// Finish Time: 2026/6/20 16:06:59 WA
// Start Time: 2026/6/20 15:17:26

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200005
#define MAXM 1000005
int n,m,a[MAXN],xs[MAXM],ys[MAXM],cnt[MAXN];
int yo[MAXN],y2[MAXN];
ll solveA()
{
	for(int i=1; i<n; ++i)
		yo[i]=y2[i]=-1;
	for(int i=1; i<=m; ++i)
	{
		int x=xs[i],y=ys[i];
		if(yo[x]==-1) yo[x]=y;
		else y2[x]=y;
	}
	ll dp0=0,dp1=LLONG_MIN;
	for(int i=1; i<=n-1; ++i)
	{
		int yL1=yo[i],yL2=y2[i];
		ll bl=LLONG_MIN,br=LLONG_MIN,blr=LLONG_MIN;
		if(yL1!=-1)
		{
			int wL1=yL1-a[i],wR1=yL1-a[i+1];
			int wL2=yL2-a[i],wR2=yL2-a[i+1];

			bl=max(wL1,wL2);
			br=max(wR1,wR2);
			blr=max(wL1+wR2,wL2+wR1);
		}
		ll new0=max(dp0,dp1);
		if(bl!=LLONG_MIN) new0=max(new0,dp0+bl);
		ll new1=LLONG_MIN;
		if(br!=LLONG_MIN) new1=max(new1,max(dp0,dp1)+br);
		if(blr!=LLONG_MIN) new1=max(new1,dp0+blr);
		dp0=new0;
		dp1=new1;
	}
	ll sum_a=0;
	for(int i=1; i<=n; ++i) sum_a+=a[i];
	return sum_a+max(dp0,dp1);
}
bitset<MAXN> e;
ll solveB()
{
	for(int i=1; i<=n; ++i) cnt[i]=0;
	for(int i=1; i<=m; ++i)
	{
		if(ys[i]==2) cnt[xs[i]]++;
	}
	ll dp0=0,dp1=LLONG_MIN;
	for(int i=1; i<=n-1; ++i)
	{
		int wl=(a[i]==1)?1:0;
		int wr=(a[i+1]==1)?1:0;
		ll bl=(cnt[i]>=1)?wl:LLONG_MIN;
		ll br=(cnt[i]>=1)?wr:LLONG_MIN;
		ll blr=(cnt[i]>=2)?(wl+wr):LLONG_MIN;
		ll new0=max(dp0,dp1);
		if(bl!=LLONG_MIN) new0=max(new0,dp0+bl);
		ll new1=LLONG_MIN;
		if(br!=LLONG_MIN) new1=max(new1,max(dp0,dp1)+br);
		if(blr!=LLONG_MIN) new1=max(new1,dp0+blr);
		dp0=new0;
		dp1=new1;
	}

	ll sum_a=0;
	for(int i=1; i<=n; ++i) sum_a+=a[i];
	return sum_a+max(dp0,dp1);
}
ll ans;
int curA[MAXN];
void dfs(int k)
{
	if(k>m)
	{
		ll sum=0;
		for(int i=1; i<=n; ++i) sum+=curA[i];
		if(sum>ans) ans=sum;
		return;
	}
	int x=xs[k],y=ys[k];
	dfs(k+1);
	int old=curA[x];
	curA[x]=y;
	dfs(k+1);
	curA[x]=old;
	int old2=curA[x+1];
	curA[x+1]=y;
	dfs(k+1);
	curA[x+1]=old2;
}
ll brute()
{
	for(int i=1; i<=n; ++i) curA[i]=a[i];
	ans=0;
	dfs(1);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) cin>>a[i];
	bool same=true,sm2=true;
	int first_x=-1;
	for(int i=1; i<=m; ++i)
	{
		cin>>xs[i]>>ys[i];
		if(i==1) first_x=xs[i];
		else if(xs[i]!=first_x) same=false;
		if(ys[i]>2) sm2=false;
	}
	for(int i=1; i<=n; ++i)
	{
		if(a[i]>2)
		{
			sm2=false;
			break;
		}
	}
	ll ans;
	if(sm2)
	{
		ans=solveB();
	}
	else
	{
		ans=solveA();
	}
	cout<<ans;
	return 0;
}