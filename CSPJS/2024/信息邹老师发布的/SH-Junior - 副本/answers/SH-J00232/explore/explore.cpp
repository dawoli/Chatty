#include<bits/stdc++.h>
using namespace std;
int T,res=0;
char a[1005][1005];
bool vis[1005][1005];
int m,n,k,x,y,d;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int t=0;t<T;t++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        vis[x][y]=1;
        while(k>0)
        {
            if(d==0)
            {
                while(y+1<=m&&a[x][y+1]!='x'&&k>0)
                {
                    y++;
                    k--;
                    vis[x][y]=1;
                }
                d=d+1;
                k--;
            }
            if(d==1)
            {
                while(x+1<=n&&a[x+1][y]!='x'&&k>0)
                {
                    x++;
                    k--;
                    vis[x][y]=1;
                }
                d=d+1;
                k--;
            }
            if(d==2)
            {
                while(y-1>0&&a[x][y-1]!='x'&&k>0)
                {
                    y--;
                    k--;
                    vis[x][y]=1;
                }
                d=d+1;
                k--;
            }
            if(d==3)
            {
                while(x-1>0&&a[x-1][y]!='x'&&k>0)
                {
                    x--;
                    k--;
                    vis[x][y]=1;
                }
                d=0;
                k--;
            }
        }
        long long res=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j])
                {
                    res++;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
