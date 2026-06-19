
#include <bits/stdc++.h>
using namespace std;

int n;
int hap[100001][3];
int ans = -1, pres;
int pp[3];
int lim;

void dfs(int d) {
    if (d == n + 1) { ans = max(ans, pres); return; }
    for (int i = 0; i < 3; i++) {
        if (pp[i] + 1 > lim) continue;
        pres += hap[d][i];
        pp[i]++;
        dfs(d + 1);
        pp[i]--;
        pres -= hap[d][i];
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> hap[i][0] >> hap[i][1] >> hap[i][2];
        lim = n / 2;
        dfs(1);
        cout << ans << "\n";
        ans = 0, pres = 0;
        memset(hap, 0, sizeof hap);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
