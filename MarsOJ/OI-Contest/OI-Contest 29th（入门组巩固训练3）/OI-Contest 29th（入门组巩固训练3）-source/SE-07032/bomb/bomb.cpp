#include <bits/stdc++.h>
using namespace std;
int a[1005][1005],vis[1005][1005],ans=INT_MAX,ans2=INT_MAX,n,m;
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
void dfs(int i,int j,int sum,int len)
{
    if(i==n&&j==m)
    {
        if(sum<ans)
        {
            ans = sum;
            ans2 = len;
        }
        else if(sum==ans) ans2 = min(ans2,len);
    }
    else
    {
        for(int k=0;k<4;k++)
        {
            int ti=i+di[k],tj=j+dj[k];
            if(ti<1||ti>n||tj<1||tj>m) continue;
            if(vis[ti][tj]) continue;
            if(a[ti][tj]==-1) continue;
            vis[ti][tj] = 1;
            dfs(ti,tj,sum+a[ti][tj],len+1);
            vis[ti][tj] = 0;
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            if(c=='.') a[i][j] = 0;
            else if(c=='$') a[i][j] = 1;
            else a[i][j] = -1;
        }
    }
    dfs(1,1,a[1][1],0);
    cout<<ans<<" "<<ans2<<'\n';
}
int main()
{
    // freopen("bomb.in","r",stdin);
    // freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}