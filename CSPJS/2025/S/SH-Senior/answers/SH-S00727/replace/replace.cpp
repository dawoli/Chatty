#include <bits/stdc++.h>
#define moda 1000000007ULL
#define modb 998244353ULL
#define hash_type unsigned long long
using namespace std;
int n, m, cnttrie;
char sa[5000009], sb[5000009];
int fail[5000009], fa[5000009], dep[5000009];
long long repl[5000009];
int trie[5000009][29];
queue <int> q;
vector <int> sons[5000009];
vector < pair < int, pair < int, pair <hash_type, hash_type> > > > query[5000009];
map < pair < int, pair <hash_type, hash_type> >, int>* cntreal[5000009];
map < pair < int, pair <hash_type, hash_type> >, int> cnt[5000009];
pair <hash_type, hash_type> hashinterval(char* s, int l, int r, pair <hash_type, hash_type> iniret = make_pair(0, 0)) {
    for(int i = l; i <= r; i++) {
        iniret.first = ((iniret.first * 31) % moda + s[i] - 'a') % moda;
        iniret.second = ((iniret.second * 37) % modb + s[i] - 'a') % modb;
    }
    return iniret;
}
pair <int, int> diffinterval(char* sa, char* sb) {
    int l = 1, r = strlen(sa);
    for(int i = 0; i < r; i++) {
        if(sa[i] == sb[i])
            l++;
        else
            break;
    }
    for(int i = r - 1; i >= 0; i--) {
        if(sa[i] == sb[i])
            r--;
        else
            break;
    }
    return make_pair(l, r);
}
void insert(char* s, int curval, pair <hash_type, hash_type> curhash, int x = 1) {
    if(s[0] == '\0') {
        cnt[x][make_pair(curval, curhash)]++;
        return;
    }
    if(!trie[x][s[0] - 'a']) {
        trie[x][s[0] - 'a'] = ++cnttrie;
        fa[cnttrie] = x;
        dep[cnttrie] = dep[x] + 1;
    }
    insert(s + 1, curval, curhash, trie[x][s[0] - 'a']);
    return;
}
void build() {
    for(int i = 0; i < 26; i++) {
        if(trie[1][i]) {
            fail[trie[1][i]] = 1;
            sons[fail[trie[1][i]]].push_back(trie[1][i]);
            q.push(trie[1][i]);
        }
        else
            trie[1][i] = 1;
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 0; i < 26; i++) {
            if(trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                sons[fail[trie[x][i]]].push_back(trie[x][i]);
                q.push(trie[x][i]);
            }
            else
                trie[x][i] = trie[fail[x]][i];
        }
    }
    return;
}
void parse_ans(int x) {
    if(!fail[x])
        cntreal[x] = new map < pair < int, pair <hash_type, hash_type> >, int >();
    else
        cntreal[x] = cntreal[fail[x]];
    for(pair < pair <int, pair <hash_type, hash_type> >, int> i : cnt[x]) {
        cntreal[x] -> operator[](i.first) += i.second;
    }
    for(pair <int, pair <int, pair <hash_type, hash_type> > > i : query[x]) {
        repl[i.first] += cntreal[x] -> operator[](i.second);
    }
    for(int i : sons[x]) {
        parse_ans(i);
    }
    for(pair < pair < int, pair <hash_type, hash_type> >, int > i : cnt[x]) {
        cntreal[x] -> operator[](i.first) -= i.second;
        if(!(cntreal[x] -> operator[](i.first)))
            cntreal[x] -> erase(cntreal[x] -> find(i.first));
    }
    return;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cnttrie = 1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s %s", sa + 1, sb + 1);
        int curl = strlen(sa + 1);
        pair <int, int> cur = diffinterval(sa + 1, sb + 1);
        if(cur.first > cur.second)
            continue;
        pair <hash_type, hash_type> curhash = hashinterval(sa, cur.first, cur.second);
        curhash = hashinterval(sb, cur.first, cur.second, curhash);
        insert(sa + 1, curl - cur.second, curhash);
    }
    build();
    for(int i = 1; i <= m; i++) {
        scanf("%s %s", sa + 1, sb + 1);
        int curla = strlen(sa + 1), curlb = strlen(sb + 1);
        if(curla != curlb)
            continue;
        pair <int, int> cur = diffinterval(sa + 1, sb + 1);
        pair <hash_type, hash_type> curhash = hashinterval(sa, cur.first, cur.second);
        curhash = hashinterval(sb, cur.first, cur.second, curhash);
        for(int j = 1, k = 1; j <= curla; j++) {
            k = trie[k][sa[j] - 'a'];
            if(j >= cur.second)
                query[k].push_back(make_pair(i, make_pair(j - cur.second, curhash)));
        }
    }
    for(int i = 1; i <= cnttrie; i++) {
        if(!fail[i])
            parse_ans(i);
    }
    for(int i = 1; i <= m; i++) {
        printf("%lld\n", repl[i]);
    }
    return 0;
}