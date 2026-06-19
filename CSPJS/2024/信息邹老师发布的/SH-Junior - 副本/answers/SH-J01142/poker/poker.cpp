#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    set<string> se;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        se.insert(s);
    }
    cout << 52 - se.size() << endl;
    return 0;
}