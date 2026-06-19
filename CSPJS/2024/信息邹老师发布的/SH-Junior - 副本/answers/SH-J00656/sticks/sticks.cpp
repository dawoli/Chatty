#include <bits/stdc++.h>
using namespace std;
int t, n;
int trans[19] = {0, 1, 2, 4, 6, 7, 8};
int p[19] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string f[100009][2];
void eq(string& x, const string& y, const char& add) {
    if(x[0] == '-' || x.size() > y.size() + 1 || (add == '0' && x.size() == y.size() + 1))
        x = add + y;
    return;
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    f[0][0] = "";
    f[0][1] = "";
    f[1][0] = "-1";
    f[1][1] = "-1";
    for(int i = 2; i <= 100000; i++) {
        f[i][0] = "-1";
        for(int j = 1; j <= 6; j++) {
            if(i >= p[trans[j]] && f[i - p[trans[j]]][1][0] != '-')
                eq(f[i][0], f[i - p[trans[j]]][1], trans[j] + '0');
        }
        f[i][1] = f[i][0];
        if(i >= p[0] && f[i - p[0]][1][0] != '-')
            eq(f[i][1], f[i - p[0]][1], '0');
    }
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++) {
        scanf("%d", &n);
        printf("%s\n", f[n][0].c_str());
    }
    return 0;
}