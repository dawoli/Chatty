#include <bits/stdc++.h>
using namespace std;

int d[14], c[14], h[14], s[14];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout); 
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char x, y;
        cin >>x >>y;
        if (x == 'D') {
            if (y > '1' && y <= '9') {
                d[y-'0'] ++;
            } else if (y == 'T') {
                d[10]++;
            } else if (y == 'J') {
                d[11]++;
            } else if (y == 'Q') {
                d[12]++;
            } else if (y == 'K') {
                d[13]++;
            } else {
                d[1]++;
            }
        } else if (x == 'C') {
            if (y > '1' && y <= '9') {
                c[y-'0'] ++;
            } else if (y == 'T') {
                c[10]++;
            } else if (y == 'J') {
                c[11]++;
            } else if (y == 'Q') {
                c[12]++;
            } else if (y == 'K') {
                c[13]++;
            } else {
                c[1]++;
            }
        } else if (x == 'H') {
            if (y > '1' && y <= '9') {
                h[y-'0'] ++;
            } else if (y == 'T') {
                h[10]++;
            } else if (y == 'J') {
                h[11]++;
            } else if (y == 'Q') {
                h[12]++;
            } else if (y == 'K') {
                h[13]++;
            } else {
                h[1]++;
            }
        } else if (x == 'S') {
            if (y > '1' && y <= '9') {
                s[y-'0'] ++;
            } else if (y == 'T') {
                s[10]++;
            } else if (y == 'J') {
                s[11]++;
            } else if (y == 'Q') {
                s[12]++;
            } else if (y == 'K') {
                s[13]++;
            } else {
                s[1]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 13; i++) {
//    	cout << d[i];
        if (d[i] == 0) ans++;
    }
    for (int i = 1; i <= 13; i++) {
//    	cout << c[i];
        if (c[i] == 0) ans++;
    }
    for (int i = 1; i <= 13; i++) {
//    	cout << h[i];
        if (h[i] == 0) ans++;
    }
    for (int i = 1; i <= 13; i++) {
//    	cout << s[i];
        if (s[i] == 0) ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
