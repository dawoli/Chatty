#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y, bo, n;
};
const int N = 1e3 + 5;
char mp[N][N];
pair<int,int>dis[N][N];
bool vis[N][N];
int mv[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.cout","w",stdout);
	int T;
	cin >> T;
	while(T --)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++)
			{
				cin >> mp[i][j];
				dis[i][j].first = 0;
				dis[i][j].second = 0;
				vis[i][j] = false;
			}
		queue<node> q;
		node a;
		a.x = 1,a.y = 1,a.bo = 0,a.n = 0;
		q.push(a);
		vis[1][1] =true;
		while(!q.empty())
		{
			node now = q.front();
//			cout << "!" <<now.x << ' ' << now.y << '\n';
			q.pop();
			for(int i = 0;i < 4;i ++)
			{
				node now2 = {now.x + mv[i][0],
							now.y + mv[i][1],
							now.bo, now.n + 1};
//				cout << "!" <<now2.x << ' ' << now2.y << '\n';
				if(now2.x > n || now2.y > m || now2.x < 1 || now2.y < 1)
					continue;
				if(mp[now2.x][now2.y] == '*')
					continue;
				if(mp[now2.x][now2.y] == '$')
					now2.bo ++;
				if(vis[now2.x][now2.y])
				{
					if(now2.bo < dis[now2.x][now2.y].first){
						dis[now2.x][now2.y].first = now2.bo;
						dis[now2.x][now2.y].second = now2.n;
					}
					if(now2.bo == dis[now2.x][now2.y].first)
					{
						if(now2.n < dis[now2.x][now2.y].second)
							dis[now2.x][now2.y].second = now2.n;
					}
					continue;
				}
				dis[now2.x][now2.y].first = now2.bo;
				dis[now2.x][now2.y].second = now2.n;
				vis[now2.x][now2.y] = true;
				q.push(now2);
			}
		}
		cout << dis[n][m].first << ' ' << dis[n][m].second << '\n';
//		cout << dis[1][5].first << ' ' << dis[1][5].second << '\n';
	}
	return 0;
}
/*
2
1 30
........$..$...$..............
2 5
.*...
.$$$.
*/
