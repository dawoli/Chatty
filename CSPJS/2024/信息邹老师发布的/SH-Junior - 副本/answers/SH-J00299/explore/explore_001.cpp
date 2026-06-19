#include <bits/stdc++.h>
using namespace std;
char b[1003][1003];
bool vis[1003][1003];
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;cin >> t;
    while(t--) 
    {
        int n,m,k;cin >> n >> m >> k;
        int x,y,d;cin >> x >> y >> d;
        vis[x][y]=true;
        for(int i=1;i<=n;i++)
        {
            string a;
            cin >> a;
            for(int j=0;j<m;j++)
            {
                b[i][j+1]=a[j];
            }
        }
        int ans=1;
        for(int j=1;j<=k;j++)
        {
            if((x+dx[d]>=1)&&(x+dx[d]<=n)&&(y+dy[d]>=1)&&(y+dy[d]<=m)&&(b[x+dx[d]][y+dy[d]]=='.'))
            {
                x+=dx[d];
                y+=dy[d];
                if(!vis[x][y])
                {
					ans++;
					vis[x][y]=true;
				}
            }
            else
            {
                d=(d+1)%4;
				
        	}
   		}
        cout << ans << "\n";
	}
    return 0;
}
