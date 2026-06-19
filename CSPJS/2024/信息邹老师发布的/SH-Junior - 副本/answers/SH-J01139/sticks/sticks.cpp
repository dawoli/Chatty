#include <bits/stdc++.h>
using namespace std;
const int strokes2mindig[] = {0, 0, 1, 7, 4, 2, 0, 8};
int t, n, last, d, digs[100000], res;
bool found;
int mindig(int strokes) {
    if (d == 0 && strokes == 6)
        return 6;
    else
        return strokes2mindig[strokes];
}
void convert() {
    int newres = 0;
    for (int i = 0; i <= d; i++)
        newres = newres * 10 + digs[i];
    if (res > newres)
        res = newres;
}
void solve() {
    if (n > 7) {
        for (int strokes = 7; strokes > 1; strokes--) {
            digs[d] = mindig(strokes);
            n -= strokes;
            d++;
            solve();
            d--;
            n += strokes;
        }
        return;
    }
    found = (n >= 2);
    if (!(found))
        return;
    digs[d] = mindig(n);
    convert();
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    for (int a = 0; a < t; a++) {
        cin >> n;
        d = 0;
        found = false;
        res = INT_MAX;
        solve();
        if (found)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
