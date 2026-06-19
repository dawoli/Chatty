#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
multimap<string, string> m;
stack<string> stk;
int n, q;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    while (n--) {
        string s, t;
        cin >> s >> t;
        m.insert(make_pair(s, t));
    }
    while (q--) {
        string s, t;
        cin >> s >> t;
        int ans=0;
        int len=s.size();
        for (int i=0; i<len; i++)
            for (int j=1; i+j<=len; j++) {
                while (m.find(s.substr(i, j))!=m.end()) {
                    multimap<string, string>::iterator it=m.find(s.substr(i, j));
                    string tmp=((i==0)?"":s.substr(0, i))+(*it).second+((i+j==len)?"":s.substr(i+j, len-i-j));
                    stk.push((*it).second);
                    m.erase(it);
                    if (tmp==t) ans++;
                }
                while (!stk.empty()) {
                    m.insert(make_pair(s.substr(i, j), stk.top()));
                    stk.pop();
                }
            }
        cout << ans << endl;
    }
}
