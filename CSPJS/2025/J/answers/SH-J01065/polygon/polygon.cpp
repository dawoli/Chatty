#include <cstdio>
#include <algorithm>
using namespace std;
#define MOD 998244353
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    std::sort(x, x+n);
    int max_[n] = 0;

    return 0;
}
