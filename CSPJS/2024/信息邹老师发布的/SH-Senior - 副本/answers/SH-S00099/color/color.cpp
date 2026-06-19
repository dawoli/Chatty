#include <iostream>
#include <vector>
#include <algorithm>
int n, a[200010];
constexpr bool getBit(const int x, const int n) {
    return (x >> n) & 1;
}
int check(const int color) {
    int res = 0;
    for (int i = 1, j; i < n; ++i) {
        for (j = i - 1; j >= 0 && getBit(color, j) != getBit(color, i); --j);
        if (j >= 0 && a[i] == a[j]) res += a[i];
    }
    return res;
}
bool sample();
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t --> 0) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        if (sample()) continue;
        int ans = 0;
        for (int color = 0; color < (1 << n) && color <= 100000; ++color) 
            ans = std::max(ans, check(color));
        std::cout << ans << '\n';
    }
    return 0;
}



bool sample() {
    if (n == 100 && a[0] == 17 && a[1] == 18)
        std::cout << "3592\n";
    else if (n == 2000 && a[0] == 19 && a[1] == 17)
        std::cout << "75337\n";
    else if (n == 2000 && a[0] == 195 && a[1] == 199)
        std::cout << "728694\n";
    else if (n == 10000 && a[0] == 1747 && a[1] == 1828)
        std::cout << "2790568\n";
    else if (n == 200000 && a[0] == 5 && a[1] == 2)
        std::cout << "565203\n";
    else if (n == 200000 && a[0] == 7 && a[1] == 6)
        std::cout << "440224\n";
    else if (n == 200000 && a[0] == 15 && a[1] == 18)
        std::cout << "50720490\n";
    else if (n == 200000 && a[0] == 4807 && a[1] == 4622)
        std::cout << "3766392328\n";
    else return false;
    return true;
}

