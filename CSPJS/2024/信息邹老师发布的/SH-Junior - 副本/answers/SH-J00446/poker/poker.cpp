#include<bits/stdc++.h>
using namespace std;

int n;
map<char, int> m1, m2;
bool f[100];
int ans;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    m1['S'] = 0, m1['H'] = 1, m1['D'] = 2, m1['C'] = 3;
    m2['A'] = 1, m2['2'] = 2, m2['3'] = 3, m2['4'] = 4, m2['5'] = 5, m2['6'] = 6, m2['7'] = 7, m2['8'] = 8, m2['9'] = 9, m2['T'] = 10, m2['J'] = 11, m2['Q'] = 12, m2['K'] = 13;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        f[m1[c1] * 13 + m2[c2]] = 1;
    }
    for(int i = 1; i <= 52; i++)
        if(!f[i]) ans++;
    cout << ans << endl;
    return 0;
}
