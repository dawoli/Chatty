#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[5005];
void dfs(int step,int num,int maxn,int sum)
{
    if(step>n)
    {
        if(num<3||sum<2*maxn||sum==2*maxn)
        {
            return;
        }
        cnt++;
        cnt=cnt%998244353;
        return;
    }
    dfs(step+1,num+1,a[step],sum+a[step]);
    dfs(step+1,num,maxn,sum);

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0,0,0);
    cout<<cnt%998244353;
    return 0;
}
