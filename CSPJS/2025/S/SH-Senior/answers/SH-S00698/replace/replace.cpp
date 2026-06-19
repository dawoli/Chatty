#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

using LL = long long;

const LL N = 2e5 + 10;
unordered_map<LL, vector<pair<pair<LL, LL>, pair<LL, LL>>>> change;

pair<LL, LL> convert(string s) {
    LL len = s.size();
    for (LL i = 0; i < len; i++) {
        if (s[i] == 'b') {
            return {i, len - i - 1};
        }
    }
    return {-1, -1};
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    LL n, q;
    cin >> n >> q;
    for (LL i = 1; i <= n; i++) {
        string s, t;
        cin >> s >> t;
        pair<LL, LL> x = convert(s);
        pair<LL, LL> y = convert(t);
        change[x.first - y.first].push_back({x, y});
    }
    for (LL i = 1; i <= q; i++) {
        string s, t;
        cin >> s >> t;
        pair<LL, LL> x = convert(s);
        pair<LL, LL> y = convert(t);
        LL cnt = 0;
        for (auto p : change[x.first - y.first]) {
            LL pre_from = p.first.first;
            LL pre_to = p.first.second;
            LL suf_from = p.second.first;
            LL suf_to = p.second.second;
            if (pre_from <= x.first && pre_to <= x.second && suf_from <= y.first && suf_to <= y.second) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
