#include <iostream>
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = n; i > 1; --i) {
        ans = ans * i % 998244353;
    }
    std::cout << ans << '\n';
    return 0;
}
