#include <bits/stdc++.h>
using namespace std;
int ad[100005], c[100005], a[100005];
int d[50][50];
int n, m;
int T;
vector<int> alive;
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &ad[i]);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &c[i]);
    }
    getchar();
    int k = 0, tmp = 1;
    while (tmp < n)
        ++k, tmp *= 2;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= pow(2, k - i); ++j)
        {
            char c;
            c = getchar();
            if (c == '1')
                d[i][j] = 1;
            else
                d[i][j] = 0;
        }
    }
    scanf("%d\n", &T);
    while (T--)
    {
        int x[4];
        for (int i = 0; i < 4; ++i)
        {
            scanf("%d", &x[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            a[i] = ad[i] ^ x[i % 4];
        }
        for (int i = 1; i <= m; ++i)
        {
            int lun = 0, tmplun = 1;
            while (tmplun < c[i])
                ++lun, tmplun *= 2;
            alive.clear();
            for (int j = 1; i <= c[i]; ++j)
                alive.emplace_back(j);
        //     for (int j = 1; j <= lun; ++j)
        //     {
        //         for (int k = 1; k <= pow(2, lun - j); ++k)
        //         {
        //             if (d[j][k])
        //             {
        //                 if (a[alive[2 * k]] >= j)
        //                     alive[2 * k - 1] = 0;
        //                 else
        //                     alive[2 * k] = 0;
        //             }
        //             else
        //             {
        //                 if (a[alive[2 * k - 1]] >= j)
        //                     alive[2 * k] = 0;
        //                 else
        //                     alive[2 * k - 1] = 0;
        //             }
        //         }
        //         for (auto j = alive.begin(); j < alive.end(); ++j)
        //         {
        //             if (*j == 0)
        //                 alive.erase(j);
        //         }
        //     }
        //     printf("%d\n", alive[0]);
        }
    }
    return 0;
}