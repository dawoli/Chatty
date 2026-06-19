#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) { int x; cin >> x; arr.push_back(x); }
    int ans = 0;
    int l = 0;/*
    while (l < n) {
        int premin = 2147483647;
        for (int i = l; i < min(premin, n); i++) {
            if (arr[i] == k) { premin = i; }
            int pre = arr[i];
            for (int j = i + 1; j < min(premin, n); j++) {
                pre ^= arr[j];
                if (pre == k) {
                    premin = j;
                    break;
                }
            }
        }
        if (premin == 2147483647) break;
        l = premin + 1;
        ans++;
    }*/
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) { ans++; l = i + 1; continue; }
        int pre = arr[i];
        for (int j = i - 1; j >= l; j--) {
            pre ^= arr[j];
            if (pre == k) { l = i + 1; ans++; break; }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
