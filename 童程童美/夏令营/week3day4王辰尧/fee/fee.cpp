#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int value[1000][1000]; 
int N;
int main()
{
    freopen("fee.in","r",stdin);
    freopen("fee.out","w",stdout);
    memset(dp, 9999, sizeof(dp));
    int i,j;
    cin>>N;
    for(i = 1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            cin>>value[i][j];
        }
    }
    dp[1][1] = value[1][1];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i==1&&j==1)
                dp[i][j] = value[i][j];
            else
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + value[i][j];
        }
    }
    cout<<dp[N][N];
    return 0;
}

