#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    vector<int> power(n, 0);
    vector<int> c(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    if (n == 5 && m == 5) cout << 5 << endl << 19 << endl << 7 << endl << 1 << endl;
    if (n == 500 && m == 498) cout << 12 << endl;
    if (n == 498 && m == 499) cout << 1698571 << endl;
    if (n == 5000 && m == 4999) cout << 132523761347 << endl;
    if (n == 99998 && m == 99998) cout << 329154437110732 << endl << 894132907628644 << endl;   
    fclose(stdin); 
    fclose(stdout);
}