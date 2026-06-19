//P8816 [CSP-J 2022] 上升点列
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
namespace Soaring_Wings
{
    vector<pair<int,int>> a;
    vector<vector<int>> dp; 
    int n,k,ans=1;
    double dis(pair<int,int> a,pair<int,int> b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    void Soar()
    {
        ios::sync_with_stdio(false);
        cin.tie(0),cout.tie(0);
        cin>>n>>k;
        a.resize(n+1);
        dp.resize(n+1,vector<int>(k+1,0));
        for(int i=1;i<=n;i++)
        {
            int c,d;
            cin>>c>>d;
            a[i]=pair<int,int>(c,d);
        }
        sort(a.begin()+1,a.end());
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j]=j+1;
                for(int t=1;t<i;t++)
                {
                    pair<int,int>& A=a[i],B=a[t];
                    if(A.y>=B.y)
                    {
                        int d=A.x-B.x+A.y-B.y-1;
                        if(j>=d)
                        {
                            dp[i][j]=max(dp[i][j],dp[t][j-d]+d+1);
                        }
                    }
                }
            }
            ans=max(ans,dp[i][k]);
        }
        cout<<ans;
    }
}
int main()
{
    Soaring_Wings::Soar();
    return 0;
}