#include<bits/stdc++.h>
using namespace std;
#define mod 998'244'353
const int N = 5005;
int n, a[N];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("ploygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n == 3) {
        int x = a[1], y = a[2], z = a[3];
        if (x + y > z && x + z > y && y + z > x) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}