#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    getline(cin, s);
    vector<int> a;
    for (int i = 0; i < s.size(); i ++)
    {
        if (s[i] >= '0' && s[i] <= '9') a.push_back(s[i] - 48);
    }
    sort(a.begin(), a.end());
    for (int i = a.size() - 1; i >= 0; i --)
        cout << a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
