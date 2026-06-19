#include <iostream>
using namespace std;
bool d[15] = {0}, c[15] = {0}, h[15] = {0}, s[15] = {0};
int n, cnt = 0;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int actual;
        cin >> a >> b;
        switch (b) {
        case 'A':
            actual = 1;
            break;
        case 'T':
            actual = 10;
            break;
        case 'J':
            actual = 11;
            break;
        case 'Q':
            actual = 12;
            break;
        case 'K':
            actual = 13;
            break;
        default:
            actual = b - '0';
            break;
        }
        switch (a) {
        case 'D':
            d[actual] = true;
        case 'C':
            c[actual] = true;
        case 'H':
            h[actual] = true;
        case 'S':
            s[actual] = true;
        }
    }
    for (int i = 1; i <= 13; i++) {
        if (!d[i])
            cnt++;
        if (!c[i])
            cnt++;
        if (!h[i])
            cnt++;
        if (!s[i])
            cnt++;
    }
    cout << cnt;
    return 0;
}
