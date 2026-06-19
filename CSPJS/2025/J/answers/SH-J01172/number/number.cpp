#include <bits/stdc++.h>
using namespace std;
char c; int cnt[10];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> c) if ('0' <= c && c <= '9') cnt[c - '0']++;
    for (int i = 9; i >= 0; i--) while (cnt[i]--) cout << i;
    return 0;
}