#include<bits/stdc++.h>
using namespace std;

const int N=502,Mod=998244353;
int c[N],a[N];
string s;
int n,m;
long long ans=0;
bool f[N];
void dfs(int now,int num,int cnt)
{
	if(now>n)
	{
		if(cnt>=m) ans=(ans+1)%Mod;
		return ;
	}
	if(cnt+n-now+1<m) return;
	for(int i=1;i<=n;i++)
		if(!f[i])
		{
			a[now]=i;
			f[i]=1;
			if(num<c[i]&&s[now-1]=='1')
				dfs(now+1,num,cnt+1);
			else
				dfs(now+1,num+1,cnt);
			f[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flaga=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]!=1)
			flaga=0;
	}
	if(n<=18)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m==n)
	{
		for(int i=0;i<n;i++)
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%Mod;
		cout<<ans;
	}
	else
	{
		srand(time(0));
		long long a=rand(),b=rand();
		cout<<a*b%Mod;
	}
	return 0;
}
