#include <iostream>
using namespace std;
int af[100000], a[100000], c[100000], aw[100000];
char d[100000][20];
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, lgn = 1, t;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> af[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    int t = n - 1;
    while ((t >>= 1) != 0)
    {
        lgn++;
    }
    for (int i = 0; i < lgn; i++)
    {
        for (int j = 0; j < 1 << (lgn - i - 1); j++)
        {
            cin >> d[j][i];
        }
    }
    cin >> t;
    while (t--)
    {
        int x1, x2, x3, x4;
        cin >> x2 >> x3 >> x4 >> x1;
        for (int i = 0; i < n; i += 4)
        {
            a[i] = af[i] ^ x1;
            a[i + 1] = af[i + 1] ^ x2;
            a[i + 2] = af[i + 2] ^ x3;
            a[i + 3] = af[i + 3] ^ x4;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < c[i]; j++)
            {
                aw[j] = j;
            }
            int lgc = 1;
            int t = c[i] - 1;
            while ((t >>= 1) != 0)
            {
                lgc++;
            }
            for (int i = 0; i < lgc; i++)
            {
                for (int j = 0; j < 1 << (lgc - i - 1); j++)
                {
                    if (d[j][i]=='0')
                    {
                        aw[j]=a[aw[j*2]]<=j+1;
                    }
                    
                }
            }
        }
    }
    return 0;
}