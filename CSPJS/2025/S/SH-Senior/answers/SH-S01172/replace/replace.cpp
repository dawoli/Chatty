#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    string s1[200005], s2[200005], x, y;
    for (int i = 1; i <= n; ++i) {
        cin >> s1[i] >> s2[i];
    }
    while (q--) {
        cin >> x >> y;

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int r = x.find(s1[i]);
            if (r != -1) {
                string temp = x;
                for (int j = r; j <= r + s1[i].size() - 1; ++j) {
                	temp[j] = s2[i][j-r];
				}
				if (temp == y) cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
