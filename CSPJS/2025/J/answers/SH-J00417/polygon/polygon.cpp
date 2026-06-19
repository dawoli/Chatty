#include<bits/stdc++.h>
using namespace std;
const int N=5000;
const int p=998244353;
int a[N];
int n,ans=0;
vector<int>v;
void dfs(int x)
{
    if (x==n+1)
    {
        if (v.size()>=3)
        {
            int maxv=0,sumv=0;
            for (auto i:v)
            {
                maxv=max(maxv,i);
                sumv+=i;
            }
            if (sumv>maxv*2)
            {
                ans++;
                ans%=p;
            }
        }
    }
    else
    {
        dfs(x+1);
        v.push_back(a[x]);
        dfs(x+1);
        v.pop_back();
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}