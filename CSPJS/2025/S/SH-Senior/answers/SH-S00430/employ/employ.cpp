#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll d[510],c[510],q[510],v[510],ans,n,m;
void dfs(ll x)
{
	if(x>=n+1)
	{
		ll cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			int j=q[i];
			if(d[i]==0||cnt>=c[j])
			{
				cnt++;
			}
			else
			{
				sum++;
			}
		}
		if(sum>=m)
		{
			ans++;
			ans%=p;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			q[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		d[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)dfs(1);
	cout<<ans;
	return 0;
}
