#include<bits/stdc++.h>
using namespace std;
int n, m, tot, score, pos, res1, res2;
vector<int> a;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    tot = n * m;
    for (int i = 1; i <= tot; ++i) {
        int x;
        cin >> x;
        if (i == 1) 
            score = x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < tot; ++i) {
        if (a[i] == score) {
            pos = tot - i;
            break;
        }
    }
    if (1 <= pos % (2 * n) && pos % (2 * n) <= n) {
        res1 = (pos / (2 * n)) * 2 + 1;
        res2 = pos % (2 * n);
    } else {
        res1 = (pos / (2  * n)) * 2 + 2;
        if (pos % (2 * n) == 0) res2 = 1;
        else res2 = 2 * n + 1 - (pos % (2 * n));
    }
    cout << res1 << ' ' << res2 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
