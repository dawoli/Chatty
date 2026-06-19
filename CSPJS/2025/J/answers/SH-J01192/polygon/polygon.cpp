#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long cnt=0;
long long mod=998244353;
void dfs(int step,int sum,int maxn)
{
    if(step>n)
    {
        if(sum>maxn*2)cnt++;
        return;
    }
    dfs(step+1,sum+a[step],max(maxn,a[step]));
    dfs(step,sum,maxn);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0,-1e9);
    cout<<cnt%mod;
    return 0;
}
