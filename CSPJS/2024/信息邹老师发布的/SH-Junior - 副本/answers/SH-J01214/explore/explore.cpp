#include<bits/stdc++.h>
using namespace std;

long long t,n,m,k,d,x,y;
int ma[6][1001][1001];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int cnt=1;cnt<=t;cnt++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        long long ans=1;
        char temp;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>temp;
                if(temp=='.')
                    ma[cnt][i][j]=1;
            }
        ma[cnt][x][y]=2;
        for(int i=1;i<=k;i++)
        {
            if(ma[cnt][x+dx[d]][y+dy[d]])
            {
                if(ma[cnt][x+dx[d]][y+dy[d]]==1)
                    ans++;
                ma[cnt][x+dx[d]][y+dy[d]]=2;
                x+=dx[d];
                y+=dy[d];
            }
            else
                d=(d+1)%4;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
