#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
bool flag;
int n,k,q;
vector<int>mp[100005];
int len[100005];
bool cnt[200005];
void dfs(int x,int tgt,int now,int fa)
{
	if(flag) return;
	if(x==0)
	{
		if(now==tgt)
		{
			flag=true;
		}
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(i==fa) continue;
		for(int j=1; j<=len[i]; j++)
		{
			if(mp[i][j-1]==now)
			{
				for(int tmp=2; tmp<=k&&j+tmp-1<=len[i]; tmp++)
				{
					dfs(x-1,tgt,mp[i][j+tmp-2],i);
				}
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1; i<=n; i++)
		{
			cin>>len[i];
			mp[i].clear();
			for(int j=1; j<=len[i]; j++)
			{
				int x;
				cin>>x;
				mp[i].push_back(x);
				cnt[mp[i][j-1]]=true;
			}
		}
		for(int i=1; i<=q; i++)
		{
			int r,d;
			cin>>r>>d;
			flag=false;
			if(cnt[d]==false) cout<<0<<endl;
			else
			{
				dfs(r,d,1,0);
				if(flag) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
	}
	return 0;
}
