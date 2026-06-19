#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, r[N];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    sort(&r[0], &r[n]);
    int x = 0, y = upper_bound(&r[0], &r[n], r[0]) - r;
    while (y < n) {
//        cout << x << " " << y << endl;
        if (r[x] < r[y]) {
            x++;
        }
        y++;
    }
//    cout << x << " " << y << endl;
    cout << n - x << endl;
    return 0;
}

// 1 1 2 2 3
// 1 1 2 2 2 3
// 136 136 136 136 136 136 136 136 2417 2417
