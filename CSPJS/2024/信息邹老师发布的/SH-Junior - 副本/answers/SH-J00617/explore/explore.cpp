#include <iostream>
using namespace std;

char c[10005][10005];
int xy[5][5] = {{0,1},
             {1,0},
             {0,-1},
             {-1,0}}; 
bool vis[10005][10005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
            	vis[i][j] = 0;
                cin>>c[i][j];
            }
        }
        int cnt = 0;
        vis[x][y] = 1;
        while(k--)
        {
            int nx = x + xy[d][0],ny = y + xy[d][1];
            if (1<=nx && nx <= n && 1 <= ny && ny <= m && c[nx][ny] == '.')
            {
                x = nx;
                y = ny;
                vis[x][y] = 1;
            }
            else
            {
                d = (d+1)%4;
            }
        }
        for(int i = 1;i<=n;i++)
        {
        	for(int j = 1;j<=m;j++)
        	{
        		cnt += vis[i][j];
			}
		}
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
