#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q,x;
int r,c;
int l[100005];
vector<int>s[100005];
bool b[200005],ans;
void dfs(int deep,int z,int p)
{
	if(deep==r)
	{
		if(z==c)ans=true;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p)continue;
		for(int j=0;j<l[i]-1;j++)
		{
			if(s[i][j]==z)
			{
				for(int m=1;j+m<l[i]&&m<k;m++)
				{
					dfs(deep+1,s[i][j+m],i);
					if(ans==true)return;
				}
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			s[i].clear();
			for(int j=1;j<=l[i];j++)
			{
				cin>>x;
				s[i].push_back(x);
				b[x]=true;
			}
		}
		while(q--)
		{
			cin>>r>>c;
			if(!b[c]||n>100000)
			{
				cout<<0<<endl;
				continue;
			}
			ans=false;
			dfs(0,1,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
