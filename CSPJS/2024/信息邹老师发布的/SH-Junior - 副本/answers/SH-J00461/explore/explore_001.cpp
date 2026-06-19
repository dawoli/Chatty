#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
const int N = 1e3 + 1;
struct Node
{
	int x,y;
	bool operator < (Node oth) const
	{
		if(oth.x != x) return x < oth.x;
		return y < oth.y;
	}
};
map <Node,bool> mp;
int n,m,k,x,y,d;
char a[N][N];
void solve()
{
	scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
	for(int i = 1; i <= n; i++)
	{
		scanf("\n");
		for(int j = 1; j <= m; j++)
			scanf("%c",&a[i][j]);
	}
	mp.clear();
	mp[{x,y}];
	while(k--)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(nx < 1 || ny < 1 || nx > n || ny > m || a[nx][ny] == 'x')
		{
			d = (d + 1) % 4;
			continue;
		}
		else
		{
			x = nx,y = ny;
			mp[{nx,ny}];
		}
	}
	printf("%d\n",mp.size());
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
