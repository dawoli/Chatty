#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, topa, topb, res;
int A[MAXN], C[MAXN], stka[MAXN], stkb[MAXN];

void calc() {
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t += C[i];
    }
    res = max(res, t);
}

void search(int index, bool isred);

void searchred(int index) {
    if (index > n) {
        calc();
        return;
    }
    stka[topa] = index;
    topa++;
    if (topa > 1) {
        if (A[stka[topa - 2]] == A[index]) {
            C[index] = A[index];
        } else {
            C[index] = 0;
        }
    } else {
        C[index] = 0;
    }
    search(index + 1, true);
    search(index + 1, false);
    topa--;
}

void searchblue(int index) {
    if (index > n) {
        calc();
        return;
    }
    stkb[topb] = index;
    topb++;
    if (topb > 1) {
        if (A[stkb[topb - 2]] == A[index]) {
            C[index] = A[index];
        } else {
            C[index] = 0;
        }
    } else {
        C[index] = 0;
    }
    search(index + 1, true);
    search(index + 1, false);
    topb--;
}

void search(int index, bool isred) {
    if (isred) searchred(index);
    else searchblue(index);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    topa = 0; topb = 0; res = 0;
    search(1, true);
    search(1, false);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
}