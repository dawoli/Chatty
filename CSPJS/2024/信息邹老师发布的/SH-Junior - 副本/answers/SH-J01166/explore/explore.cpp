#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1010][1010] = {};
int pre[1010][1010] = {};
int n,m,kk,xo,yo,doo;
int t;
void dfs(int x,int y,int k,int d)
{
    if (k == 0)
    {
        return;
    }
    int xx = 0;
    int yy = 0;
    if (d == 0)
    {
        xx = x;
        yy = y+1;
    }
    else if (d == 1)
    {
        xx = x+1;
        yy = y;
    }
    else if (d == 2)
    {
        xx = x;
        yy = y-1;
    }
    else if (d == 3)
    {
        xx = x-1;
        yy = y;
    }
    if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy] == 0)
    {
        pre[xx][yy] = 1;
        dfs(xx,yy,k-1,d);
    }
    else
    {
        d = (d+1)%4;
        pre[x][y] = 1;
        dfs(x,y,k-1,d);
    }
}
signed main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>kk;
        cin>>xo>>yo>>doo;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if (c == '.')
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = 1;
                }
            }
        }
        pre[xo][yo] = 1;
        dfs(xo,yo,kk,doo);
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (pre[i][j] == 1)
                {
                    ans++;
                    pre[i][j] = 0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
