#include <bits/stdc++.h>
using namespace std;
vector<int> a;
string s;
signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for (auto it : s)
        if (it >= '0' && it <= '9')
            a.push_back(it - '0');
    sort(a.begin(), a.end(), greater<int>());
    for (auto it : a)
        cout << it;
}
// AC
