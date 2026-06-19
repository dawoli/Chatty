#include<iostream>
#include<algorithm>
using namespace std;
int n,a[200001];
long long maxn;
bool b[200001];
long long cal()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i]==b[j])
			{
				if(a[i]==a[j])ans+=a[i];
				break;
			}
		}
	}
	maxn=max(maxn,ans);
}
void dfs(int now)
{
	if(now==n+1)
	{
		cal();
		return;
	}
	b[now]=true;
	dfs(now+1);
	b[now]=false;
	dfs(now+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		maxn=0;
		dfs(1);
		cout<<maxn<<endl;
	}
}
