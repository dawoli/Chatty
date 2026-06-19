#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long LL;
const LL N = 1e5 + 10;
LL a[N], atk[N], alive[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    LL n0;
    cin >> n0;
    set<LL> s;
    for (LL i = 0; i < n0; i++) {
        cin >> a[i];
        atk[a[i]]++;
        alive[a[i]]++;
        s.insert(a[i]);
    }
    sort(a, a + n0);
    LL ans = 0;
    for (LL _ = 0; _ < 100; _++) {
        // every round will kill about half, log(2, n), 100 is totally enough
        LL n = 0;
        for (LL x : s) {
            a[n++] = x;
        }
        //for (LL i = 0; i < n; i++) {
        //    cout << a[i] << ' ';
        //}
        //cout << endl;
        for (LL i = 1; i < n; i++) {
            // x attack y, x = attack, y = defense
            LL x = a[i];
            LL y = a[i - 1];
            if (atk[x] < alive[y]) {
                alive[y] -= atk[x]; ans += atk[x];
                atk[x] = 0;
            } else {
                atk[x] -= alive[y]; ans += alive[y];
                alive[y] = 0; s.erase(y);
            }
        }
    }
    cout << n0 - ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
