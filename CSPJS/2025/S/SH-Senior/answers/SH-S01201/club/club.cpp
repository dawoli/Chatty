#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll INF = 0x3F3F'3F3F'3F3F'3F3F;
ll T, n, a[N][5], choice[N], cnt[5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef LOCAL
    ignore = freopen("club.in", "r", stdin);
    ignore = freopen("club.out", "w", stdout);
    // #else
    // ignore = freopen("club.err", "w", stderr);
    // #endif
    cin >> T;
    while (T-- > 0)
    {
        cnt[0] = cnt[1] = cnt[2] = 0;
        ll ans = 0;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            choice[i] = max_element(a[i], a[i] + 3) - a[i];
            cnt[choice[i]]++;
            ans += a[i][choice[i]];
        }
        // cerr << ans << " " << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
        for (ll i = 0; i < 3; i++)
        {
            if (cnt[i] <= n / 2)
                continue;
            priority_queue<ll> pq;
            for (ll j = 0; j < n; j++)
            {
                if (i != choice[j])
                    continue;
                ll tmp = -INF;
                for (ll k = 0; k < 3; k++)
                    if (i != k)
                        tmp = max(tmp, a[j][k] - a[j][i]);
                // cerr << "Index " << j << " can change: " << tmp << endl;
                pq.push(tmp);
            }
            for (ll j = 0; j < cnt[i] - n / 2; j++)
            {
                // cerr << "Chosen " << pq.top() << endl;
                ans += pq.top(), pq.pop();
            }
        }
        cout << ans << endl;
        // cerr << endl;
    }
    return 0;
}