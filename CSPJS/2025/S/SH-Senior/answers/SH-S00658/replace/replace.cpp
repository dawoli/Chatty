#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+5;

unordered_map<string, int> S;
vector<string> st1[maxn], st2[maxn];

unordered_set<string> p, q;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, Q;
    cin>>n>>Q;
    string a,b,c;
    int l, r, len;
    int cnt=0;
    int id;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        len=a.length();
        l=0, r=len-1;
        while(a[l]==b[l] && l<r) ++l;
        if(a[l]==b[l]) continue;
        while(a[r]==b[r]) --r;
        c=a.substr(l, r-l+1)+b.substr(l, r-l+1);
        if(!S[c]) S[c]=++cnt;
        id=S[c];
        st1[id].push_back(a.substr(0, l));
        st2[id].push_back(a.substr(r+1));     // potent RE


    }
    while(Q--) {
        cin>>a>>b;
        len=a.length();
        if(b.length()!=len) {
            cout<<"0\n";
            continue;
        }
        l=0, r=len-1;
        while(a[l]==b[l]) ++l;
        while(a[r]==b[r]) --r;
        c=a.substr(l, r-l+1)+b.substr(l, r-l+1);
        if(S.find(c)==S.end()) {
            cout<<"0\n";
            continue;
        }
        id=S[c];
        p.clear(); q.clear();
        c="";
        p.insert(c);
        for(int i=l-1;i>=0;--i) {
            c=a[i]+c;
            p.insert(c);
        }
        c="";
        q.insert(c);
        for(int i=r+1;i<len;++i) {
            c+=a[i];
            q.insert(c);
        }
        len=st1[id].size();
        int ans=0;
        for(int i=0;i<len;i++) {
            if(p.find(st1[id][i])!=p.end() && q.find(st2[id][i])!=q.end()) ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}