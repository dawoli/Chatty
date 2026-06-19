#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;

int n, a[N];

int main ()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d", &n);
    for (int i=1; i<=n; i++) { scanf("%d", &a[i]); }
    sort(a+1, a+n+1);
    int cur=1, ans=n;
    for (int i=2; i<=n; i++) {
        if (cur<=n && a[i]>a[cur]) { ans--; cur++; }
    }
    printf("%d\n", ans);

    return 0;
}