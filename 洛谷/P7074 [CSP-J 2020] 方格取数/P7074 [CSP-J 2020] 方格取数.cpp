#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, w[1005][1005], f[1005][1005][3]; //0从上面，1从下面，2从左边
int MIN;
int dfs(int x,int y,int d)
{
    if (x<1||x>n||y<1||y>m)return MIN;
    if (f[x][y][d]!=MIN)return f[x][y][d];
    if (d==0)
    {
        f[x][y][d]=max(dfs(x-1,y,0),dfs(x-1,y,2))+w[x][y];
        return f[x][y][d];
    }
    if (d==1)
    {
        f[x][y][d]=max(dfs(x+1,y,1),dfs(x+1,y,2))+w[x][y];
        return f[x][y][d];
    }
    if (d==2)
    {
        f[x][y][d]=max(max(dfs(x,y-1,0),dfs(x,y-1,1)),dfs(x,y-1,2))+w[x][y];
        return f[x][y][d];
    }
}
signed main()
{
    cin >> n >> m;
    memset(f, 128, sizeof(f));
    MIN=f[0][0][0];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
        }
    }
    f[1][1][0]=f[1][1][1]=f[1][1][2]=w[1][1];
    cout<<max(dfs(n,m,0),dfs(n,m,2));
    return 0;
}