#include <iostream>
#include <deque>
#include <map>
int n, ans;
std::deque<int> left;
std::map<int, int> mp;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    ans = n;
    for (int i = 0; i < n; ++i) {
        int ri;
        std::cin >> ri;
        ++mp[ri];
    }
    for (const auto& p: mp){
        int cnt = p.second;
        while (!left.empty() && cnt > 0)
            if (left.front() <= cnt) {
                ans -= left.front();
                cnt -= left.front();
                left.pop_front();
            } else {
                ans -= cnt;
                left.front() -= cnt;
                cnt = 0;
            }
        left.push_back(p.second);
    }
    std::cout << ans << '\n';
    return 0;
}

