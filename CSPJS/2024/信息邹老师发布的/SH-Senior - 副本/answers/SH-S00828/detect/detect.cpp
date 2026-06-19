#include <bits/stdc++.h>
using namespace std;

        int arr[10000043];
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m, L, V;
        cin >> n >> m >> L >> V; 
        for (int i = n; i >= 1; i--) {
            int d, v, a;
            cin >> d >> v >> a;
            if (a == 0 && v > V) {
                for (int j = d; j <= L; j++) {
                    arr[j]++;
                }
            }
        }
        int ans1 = 0;
        for (int i = 1; i <= m; i++) {
            int cesus;
            cin >> cesus;
            ans1 = max(ans1, arr[cesus]);
        }
        cout << ans1 << " " << m - 1;
    }
    return 0;
}
