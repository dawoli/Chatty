#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 998244353;

int n,ans,pos;
int a[5005];
bool vis[5005];

void dfs(int step,int sum,int maxn,int last,int stop)
{
    if(step == stop+1)
    {
        if(sum > 2*maxn)
        {
            ans = (ans+1)%MOD;
        }
        return;
    }

    for(int i=last;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            dfs(step+1,sum+a[i],max(maxn,a[i]),i,stop);
            vis[i] = false;
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        dfs(1,0,0,1,i);
    }
    cout << ans;
    return 0;
}
