#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,lim,ans=INT_MAX;
vector<int> u(2,1);
void dfs(int x,int dep)
{
	if(dep>lim) return;
	if(x==n)
	{
		ans=min(ans,dep);
		return;
	}
	for(int i=u.size()-1;i>=1;i++)
	{
		int t=x+u[i];
		if(t>n)t-=2*u[i];
		if(t>0)
		{
			u.push_back(t);
			dfs(t,dep+1);
			u.pop_back();
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(1)
	{
		cin>>n;
		if(n==0) break;
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		ans=INT_MAX;
		for(lim=10;lim<=20;lim++)
		{
			u.resize(2,1);
			dfs(1,0);
			if(ans!=INT_MAX)
			{
				cout<<ans<<'\n';
				break;
			}
		}
	}
	return 0;
}