#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s[200009],t[200009];
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i]>>t[i];
    for(int i=1;i<=q;i++) {
        string x,y;
        cin>>x>>y;
        ll ans=0;
        for(int j=1;j<=n;j++) {
            ll st;
            if((st = x.find(s[j]))==x.npos) continue;
            string u = x.substr(0,st) + t[j] + x.substr(st+s[j].size());
            if(u == y) ans ++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
