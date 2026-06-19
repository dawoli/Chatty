#include <iostream>
#include <queue>
struct Member{
    int a[3];
};
template <int type>
struct Cmp {
    bool operator ()(const Member &a, const Member &b) const {
        return a.a[type] - a.a[(type + 1) % 3] - a.a[(type + 2) % 3] > b.a[type] - b.a[(type + 1) % 3] - b.a[(type + 2) % 3];
    }
};
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n;
    std::cin >> t;
    while (t-- > 0) {
        std::cin >> n;
        std::priority_queue<Member, std::vector<Member>, Cmp<0>> m0;
        std::priority_queue<Member, std::vector<Member>, Cmp<1>> m1;
        std::priority_queue<Member, std::vector<Member>, Cmp<2>> m2;
        int cnt[3]{};
        for (int i = 0; i < n; ++i) {
            Member mem;
            std::cin >> mem.a[0] >> mem.a[1] >> mem.a[2];
            if (mem.a[0] >= mem.a[1] && mem.a[0] >= mem.a[2]) {
                m0.push(mem);
                cnt[0] += mem.a[0];
            } else if (mem.a[1] >= mem.a[2]) {
                m1.push(mem);
                cnt[1] += mem.a[1];
            } else {
                m2.push(mem);
                cnt[2] += mem.a[2];
            }
        }
        while (m0.size() > n / 2) {
            auto mem = m0.top();
            m0.pop();
            cnt[0] -= mem.a[0];
            if (mem.a[1] >= mem.a[2]) {
                m1.push(mem);
                cnt[1] += mem.a[1];
            } else {
                m2.push(mem);
                cnt[2] += mem.a[2];
            }
        }
        while (m1.size() > n / 2) {
            auto mem = m1.top();
            m1.pop();
            cnt[1] -= mem.a[1];
            if (mem.a[0] >= mem.a[2] && m0.size() <= n / 2) {
                m0.push(mem);
                cnt[0] += mem.a[0];
            } else {
                m2.push(mem);
                cnt[2] += mem.a[2];
            }
        }
        while (m2.size() > n / 2) {
            auto mem = m2.top();
            m2.pop();
            cnt[2] -= mem.a[2];
            if (mem.a[0] >= mem.a[1] && m0.size() <= n / 2) {
                m0.push(mem);
                cnt[0] += mem.a[0];
            } else {
                m1.push(mem);
                cnt[1] += mem.a[1];
            }
        }
        std::cout << cnt[0] + cnt[1] + cnt[2] << '\n';
    }
    return 0;
}
