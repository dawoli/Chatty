#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1000010;
ll n, tot, a[N]; char s[N];
void solve()
{
    scanf("%s", s + 1), n = strlen(s + 1);
    for (ll i = 1; i <= n; i++)
        if (s[i] >= '0' && s[i] <= '9') a[++tot] = s[i] - '0';
    sort(a + 1, a + tot + 1);
    for (ll i = tot; i >= 1; i--) printf("%lld", a[i]);
    printf("\n");
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ll T = 1;
    while (T--) solve();
    return 0;
}
