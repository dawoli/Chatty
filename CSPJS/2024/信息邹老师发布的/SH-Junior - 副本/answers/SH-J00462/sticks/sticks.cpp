#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int t[10] = {0 ,0, 1, 7, 4, 2, 6, 8, 0, 0};
int T, n;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    while (T--) {
        int sum = 0;
        n = 0;
        scanf("%d", &n);
        if (n <= 7) {
            if (t[n] != 0) {
                scanf("%d", t[n]);
            } else {
                cout << -1 << endl;
            }
        } else if (n > 7 && n <= 14) {
            for (int i = 1; i <= 9; i++) {
                if (t[n - s[i]] != 0) {
                    if (n - i == 6) {
                        sum = 10 * i + 0;
                    } else{
                        sum = 10 * i + t[n - i];
                    }
                }
            }
        } else if (n > 14 && n < 21) {
            for (int i = 1; i <= 9; i++) {
                for (int j = 1; j <= 9; i++) {
                    if (t[n - s[i] - s[j]]= 0) {
                        if (n - i - j == 6) {
                            sum = 100 * i + 10 * j + 0;
                        } else{
                            sum = 100 * i + 10 * j + t[n - i];
                        }
                    }
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}

