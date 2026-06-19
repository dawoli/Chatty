#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,n,m,k,x,y,d,be[1005][1005]={},x1,y1,cnt[10]={},cn;
    char mp[1005][1005];
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
            }
        }
        be[x][y]=1;
        for(int i=1;i<=k;i++)
        {
            if(d==0)
            {
                x1=x;
                y1=y+1;
            }
            if(d==1)
            {
                x1=x+1;
                y1=y;
            }
            if(d==2)
            {
                x1=x;
                y1=y-1;
            }
            if(d==3)
            {
                x1=x-1;
                y1=y;
            }
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&mp[x1][y1]=='.')
            {
                x=x1;
                y=y1;
                if(be[x][y]!=1)
                {
                    be[x][y]=1;
                }
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cn=0;
        for(int j=1;j<=n;j++)
        {
            for(int h=1;h<=m;h++)
            {
                if(be[j][h]==1)
                {
                    cn++;
                }
            }
        }
        cnt[t]=cn;
    }
    for(int i=1;i<=T;i++)
    {
        cout<<cnt[i]<<endl;
    }
    return 0;
}
