#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a [maxn];
int main (void)
{
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    int n, i; scanf ("%d", &n);
    for (i=0; i<n; i++) scanf ("%d", a+i);
    sort (a, a+n);
    int j = 1, c = 0;
    for (i=0; i<n; i++)
    {
        while (j < n && a [j] == a [i]) j++;
        if (j == n) break;
        c++; j++;
    }
    printf ("%d\n", n-c);
    return 0;
}
