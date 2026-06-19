#include<iostream>
#include <bits/stdc++.h>
#define N 100

using namespace std;

int n[N];
int T;
int number[N]={6,2,5,5,4,5,6,3,7,6};
int dp[N];

int ans;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout;)

    cin>>T;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=0;
    dp[7]=8;

    for(int i=1;i<=T;i++)
    {
        cin>>n[i];
    }

    for(int j=1;j<=T;j++)
    {
        int plac=0;
        int k=n[j];
        int v=2;
        while(v!=k)
        {
            if(plac=0)
            {
                dp[j]=min(dp[j]+ans,dp[j-1]+ans);
            }
            else
            {
                dp[j]=min(dp[j]*pow(10,plac)+ans,dp[j-1]*plac+ans);
            }
            j++;
            plac++;
        }
        cout<<dp[n[j]];
    }

    return 0;
}
