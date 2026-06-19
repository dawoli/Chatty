#include <bits/stdc++.h>
using namespace std;

struct z
{
	int x, y;
};

struct node
{
	int num;
	vector <z> v;
};
node mp[1005][20005];
bool b;
int n, m, q;

void dfs(int x, int y, int t, int end)
{
	if(b)return;
	if(t==0 && mp[x][y].num == end)
	{
		b = true;
		cout << 1 << endl;
		return;
	}
	for(int j = y+1; j <= mp[x][0].num && j-y+1 <= m; j++)
	{
		for(int i = 0; i <= mp[x][j].v.size(); i++)
		{
			if(mp[x][j].v[i].x!=x)
			{
				dfs(mp[x][j].v[i].x, mp[x][j].v[i].y, t-1, end);
			}
		}
	}
}

int main()
{
//	freopen("chain.in", "r", stdin);
//	freopen("chain.out", "w", stdout); 
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> q;
		for(int i = 1; i <= n; i++)
		{
			int l;
			cin >> l;
			mp[i][0].num = l;
			for(int j = 1; j <= l; j++)
			{
				cin >> mp[i][j].num;
				if(j>1) mp[i][j].v.push_back({i, j-1});
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= mp[i][0].num; j++)
			{
				for(int k = i+1; k <= n; k++)
				{
					for(int l = 2; l <= mp[k][0].num; l++)
					{
						if(mp[i][j].num == mp[k][l].num)
						{
							mp[i][j].v.push_back({k, l});
							mp[k][l].v.push_back({i, j});
						}
					}
				}
			}
		}
		cout << q;
		while(q--)
		{
			cout <<q;
			int t, end;
			cin >> t >> end;
			b=false;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= mp[i][0].num; j++)
				{
//					if(b)break;
					if(mp[i][j].num == 1) dfs(i, j, t, end);
				}
//				if(b)break;
			}
			if(!b) cout << 0 << endl;
		}
		
	}
	cout <<q;
	return 0;
}
