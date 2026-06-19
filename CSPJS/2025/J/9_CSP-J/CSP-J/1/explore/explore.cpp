#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int T,n,m,k,x,y,d,ans=0;
    char a[1001][1001];
    bool vis[1001][1001]={0};
    int mx[4]={0,1,0,-1};
    int my[4]={1,0,-1,0};
    void Soar()
    {
        //freopen("explore.in","r",stdin);
        //freopen("explore.out","w",stdout);
        //ios::sync_with_stdio(false);
		//cin.tie(0),cout.tie(0);
		cin>>T;
        while(T--)
        {
            ans=0;
			memset(vis,0,sizeof(vis));
			cin>>n>>m>>k;
            cin>>x>>y>>d;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cin>>a[i][j];
            while(k--)
            {
				vis[x][y]=1;
				int newx=x+mx[d],newy=y+my[d];
				if(1<=newx&&newx<=n&&1<=newy&&newy<=m&&a[newx][newy]=='.')
					x=newx,y=newy;
				else d=(d+1)%4;
                vis[x][y]=1;
				//cout<<k<<endl;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(vis[i][j])ans++;
                }
            }
			cout<<ans<<endl;
        }
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}