#include <bits/stdc++.h>
using namespace std;

int a[2010];
int b[2010];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n,k,q;
        cin >> n >> k >> q;
        int cur = 0;
        for (int i = 1;i <= n;i++)
        {
            int l;
            cin >> l;
            for (int j = 1;j <= l;j++)
            {
                cin >> a[++cur];
                int x = a[cur];
                while (x > 9)
                {
                    x /= 10;
                }
                b[cur] = x;
            }
        }
        for (int i = 1;i <= q;i++)
        {
            int r;
            int c;
            cin >> r >> c;
            int aa = 0;
            for (int i = 1;i <= cur;i++)
            {
                if (b[i] == 1 && a[i] % 10 == c)
                {
                    aa = 1;
                }
            }
            cout << aa << endl;
        }
    }
    return 0;
}
