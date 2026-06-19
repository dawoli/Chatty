#include<bits/stdc++.h>
using namespace std;
int q;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            ans += max(a, max(b, c));
        }
        cout << ans << endl;
    }
    return 0;
}