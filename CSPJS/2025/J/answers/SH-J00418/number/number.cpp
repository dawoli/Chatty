// SH-J00418
// number
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
vector<ll> v;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if('0'<=s[i]&&s[i]<='9') {
            v.push_back(s[i] - '0');
        }
    }
    sort(v.begin(),v.end(),greater<ll>());
    for(auto i : v) {
        cout<<i;
    }
    return 0;
}
