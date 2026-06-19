#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e5+5;
long long n,k,a[MAXN],ans;
bool check(long long x,long long y)
{
    long long cnt=0;
    for(long long i=x;i<=y;i++)
        cnt^=a[i];
    return cnt==k;
}
void dfs(long long pos,long long num)
{
    if(pos>=n)
    {
        ans=max(ans,num);
        return ;
    }
    for(long long i=pos;i<=n;i++)
    {
        if(check(pos,i))
            dfs(i+1,num+1);
        else if(i!=pos)
            dfs(i,num);
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);
    cout<<ans;
    return 0;
}
