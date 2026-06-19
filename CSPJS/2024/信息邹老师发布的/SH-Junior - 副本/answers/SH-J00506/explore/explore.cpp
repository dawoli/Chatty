#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e3 + 5;
int t,n,m,k,x,y,d;
char a[N][N];
bool ls[N][N];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while (t--)
	{
		memset(ls,0,sizeof(ls));
		int n,m;
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				a[i][j] = ' ';
				while (a[i][j] != '.' && a[i][j] != 'x') a[i][j] = getchar();
			}
		ls[x][y] = 1;
		for (int i = 1; i <= k; i++)
		{
			int lx = x,ly = y,ld = d;
			if (d == 0) ly++;
			else if (d == 1) lx++;
			else if (d == 2) ly--;
			else lx--;
			if (lx < 1 || ly < 1 || lx > n || ly > m || a[lx][ly] == 'x')
			{
				d = (d + 1) % 4;
				continue;
			}
			x = lx; y = ly,d = ld;
			ls[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cnt += ls[i][j];
		cout << cnt << endl; 
	}
	return 0;
}
