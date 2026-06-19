#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
bool flag[N][N],a[N][N];
int n,m,k;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void solve()
{
	memset(flag,false,sizeof(flag));
	cin >> n >> m >> k;
	int x,y,d;
	cin >> x >> y >> d;
	string s;
	for(int i = 1;i <= n;i++)
	{
		cin >> s;
		for(int j = 1;j <= m;j++)
			a[i][j] = s[j - 1] == '.';
	}
	flag[x][y] = true;
	while(k--)
	{		
		int nx = x + dx[d],ny = y + dy[d];
		if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny])
			x = nx,y = ny;
		else	d = (d + 1) % 4;
		flag[x][y] = true;
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cnt += flag[i][j];
	cout << cnt << endl;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--)	solve();
	return 0;
}

