#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int N=2e5+10;
int a[N];
int color[N];
int n;
long long ans=0;

void dfs(int u)
{
	if(u==n+1)
	{
		long long res=0;
		int last1=-1,last2=-1;
		for(int i=1;i<=n;i++)
		{
			if(color[i])
			{
				if(last2!=-1 && a[last2]==a[i])
					res+=a[i];
				last2=i;
			}
			else
			{
				if(last1!=-1 && a[last1]==a[i])
					res+=a[i];
				last1=i;
			}
		}
		ans=max(ans,res);
		return ;
	}
	color[u]=0;
	dfs(u+1);
	color[u]=1;
	dfs(u+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
    return 0;
}
