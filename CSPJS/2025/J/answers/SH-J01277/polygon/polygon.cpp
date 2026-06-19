#include <iostream>
#include <cstdio>
using namespace std;
int n,a[5005];
long long ans;
void dfs(int sum,int maxn,int st,int step)
{
    if(step == n+1)
    {
        if(sum > maxn*2 && st >= 3)
        {
            ans++;
            ans %= 998244353;
            return;
        }

    }
    dfs(sum,maxn,st,step+1);
    dfs(sum+a[step],max(maxn,a[step]),st+1,step+1);
    return ;
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
    dfs(0,0,0,1);
    cout << ans;
    return 0;
}
