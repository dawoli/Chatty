#include <iostream>
#include <vector>
using namespace std;

using LL = long long;

const LL N = 5e5 + 10;
const LL M = (1 << 20) + 10;
LL a[N], x[N], dp[N];
vector<LL> val_to_id[M];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    LL n, k;
    cin >> n >> k;
    x[0] = 0;
    val_to_id[0].push_back(0);
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = x[i - 1] ^ a[i];
        val_to_id[x[i]].push_back(i);
    }
    dp[0] = 0;
    for (LL i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        //printf("dp[%d] = dp[%d]\n", i, i - 1);
        for (LL j : val_to_id[x[i] ^ k]) {
            if (j >= i) {
                break;
            }
            dp[i] = max(dp[i], dp[j] + 1);
            //printf("dp[%d] max= dp[%d] + 1\n", i, j);
        }
        //printf("dp[%d] = %d\n", i, dp[i]);
    }
    cout << dp[n] << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
