#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
bool ans;
int r,need,k;
vector<pair<int,int>> pos[200010];
vector<int> s[100010];
void dfs(int x,int now,int num)
{
	if(num > r)
	{
		if(now == need) ans = true;
		else return;
	}
	if(ans) return;
	for(int i = 0;i < pos[now].size();i++)
	{
		int xx = pos[now][i].first,y = pos[now][i].second;
		for(int j = y + 1;j <= min(y + k - 1,(int)s[xx].size());j++) if(x != xx) dfs(xx,s[xx][j - 1],num + 1);
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		cin >> n >> k >> q;
		for(int i = 1;i <= n;i++)
		{
			int m;
			cin >> m;
			for(int j = 1;j <= m;j++)
			{
				int a;
				cin >> a;
				pos[a].push_back({i,j});
				s[i].push_back(a);
			}
		}
		while(q--)
		{
			cin >> r >> need;
			dfs(0,1,1);
			cout << ans << endl;
			ans = false;
		}
		for(int i = 1;i <= 200000;i++) pos[i].clear();
		for(int i = 1;i <= n;i++) s[i].clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
