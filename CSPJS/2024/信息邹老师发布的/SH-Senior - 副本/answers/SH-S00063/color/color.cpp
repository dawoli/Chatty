#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[101010],rp[101010][101];
ll ans;
bool b[101];
ll cal()
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<i;j++) if(b[j]==b[i]) tmp=j;
		if(tmp!=0)
		{
			if(a[tmp]==a[i]) sum+=a[i];
		}
	}
	return sum;
}
void dfs1(int i)
{
	if(i==n+1)
	{
		ans=max(ans,cal());
		return;
	}
	b[i]=0;
	dfs1(i+1);
	b[i]=1;
	dfs1(i+1);
}
void solve()
{
	memset(rp,0,sizeof(rp));
	ans=0;
	cin>>n;
	int type=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=10) type=0;
	}
	if(type==0) dfs1(1);
	else
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=10;j++)
			{
				rp[i][j]=rp[i-1][j];
				if(a[i-1]==j) rp[i][j]++;
			}
		}
		for(int i=1;i<=n;i++) if(rp[i][a[i]]!=0) ans+=a[i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}

