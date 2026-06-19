#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using LL = long long;

const LL N = 1e5 + 10;
LL d[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    LL t;
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        LL sum = 0;
        vector<LL> best_1, best_2, best_3;
        for (LL i = 1; i <= n; i++) {
            vector<LL> vals(3, 0);
            cin >> vals[0] >> vals[1] >> vals[2];
            LL max_val = max(vals[0], max(vals[1], vals[2]));
            sum += max_val;
            if (vals[0] == max_val) {
                best_1.push_back(i);
            } else if (vals[1] == max_val) {
                best_2.push_back(i);
            } else {
                best_3.push_back(i);
            }
            sort(vals.begin(), vals.end(), greater<LL>());
            d[i] = vals[0] - vals[1];
        }
        LL half = n / 2;
        vector<LL> best;
        if (LL(best_1.size()) > half) {
            best = best_1;
        } else if (LL(best_2.size()) > half) {
            best = best_2;
        } else if (LL(best_3.size()) > half) {
            best = best_3;
        } else {
            cout << sum << endl;
            continue;
        }
        vector<LL> ds;
        for (LL i : best) {
            ds.push_back(d[i]);
        }
        sort(ds.begin(), ds.end());
        LL len = ds.size();
        for (LL i = 0; i < len - half; i++) {
            sum -= ds[i];
        }
        cout << sum << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
