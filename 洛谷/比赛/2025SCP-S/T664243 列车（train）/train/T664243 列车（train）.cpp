#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
    int T,n,m;
    void Soar()
    {
        vector<int> p(n+1,0);
        vector<vector<uint8_t>> train(n+1,vector<uint8_t>(0,0));
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n+1;j++)
            {
                train[i].push_back(1);
            }
        }
        while(m--)
        {
            int op,x,y;
            cin>>op>>x>>y;
            if(op==1)
            {
                for(int i=x;i<y;i++)
                {
                    for(int j=i+1;j<=y;j++)
                    {
                        train[i][j]=0;
                    }
                }
            }
            if(op==2)
            {
                if(train[x][y]==1)
                {
                    cout<<p[y]-p[x]<<endl;
                    continue;
                }
                int ans=INT_MAX;
                for(int i=x;i>=1;i--)
                {
                    for(int j=y;j<=n;j++)
                    {
                        if(train[i][j]==1)ans=min(ans,p[j]-p[i]);
                    }
                }
                if(ans!=INT_MAX)cout<<ans<<endl;
                else cout<<"-1"<<endl;
            }
        }
    }
    void solve()
    {
        cin>>T;
        while(T--)
        {
            cin>>n>>m;
            Soar();
        }
    }
}
int main()
{
    Soaring_Wings::solve();
    return 0;
}