#include <bits/extc++.h>

using namespace std;
namespace pbds = __gnu_pbds;

namespace {
    ifstream fin("replace.in");
    ofstream fout("replace.out");

    int n, q;
    pbds::gp_hash_table<size_t, int> c;

    void solve() {
        fin >> n >> q;
        auto h = hash<string>();
        int e = h(string());
        for (string a, b; n--; ) {
            fin >> a >> b;
            int l = -1, r = 0, m = a.size();
            for (int i = 0; i < m; a[i] ^ b[i] && (~l || (l = i), r = i), i++);
            if (~l) r++, c[h(a.substr(l, r - l) + b.substr(l, r - l))]++;
            else c[e]++;
        }
        for (string a, b; q--; ) {
            fin >> a >> b;
            if (a.size() ^ b.size()) {
                fout << "0\n";
                continue;
            }
            int l = -1, r = 0, m = a.size();
            for (int i = 0; i < m; a[i] ^ b[i] && (~l || (l = i), r = i), i++);
            if (~l) r++, fout << c[h(a.substr(l, r - l) + b.substr(l, r - l))] << '\n';
            else fout << c[e] << '\n';
        }
    }
}

int main() {
    solve();
}