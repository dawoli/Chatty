#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp [200083] [2], p [200083]; int a [200083], lst [1000055], l [200083];
int main (void)
{
    freopen ("color.in", "r", stdin);
    freopen ("color.out", "w", stdout);
    int t; scanf ("%d", &t);
    while (t--)
    {
        int n, i, j;
        scanf ("%d", &n);
        for (i=0; i<=1000000; i++) lst [i] = 0;
        for (i=1; i<=n; i++)
        {
            scanf ("%d", a+i);
            l [i] = lst [a [i]];
            lst [a [i]] = i;
            p [i] = p [i-1] + (a [i] == a [i-1] ? a [i] : 0);
        }
        ll m = 0;
        for (i=1; i<=n; i++)
        {
            dp [i] [0] = max (dp [i-1] [0], dp [i-1] [1]) + (a [i] == a [i-1] ? a [i] : 0);
            dp [i] [1] = max (dp [i-1] [0], dp [i-1] [1]);
            if (l [i])
            {
                int tmp = l [i];
                dp [i] [1] = max (dp [i] [1], dp [tmp+1] [1] + p [i-1] - p [tmp+1] + a [i]);
            }
        }
        printf ("%lld\n", max (dp [n] [0], dp [n] [1]));
    }
    return 0;
}
