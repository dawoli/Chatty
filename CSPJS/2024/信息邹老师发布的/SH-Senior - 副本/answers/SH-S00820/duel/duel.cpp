#include <bits/stdc++.h>
using namespace std;
int arr[100010], ans;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        arr[a]++;
    }
    for (int i = 1; i <= 100000; i++) {
        ans = max(ans, arr[i]);
    }
    cout << ans << endl;
    return 0;
}