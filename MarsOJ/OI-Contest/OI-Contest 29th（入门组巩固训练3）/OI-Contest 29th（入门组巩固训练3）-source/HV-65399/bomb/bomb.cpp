#include<bits/stdc++.h>
using namespace std;
int t;
struct node
{
    int x,y,stp,g;
};
int main()
{
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[1005][1005];
        for(int i=1;i<=n;i++)
        {
            char c;
            for(int j=1;j<=m;j++)
            {
                cin >> c;
                if(c=='.')
                {
                    a[i][j]=0;
                }
                else if(c=='$')
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=2;
                }
            }
        }
        queue<node> q;
        int vis[1005][1005];
        memset(vis,0,sizeof(vis));
        vis[1][1]=1;
        q.push({1,1,0});
        int ans=n*m,anstp=n*m;
        while(!q.empty())
        {
            node d=q.front();
            q.pop();
            if(d.x==n&&d.y==m)
            {
                vis[n][m]=0;
                if(ans>d.stp)
                {
                    ans=d.stp;
                    anstp=d.g;
                }
                else if(ans==d.stp)
                {
                    anstp=min(anstp,d.g);
                }
                continue;
            }
            if(d.x+1<=n&&!vis[d.x+1][d.y]&&(a[d.x+1][d.y]==0||a[d.x+1][d.y]==1))
            {
                vis[d.x+1][d.y]++;
                q.push({d.x+1,d.y,d.stp+a[d.x+1][d.y],d.g+1});
            }
            if(d.x-1>0&&!vis[d.x-1][d.y]&&(a[d.x-1][d.y]==0||a[d.x-1][d.y]==1))
            {
                vis[d.x-1][d.y]++;
                q.push({d.x-1,d.y,d.stp+a[d.x-1][d.y],d.g+1});
            }
            if(d.y+1<=m&&!vis[d.x][d.y+1]&&(a[d.x][d.y+1]==0||a[d.x][d.y+1]==1))
            {
                vis[d.x][d.y+1]++;
                q.push({d.x,d.y+1,d.stp+a[d.x][d.y+1],d.g+1});
            }
            if(d.y-1>0&&!vis[d.x][d.y-1]&&(a[d.x][d.y-1]==0||a[d.x][d.y-1]==1))
            {
                vis[d.x][d.y-1]++;
                q.push({d.x,d.y-1,d.stp+a[d.x][d.y-1],d.g+1});
            }
        }
        printf("%d %d\n",ans,anstp);
    }
    return 0;
}
