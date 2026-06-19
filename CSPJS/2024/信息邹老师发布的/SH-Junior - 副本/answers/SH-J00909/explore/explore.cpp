#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e3+5;
int t;  //How many queues
int n,m,k;
int x,y,d;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
char dd[MAXN][MAXM];
bool vis[MAXN][MAXN];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(dd,'\0',sizeof(dd));
        memset(vis,false,sizeof(vis));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++)
            scanf("%s",dd[i]+1);
        vis[x][y]=true;
        int ans=1;
        while(k--)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx<1 || ny<1 || nx>n || ny>m || dd[nx][ny]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=nx;y=ny;
            if(!vis[x][y])
            {
                vis[x][y]=true;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
