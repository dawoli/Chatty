#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int T,n,k,q,r,c;
int l[MAXN+5],S[MAXN+5][2000+5];
bool ans[100][MAXN+5];
vector <pair<int,int>> lst[MAXN+5];
void dfs(int pos,int x,int y)
{
	if (pos>=11)
	{
		return;
	}
	for (int i=y+1;i<=min(y+k-1,l[x]);i++)
	{
		ans[pos][i]=1;
		for (int j=0;j<lst[S[x][y]].size();j++)
		{
			if (lst[S[x][y]][j].first!=x)
			{
				dfs(pos+1,lst[S[x][y]][j].first,lst[S[x][y]][j].second);
			}
		}
	}
	
}
int main()
{
	cin.tie(0); 
	cout.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++)
		{
			cin>>l[i];
			for (int j=1;j<=l[i];j++)
			{
				cin>>S[i][j];
				lst[S[i][j]].push_back({i,j});
			}
		}
		for (int i=0;i<lst[1].size();i++)
		{
			dfs(1,lst[1][i].first,lst[1][i].second);
		}
		for (int i=1;i<=q;i++)
		{
			cin>>r>>c;
			cout<<ans[r][c]<<endl;
		}
	}
	return 0;
}
