#include <iostream>
using namespace std;

typedef long long LL;

const LL N = 2e5 + 10;
LL a[N];
bool is_red[N];
LL n;

LL score() {
    LL sum = 0;
    for (LL i = 0; i < n; i++) {
        LL pos = -1;
        for (LL j = 0; j < i; j++) {
            if (is_red[i] == is_red[j]) {
                pos = j;
            }
        }
        if (pos == -1 || a[i] != a[pos]) {
            continue;
        }
        sum += a[i];
    }
    return sum;
}

LL solve(LL i) {
    if (i == n) {
        return score();
    }
    LL max_score = 0;
    is_red[i] = true;
    max_score = max(max_score, solve(i + 1));
    is_red[i] = false;
    max_score = max(max_score, solve(i + 1));
    return max_score;
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    LL t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (LL i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(0) << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
