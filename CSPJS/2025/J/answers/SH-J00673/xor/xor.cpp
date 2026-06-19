#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,cnt,maxn=-1,minn=1e8,cnt0,cnt1;
int k2[25],a2[500005][25];
bool vis[500005];
void i2bool(int x,int x2[])
{
    while(x)
    {
        x2[++x2[0]]=x%2;
        x/=2;
    }
    return;
}
int yh(int a[],int b[])
{
    int po=1,c=0;
    for(int i=1;i<=max(a[0],b[0]);i++)
    {
        if(a[i]!=b[i])
        {
            c+=po;
        }
        po*=2;
    }
    return c;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
        if(a[i]==0)cnt0++;
        if(a[i]==1)cnt1++;
        if(a[i]==k)cnt++;
        i2bool(a[i],a2[i]);
    }
    ans=max(ans,cnt);
    cnt=0;
    if(n==2)
    {
        ans=max(ans,1);
        cout<<ans;
        return 0;
    }
    if(maxn==minn&&k==0)
    {
        ans=max(ans,n/2);
        cout<<ans;
        return 0;
    }
    if(maxn==1&&minn==0&&(k==1||k==0))
    {
        if(k==0)
        {
            ans=max(ans,cnt0+(cnt1/2));
        }
        if(k==1)
        {
            ans=max(ans,cnt1);
        }
        cout<<ans;
        return 0;
    }
    cout<<ans;
    return 0;
}
