#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int N=200005;
int _,n,a[N],p1[N],p2[N],ans;
void solveBF()
{
	int cnt1=0,cnt2=0;
	for(int s=0;s<(1<<n);s++)
	{
		cnt1=0;
		cnt2=0;
		int res=0;
		for(int j=0;j<n;j++)
		{
			if(s&(1<<j)) p1[++cnt1]=j+1;
			else p2[++cnt2]=j+1;
		}
		for(int j=2;j<=cnt1;j++)
		{
			if(a[p1[j]]==a[p1[j-1]]) res+=a[p1[j]];
		}
		for(int j=2;j<=cnt2;j++)
		{
			if(a[p2[j]]==a[p2[j-1]]) res+=a[p2[j]];
		}
		ans=max(ans,res);
	}
	cout<<ans<<endl;
	return;
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=15)
	{
		solveBF();
		return;
	}
	return;
}
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while(_--) solve();
	return 0;
}
