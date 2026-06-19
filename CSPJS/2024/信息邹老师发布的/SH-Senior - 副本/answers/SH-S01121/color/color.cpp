#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, a[N], ans;
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while (T-- > 0) {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
//        if (true) {
        for (long long i = 0; i < (1ll << n); i++) {
            int last1 = -1, last2 = -1, cnt = 0;
            for (int j = 0; j < n; j++) {
//                    cout << bool(i & (1 << j));
                if (i & (1ll << j)) {
                    if (a[j] == last1) {
                        cnt += last1;
                    }
                    last1 = a[j];
                } else {
                    if (a[j] == last2) {
                        cnt += last2;
                    }
                    last2 = a[j];
                }
            }
//                cout << " " << cnt << endl;
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}
