#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("./number.in", "r", stdin);
    freopen("./number.out", "w", stdout);

    string s; cin >> s;
    int bucket[10] = {};

    for (char i : s) if (i <= '9' && i >= '0') bucket[i - '0']++;

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < bucket[i]; j++) cout << (char)('0' + i);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
