#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    LL n;
    cin >> n;
    vector<string> a;
    for (LL i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    auto pos = unique(a.begin(), a.end());
    LL len = distance(a.begin(), pos);
    cout << 52 - len << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
