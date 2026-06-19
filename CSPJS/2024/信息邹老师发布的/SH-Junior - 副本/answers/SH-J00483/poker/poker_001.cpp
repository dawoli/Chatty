#include <bits/stdc++.h>
using namespace std;

int m[200][200];


int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    long long n, result=0;
    char a,b;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        if (m[a][b]==0) {
        m[a][b] = 1;
        result++;
        }
    }
    cout << 52-result;
    return 0;
}
