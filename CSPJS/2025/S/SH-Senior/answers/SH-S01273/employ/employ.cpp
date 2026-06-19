#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,t[100010],p[100010],a[100010],cnt[100010],mod=998244353;
bool ok()
{
	long long lst=0;
	for(int i=1;i<=n;i++)
	{
		if(t[p[i]]<=lst||a[i]==0) lst++;
	}
	int k=n-lst;
	if(k>=m) return 1;
	else return 0;
}
void dfs(int step)
{
	if(step==n+1)
	{
		if(ok())
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!p[i])
		{
			p[i]=step;
			dfs(step+1);
			p[i]=0;
		}
	}
}
void solve()
{
	int flag=0,sum=1;
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		if(t[i]==0||a[i]==0)
		{
			flag=1;
			cout<<0;
			break;
		}
	}
	if(flag==1) return ;
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==0) continue;
		for(int j=2;j<=cnt[i];j++)
		{
			sum*=j;
			sum%=mod;
		}
	}
	cout<<sum<<endl;
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1;i<=n;i++) cin>>t[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	{
		solve();
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
