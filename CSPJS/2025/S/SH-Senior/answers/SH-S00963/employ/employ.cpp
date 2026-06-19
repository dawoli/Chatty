#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],cnt,ans,ab;
string s;
bool vis[505];
void dfs(int x)
{
	if(x==n+1)
	{
		if(n-ab>=m)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	if(s[x-1]==48)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			vis[i]=1;
			ab++;
			dfs(x+1);
			ab--;
			vis[i]=0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			vis[i]=1;
			if(ab>=c[i])
			{
				ab++;
				dfs(x+1);
				ab--;
			}
			else
			{
				dfs(x+1);
			}
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(!c[i])cnt++;
	}
	if(n<=10)
	{
		dfs(1);
		printf("%d\n",ans); 
		return 0;
	}
	bool flag=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='1')
		{
			flag=0;
			break;
		}
	}
	if(flag||m==1)
	{
		if(n-cnt<m)printf("0\n");
		else
		{
			int ans=1;
			unsigned long long res=(unsigned long long)(ans);
			int bound=n-m+1;
			for(int i=n;i>=bound;i--)
			{
				res=res*i;
				if(res%m==0&&m)
				{
					res/=m;
					m--;
				}
			}
			for(int i=m;i>=2;i--)res=res/i;
			printf("%d",(int)(res));
		}
		return 0;
	}
	printf("0\n");
	return 0;
}
