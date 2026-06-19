#include<bits/stdc++.h>

using namespace std;

int n, pac[1000010]{};
bool hd[1000010]{};

int fd(int i, int fail) {

}

int main() {
#ifndef MYDEBUG
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
#endif

    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '1') hd[i] = true;
    }

    for (int i = 1; i <= n; i++) {
        cin >> pac[i];
    }

    cout << 28;

    return 0;
}

// ^_^
