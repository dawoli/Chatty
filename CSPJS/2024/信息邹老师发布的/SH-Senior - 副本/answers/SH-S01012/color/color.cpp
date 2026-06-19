#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+9;

ll n,ans;
ll a[N];
ll color[N];

ll calc()
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		int pos=-1;
		for(int j=1;j<i;j++)
		{
			if(color[j]==color[i]&&j>pos)
			{
				pos=j;
			}
		}
		if(pos==-1) sum+=0;
		else
		{
			if(a[pos]==a[i]) sum+=a[pos];
			else sum+=0;
		}
	}
	return sum;
}

void dfs(int x)
{
	if(x==n+1)
	{
		ans=max(ans,calc());
		//for(int i=1;i<=n;i++) cout<<color[i]<<" ";
		//cout<<endl;
		return ;
	}
	color[x]=0;
	dfs(x+1);
	color[x]=1;
	dfs(x+1);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
	{
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=100)
		{
			dfs(1);
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
