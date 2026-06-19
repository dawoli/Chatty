#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> m >> n;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    int tgt;
    vector<int> s;
    for (int i = 0; i < n * m; i++) { int x; cin >> x; s.push_back(x); }
    tgt = s[0];
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    int pre = find(s.begin(), s.end(), tgt) - s.begin() + 1;
    int ansx = 1, ansy = 1;
    while (pre - n > 0) { pre -= n; ansx++; }
    if (ansx % 2 == 1) ansy = pre;
    else ansy = n - pre + 1;
    cout << ansx << " " << ansy << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
