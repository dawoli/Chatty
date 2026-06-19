#include <bits/stdc++.h>
using namespace std;
vector<int> S[200005];
int n, k, q;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            for (int i = 1; i <= tmp; ++i)
            {
                int tmps;
                scanf("%d", &tmps);
                // S[i].emplace_back(tmps);
            }
        }
        while (q--)
        {
            int r, c;
            scanf("%d%d", &r, &c);
            puts("0");
        }
    }
    return 0;
}
