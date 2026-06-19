#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(nullptr));
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
    int T;
    cin >> T;
    while(T-- > 0) {
        cout << rnd() << '\n';
    }
    return 0;
}
