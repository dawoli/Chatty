#include<cstdio>
#include<iostream>
using namespace std;

int n;
long long ans=0;
const int p=998244353;
int a[5010];

void dfs(int step,int sum,int mx,int cnt)
{
    if(step>n)
    {
        if(cnt>=3 && sum>2*mx)
        {
            ans++;
            ans%=p;
        }
        return;
    }
    dfs(step+1,sum+a[step],max(mx,a[step]),cnt+1);
    dfs(step+1,sum,mx,cnt);
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
    dfs(1,0,0,0);
    cout << ans%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
