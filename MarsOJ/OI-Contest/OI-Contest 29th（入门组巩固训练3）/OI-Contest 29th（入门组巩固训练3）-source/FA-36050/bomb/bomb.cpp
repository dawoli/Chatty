#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
int T,min_b,min_dep,n,m,a[1010][1010],d[1010][1010];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
void dfs(int dep,int x,int y,int b)
{
    d[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<1||ty<1||tx>n||ty>m||a[tx][ty]==-1||d[tx][ty]==1)continue;
        else if(tx==n&&ty==m)
        {
            if(b<min_b)
            {
                min_b=b;
                min_dep=dep+1;
            }
            else if(b==min_b&&dep+1<min_dep)min_dep=dep+1;
            return;
        }
        else
        {
            if(a[tx][ty]==0)dfs(dep+1,tx,ty,b);
            else dfs(dep+1,tx,ty,b+1);
        }
    }
}
void solve()
{
    s(n);s(m);
    memset(a,0,sizeof(a));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char s;
            cin>>s;
            if(s=='.')a[i][j]=0;
            if(s=='$')a[i][j]=1;
            if(s=='*')a[i][j]=-1;
        }
    }
    min_b=INT_MAX;min_dep=INT_MAX;
    dfs(0,1,1,0);
    printf("%d %d\n",min_b,min_dep);
}
int main()
{
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    s(T);
    while(T--)
    {
        solve();
    }
    return 0;
}
