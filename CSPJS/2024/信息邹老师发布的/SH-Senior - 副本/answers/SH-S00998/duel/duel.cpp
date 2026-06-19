#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;

int n, r[N];
priority_queue<int, vector<int>, greater<int>> q;

signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> r[i];
        q.push(r[i]);
    }

    int ans = n;
    sort(r + 1, r + n + 1);
    for(int i = 1; i <= n; ++i) {
        int a = q.top(); q.pop();
        if(a < r[i]) ans--;
        else q.push(a);
    }

    cout << ans << endl;
    return 0;
}