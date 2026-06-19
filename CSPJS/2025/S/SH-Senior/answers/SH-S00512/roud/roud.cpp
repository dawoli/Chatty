#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
int dis[10010],vis[10010], s;
struct node
{
	long long x,y;
	long long _x()
	{
		return x;
	}
};
vector<node> V[10010];
int disk();
int main()
{
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		V[a].push_back({b,c});
		V[b].push_back({a,c});
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans,dis[i]);
	cout << ans;
	return 0;
}
int disk()
{
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	for (int i = 1;i <= n;i++)
	{
		int minn = 2e9,id = 0;
		for (int j = 1;j <= n;j++)
		{
			if (!vis[j] && dis[j] < minn)
			{
				minn = dis[j];
				id = j;
			}
		}
		for (int j = 0;j < V[id].size();j++)
		{
			int np=V[id]._x();
			dis[np] = min(dis[np],dis[id] + V[id].y);
		}
	}
}
