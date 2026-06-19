#include <bits/stdc++.h>

using namespace std;

int pref[200005]{};

int main() {
    ifstream in("xor.in");
    ofstream out("xor.out");
    int n, k;
    in >> n >> k;

    for (int i = 1; i <= n; ++i) {
        int num;
        in >> num;
        pref[i] = pref[i - 1] ^ num;
    }

    vector<pair<int, int>> spans;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if ((pref[i-1] ^ pref[j]) == k) {
                spans.push_back({i,j});
                break;
            }
        }
    }
    sort(spans.begin(), spans.end(), [](auto lhs, auto rhs) {
        return lhs.second < rhs.second;
    });
    int cur = 0;
    int ans = 0;
    for (auto span : spans) {
        if (span.first <= cur) continue;
        // cout << "["<<span.first<<", "<<span.second<<"]"<<endl;
        ans++;
        cur = span.second;
    }
    out << ans << endl;
    return 0;
}