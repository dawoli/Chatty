#include <bits/stdc++.h>
using namespace std;

int a[5010],jihe[5010]={},t=0,n,ans=0;
bool cmp(int b,int c)
{
    return b>c;
}

void dfs(int k)
{
    if(t>=3)
    {
        int sigam=0;
        for(int i=0;i<t;i++)
        {
            sigam=sigam+a[jihe[i]];
        }
        if(sigam>a[jihe[0]]*2)
        {
            ans++;
        }
    }
    for(int i=k;i<n;i++)
    {
        jihe[t]=i;
        t++;
        dfs(i+1);
        jihe[t]=-1;
        t--;
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    dfs(0);
    cout<<ans%998%244%353;
    return 0;
}
