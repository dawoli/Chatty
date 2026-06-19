#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, l, r, ans, a[100001];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    l = 1, r = 2;
    while (r <= n)
    {
        if (a[r] > a[l])
        {
            --ans;
            ++l;
            ++r;
        }
        else ++r;
    }
    cout << ans;
    return 0;
}
