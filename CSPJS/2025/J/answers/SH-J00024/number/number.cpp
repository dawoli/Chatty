#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n, cnt = 0;
vector<int> a;
string s;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    n = s.length();
    for (int i = 0; i <= n; ++i) {
        char c = s[i];
        if (0 <= c - '0' && c - '0' <= 9) {
            a.push_back(c - '0');
            ++cnt;
        }
    }
    sort(a.begin(), a.end());
    for (int i = cnt-1; i >= 0; --i) {
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
