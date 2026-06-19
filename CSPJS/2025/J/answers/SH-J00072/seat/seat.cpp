#include <bits/stdc++.h>
using namespace std;
// Aeroperu 603, we are in an emergency
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    vector<int> aeroperu603;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n*m; i++) {
        scanf("%d", &x);
        aeroperu603.push_back(x);
    }
    int pilot = aeroperu603[0], rk = 0;
    sort(aeroperu603.begin(), aeroperu603.end(), greater<int>());
    for (size_t i = 0; i < aeroperu603.size(); i++) {
        if (pilot == aeroperu603[i]) {
            rk = i+1;
            break;
        }
    }
    int col = int(ceil((rk * 1.) / (n * 1.)));
    printf("%d ", col);
    int firstofficer = rk % n, row;
    if (col % 2 == 1) {
        if (firstofficer == 0) {
            row = n;
        }
        else row = firstofficer;
    } else {
        if (firstofficer == 0) {
            row = 1;
        }
        else row = n - firstofficer + 1;
    }
    printf("%d", row);
    return 0;
}