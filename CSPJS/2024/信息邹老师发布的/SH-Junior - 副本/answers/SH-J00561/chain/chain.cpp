#include <bits/stdc++.h>
using namespace std;
int t,n,k,m,idx,cnt;
vector<int> words[100010];
pair<int,int> tasks[100010];
map<pair<int,int>,int> mp;
map<pair<int,int>,bool> st2;
struct node
{
	int n,p,r;
};
map<pair<int,pair<int,int>>,bool> st;
int ans[100010];
void bfs()
{
	queue<node> q;
	q.push({1,-1,0});
	while(q.size())
	{
		if(cnt < 1)
		{
			return;
		}
		node t = q.front();
		q.pop();
		while(t.r > tasks[idx].first && idx <= m)
		{
			if(!st2[tasks[idx]])
			{
				cnt--;
				st2[tasks[idx]] = 1;
			}
			idx++;
		}
		int s = idx;
		bool flag = 0;
		while(t.r == tasks[idx].first && idx <= m)
		{
			if(t.n == tasks[idx].second)
			{
				ans[mp[tasks[idx]]] = 1;
				if(!st2[tasks[idx]])
				{
					cnt--;
					st2[tasks[idx]] = 1;
				}
			}
			else
			{
				flag = 1;
			}
			idx++;
			if(!flag)
			{
				s++;
			}
		}
		idx = s;
		for(int i = 0;i < n;i++)
		{
			if(i == t.p)
			{
				continue;
			}
			for(int j = 0;j < words[i].size();j++)
			{
				if(words[i][j] == t.n)
				{
					for(int l = j + 1;l < j + k;l++)
					{
						if(!st[{words[i][j + l],{i,t.r + 1}}])
						{
							q.push({words[i][j + l],i,t.r + 1});
							st[{words[i][j + l],{i,t.r + 1}}] = 1;
						}
					}
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	for(int l = 0;l < t;l++)
	{
		cin >> n >> k >> m;
		cnt = m;
		for(int i = 0;i < n;i++)
		{
			int l;
			cin >> l;
			for(int j = 0;j < l;j++)
			{
				int x;
				cin >> x;
				words[i].push_back(x);
			}
		}
		for(int i = 0;i < m;i++)
		{
			int r,c;
			cin >> r >> c;
			tasks[i] = {r,c};
			mp[{r,c}] = i;
		}
		sort(tasks,tasks + m);
		bfs();
		for(int i = 0;i < m;i++)
		{
			cout << ans[i] << endl;
		}
	}
	return 0;
}
