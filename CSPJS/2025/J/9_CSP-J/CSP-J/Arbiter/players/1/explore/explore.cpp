#include<bits/stdc++.h>
#define dx (x+mx[d])
#define dy (y+my[d])
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
        freopen("explore.in","r",stdin);
        freopen("explore.out","w",stdout);
        ios::sync_with_stdio(false);
		cin.tie(0),cout.tie(0);
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
            while(k!=-1)
            {
                //cout<<x<<' '<<y<<endl;
				if(!vis[x][y])
				{
					ans++;
					vis[x][y]=1;
				}
				while(!(1<=dx&&dx<=n&&1<=dy&&dy<=m&&a[dx][dy]=='.'))
				{
					d=(d+1)%4;
					k--;
					if(k==0)goto end;
					//cout<<k<<endl;
				}
				x=dx,y=dy;
				k--;
				//cout<<k<<endl;
            }
			end:
			cout<<ans<<endl;
        }
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}