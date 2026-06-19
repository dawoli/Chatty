#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

using LL = long long;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    LL n, m;
    cin >> n >> m;
    vector<LL> a;
    a.push_back(-1);
    for (LL i = 1; i <= n * m; i++) {
        LL x;
        cin >> x;
        a.push_back(x);
    }
    LL score = a[1];
    sort(a.begin(), a.end(), greater<LL>());
    LL rank = 0;
    for (LL i = 1; i <= n * m; i++) {
        if (a[i] == score) {
            rank = i;
        }
    }
    //printf("rank = %d\n", rank);
    LL cnt = 0;
    for (LL j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (LL i = 1; i <= n; i++, cnt++) {
                if (rank == cnt) {
                    cout << j << ' ' << i << endl;
                    return 0;
                }
            }
        } else {
            for (LL i = n; i >= 1; i--, cnt++) {
                if (rank == cnt) {
                    cout << j << ' ' << i << endl;
                    return 0;
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
