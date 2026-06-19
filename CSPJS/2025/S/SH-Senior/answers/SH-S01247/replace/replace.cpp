#include<bits/stdc++.h>
using namespace std;

const int L = 5e6+10;
const int N = 2e5+10;
int n, q, sum[L], fail[L], cntp, v1[L], v2[L], st, ed, hsh[L];
unordered_map<int,int> trie[L];
struct nxt{
    int pos, hsh;
};
vector<nxt> cg[L];

void add(string s1,string s2){
    int p = 0;
    for(int i = 0; i < s1.length(); i++){
        int a1 = s1[i]-'a';
        int a2 = s2[i]-'a';
        int hsh = a1*26+a2;
        if(trie[p][hsh] == 0){
            trie[p][hsh] = ++cntp;
            cg[p].push_back((nxt){cntp,hsh});
        }
        p = trie[p][hsh];
    }
    ++sum[p];
}

struct Node{
    int pos, fal;
};

queue<Node> sk;

void build(){
    for(auto v : cg[0])
        sk.push((Node){v.pos,0});
    while(!sk.empty()){
        Node u = sk.front();
        sk.pop();
        fail[u.pos] = u.fal;
        sum[u.pos] += sum[u.fal];
        for(auto v : cg[u.pos]){
            int nfal = u.fal;
            while(nfal != 0 && trie[nfal][v.hsh] == 0) nfal = fail[nfal];
            if(trie[nfal][v.hsh]) nfal = trie[nfal][v.hsh];
            sk.push((Node){v.pos,nfal});
        }
    }
}

string s[N][2];

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s[i][1] >> s[i][2];
        add(s[i][1],s[i][2]);
    }
    build();
    for(int i = 1; i <= q; i++){
        string t1,t2;
        cin >> t1 >> t2;
        st = ed = 0;
        int len = t1.length();
        if(t1.length() != t2.length()){
            cout << "0\n";
            continue;
        }
        for(int i = 0; i < len; i++){
            v1[i+1] = t1[i]-'a';
            v2[i+1] = t2[i]-'a';
            hsh[i+1] = v1[i+1]*26+v2[i+1];
        }
        for(int i = 1; i <= len; i++){
            if(v1[i] != v2[i]){
                st = (st==0?i:st);
                ed = i;
            }
        }
        int p = 0;
        int sum1 = 0;
        for(int i = 1; i <= len; i++){
            while(p != 0 && trie[p][hsh[i]]==0) p = fail[p];
            if(trie[p][hsh[i]]) p = trie[p][hsh[i]];
            if(i >= ed) sum1 += sum[p];
        }
        p = 0;
        for(int i = st+1; i <= len; i++){
            while(p != 0 && trie[p][hsh[i]]==0) p = fail[p];
            if(trie[p][hsh[i]]) p = trie[p][hsh[i]];
            if(i >= ed) sum1 -= sum[p];
        }
        cout << sum1 << "\n";
    }
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/