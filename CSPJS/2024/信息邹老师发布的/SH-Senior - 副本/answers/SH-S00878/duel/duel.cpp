#include <bits/stdc++.h>
using namespace std;
int n;
int g[200000], f[200000];
int k,sum;
int maxn = INT_MIN;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
        f[i] = g[i];
    }
    sort(g + 1,g + n + 1);
    for(int i=1;i<=n;i++)
    {
        if(f[i]==-1)
        {
            continue;
        }
        for(int j=1;j<=n;j++)
        {
            if(f[j]==-1)
            {
                continue;
            }
            else
            {
                if(g[i]>f[j])
                {
                    sum++;
                    f[j]=g[j]=-1;\
                    break;
                }
            }
        }
    }
    cout<<n-sum;
    return 0;
}