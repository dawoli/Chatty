#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll r[10];
string s;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        if('0' <=s[i] && s[i] <='9') {
            r[s[i]-'0']++;
        }
    }
    for(ll i = 9; i >= 0; i--) {
        for(ll j = 1; j <= r[i]; j++) {
            cout << i;
        }
    }
    return 0;
}
