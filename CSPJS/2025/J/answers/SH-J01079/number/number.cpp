#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
multiset<ll> s;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char ch;
    while(cin >> ch) if('0' <= ch && ch <= '9') s.insert(ch-'0');
    string st;
    for(ll x:s) st += char(x+'0');
    reverse(st.begin(), st.end());
    cout << st << '\n';
    return 0;
}