#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int n,m;
char g[1005][1005];
bool f[1005][1005];

bool chk(int x,int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main()
{
    freopen("explore5.in","r",stdin);
    freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
	    memset(f,false,sizeof f);
		int k,x,y,d,cnt = 0;
		cin >> n >> m >> k >> x >> y >> d;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= m;j++) cin >> g[i][j];
		}
		while(k--)
        {
            f[x][y] = true;
            int nx = x + dx[d],ny = y + dy[d];
            if(chk(nx,ny) && g[nx][ny] == '.')
                x = nx,y = ny;
            else d = (d + 1) % 4;
        }
        f[x][y] = true;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                if(f[i][j]) cnt++;
            }
        }
        cout << cnt << endl;
	}
	return 0;
}
