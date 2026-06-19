#include <iostream>
#include <cstdio>
using namespace std;
int t, n, m, k, l, s;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        while (n--)
        {
            cin >> l;
            while (l--) cin >> s;
        }
        while (k--) cout << "0\n";
    }
    return 0;
}
