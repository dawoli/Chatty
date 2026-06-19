#include <iostream>
#include <string>
class view{
    const std::string &str;
    int begin, end;
public:
    explicit view(const std::string &str) : str(str), begin(0), end(str.size()) {}
    explicit view(const std::string &str, const int begin, const int end) : str(str), begin(begin), end(end) {}
    friend int comp(const view &a, const view &b) {
        int i = a.begin, j = b.begin;
        for (; i != a.end; ++i, ++j)
            if (a.str[i] != b.str[j]) return i - a.begin;
        return a.end - a.begin;
    }
    friend int rev_comp(const view &a, const view &b) {
        int i = a.end - 1, j = b.end - 1;
        for (; i != a.begin - 1; --i, --j)
            if (a.str[i] != b.str[j]) return i - a.begin;
        return -1;
    }
    friend bool operator ==(const view &a, const view &b) {
        if (a.end - a.begin != b.end - b.begin) return false;
        int i = a.begin, j = b.begin;
        for (; i != a.end; ++i, ++j)
            if (a.str[i] != b.str[j]) return false;
        return true;
    }
};
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::string s[200010][2], t[2];
    std::cin >> n >> q;
    for (int i = 0; i < n; ++i)
        std::cin >> s[i][0] >> s[i][1];
    while (q-- > 0) {
        std::cin >> t[0] >> t[1];
        if (t[0].size() != t[1].size()) {
            std::cout << "0\n";
            continue;
        }
        int ans = 0;
        const int x = comp(view(t[0]), view(t[1]));
        const int y = rev_comp(view(t[0]), view(t[1]));
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j < n; ++j) {
                const int len = s[j][0].size();
                if (i + len > t[0].size()) continue;
                if (i + len <= y) continue;
                ans += (view(t[0], i, i + len) == view(s[j][0]) &&
                        view(s[j][1]) == view(t[1], i, i + len));
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
