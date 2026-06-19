#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200009;
int n, m, L, V, T;
double t;
int sum = 0,maxn=-1;
int d[MAXN], v[MAXN], a[MAXN], p[MAXN];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        cin >> n >> m >> L >> V;
        for (int j = 1; j <= n; j++)
        {
            cin >> d[j] >> v[j] >> a[j];
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> p[j];
            maxn=max(maxn,p[j]);
        }
        for(int j=1;j<=n;j++)
        {
            if(a[j]==0&&d[j]<=maxn)
            {
                if(v[j]>V)
                {
                    sum++;
                }
                continue;
            }
            t = v[j] * v[j] + 2 * a[j] * (L-d[j]);
            if (t > V*V&&d[j]<=maxn)
            {
                sum++;
            }
        }
        cout << sum << " ";
        sum=0;
        maxn=-1;
        if(a[1]>=0)
        {
            cout<<m-1<<"\n";
            continue;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
