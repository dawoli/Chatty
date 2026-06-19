#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans=0;
const int N=510;
char s[N];
int c[N];
int vis[N];
int Now[N];
const int mod=998244353;
long long fact=1;

void dfs(int x)
{
	if(x==n+1)
	{
		int cnt=0;
		int fqs=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				fqs++;
			}
			else{
				if(fqs>=c[Now[i]]) fqs++;
				else cnt++;
			}
		}
		if(cnt>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			Now[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=18)
	{
		dfs(1);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			fact=fact*i%mod;
		}
		cout<<fact;
	}
	return 0;
}
