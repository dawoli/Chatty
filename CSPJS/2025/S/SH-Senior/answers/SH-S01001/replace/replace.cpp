#include <bits/stdc++.h>
using namespace std;
int n,q,k,l,r,p,tr[8000010][30],fl[8000010],rt[8000010],val[8000010],cnt,st[8000010],ans;
vector<int> vec[8000010];
string s1,s2;
const char mg='{';
int find(const string &x) {
    int u=0;
    for (char c:x) {
        if (!tr[u][c-'a'+1]) tr[u][c-'a'+1]=++cnt;
        u=tr[u][c-'a'+1];
    }
    return u;
}
void append(int u,const string &x) {
    //cout<<"A "<<u<<' '<<x<<endl;
    if (!rt[u]) rt[u]=++cnt;
    u=rt[u];
    for (char c:x) {
        if (!tr[u][c-'a'+1]) tr[u][c-'a'+1]=++cnt;
        u=tr[u][c-'a'+1];
    }
    ++val[u];
}
void _ac(int u) {
    for (int v:vec[u]) val[v]+=val[u],_ac(v);
}
void ac(int u) {
    //cout<<u<<endl;
    l=1;
    r=0;
    fl[u]=u;
    for (int i=1;i<=27;++i) if (tr[u][i]) st[++r]=tr[u][i],fl[tr[u][i]]=u,vec[u].push_back(tr[u][i]);
    else tr[u][i]=u;
    while (l<=r) {
        p=st[l];
        ++l;
        for (int i=1;i<=27;++i) if (tr[p][i]) {
            fl[tr[p][i]]=tr[fl[p]][i];
            vec[tr[fl[p]][i]].push_back(tr[p][i]);
            st[++r]=tr[p][i];
        }
        else tr[p][i]=tr[fl[p]][i];
    }
    _ac(u);
}
void dfs(int u) {
    for (int i=1;i<=26;++i) if (tr[u][i]) dfs(tr[u][i]);
    if (rt[u]) ac(rt[u]);
}
int query(int u,const string &x) {
    //cout<<"Q "<<u<<' '<<x<<endl;
    if (!rt[u]) return 0;
    u=rt[u];
    ans=0;
    for (char c:x) {
        u=tr[u][c-'a'+1];
        ans+=val[u];
    }
    return ans;
}
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;++i) {
        cin>>s1>>s2;
        k=s1.size();
        l=-1;
        r=-1;
        for (int i=0;i<k;++i) if (s1[i]!=s2[i]) {
            if (l==-1) l=i;
            r=i;
        }
        if (l==-1) continue;
        append(find(s1.substr(l,r-l+1)+s2.substr(l,r-l+1)),s1.substr(0,l)+mg+s1.substr(r+1));
    }
    dfs(0);
    for (int i=1;i<=q;++i) {
        cin>>s1>>s2;
        k=s1.size();
        if (k!=s2.size()) {
            cout<<"0\n";
            continue;
        }
        l=-1;
        r=-1;
        for (int i=0;i<k;++i) if (s1[i]!=s2[i]) {
            if (l==-1) l=i;
            r=i;
        }
        cout<<query(find(s1.substr(l,r-l+1)+s2.substr(l,r-l+1)),s1.substr(0,l)+mg+s1.substr(r+1))<<'\n';
    }
}