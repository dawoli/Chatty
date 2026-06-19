#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,a[100001],b[100001],ans=0;
vector<int> na,nb;
int ta=0,tb=0;
struct State
{
	int p,c;
};
bool operator<(const State &_a,const State &_b)
{
	return _a.p<_b.p;
}
State st[100001];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>x;
	na.push_back(0);
	nb.push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>st[i].p>>st[i].c;
	}
	sort(st+1,st+n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		ans+=min(a[i],b[i])*x*2;
		if(a[i]>=b[i])
		{
			na.push_back(a[i]-b[i]);
			ta++;
		}
		else
		{
			nb.push_back(b[i]-a[i]);
			tb++;
		}
	}
	sort(na.begin(),na.end());
	sort(nb.begin(),nb.end());
	int l=1,r=n;
	while(ta>0)
	{
		if(st[l].c<=0)l++;
		ans+=na[ta--]*st[l].p*2;
		st[l].c--;
	}
	while(tb>0)
	{
		if(st[r].c<=0)r--;
		ans+=nb[tb--]*(x-st[r].p)*2;
		st[r].c--;
	}
	cout<<ans;
	return 0;
}