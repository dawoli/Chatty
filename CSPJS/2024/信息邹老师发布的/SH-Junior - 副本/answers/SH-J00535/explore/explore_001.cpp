#include<bits/stdc++.h>
using namespace std;

char q[1001][1001];
int vis[1001][1001];
int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    string w;
    int T, n, m, k, x, y, d;
    cin >> T;
    while(T--)
    {
        int cnt=1;
        cin >> n >> m >> k >> y >> x >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >>w;
            for(int j = 1; j <= m; j++){q[i][j]=w[j-1];vis[i][j]=0;}
        }
        vis[y][x]=1;
        for(int i = 1; i <= k; i++)
        {
            if(x+direction[d][1]>=1&&y+direction[d][0]>=1&&x+direction[d][1]<=m&&y+direction[d][0]<=n&&q[y+direction[d][0]][x+direction[d][1]]=='.')
            {
                x+=direction[d][1];
                y+=direction[d][0];
                if(!vis[y][x]){vis[y][x]=1;cnt++;}
            } else {
                d++;
                d%=4;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
