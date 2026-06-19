//replace
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, L = 5e6 + 10;
int n, q;
int ban[N];

typedef unsigned long long ull;
ull A = 998244853, B = 1000000007, C = 337, D = 197;
map<pair<ull, ull>, int> mp;
int cnt;

vector<int> op[N], qr[N];

int ch[L][26], ok[L];
vector<int> ed[L];
int rt[N*2], tot;

vector<int> aa;

int ans[N];
void dfs(int x){
    if(!x) return;
    for(auto i : ed[x]){
        aa.push_back(i);
    }
    for(int i = 0; i < 26; ++ i){
        dfs(ch[x][i]);
    }
    for(auto i : ed[x]){
        if(i <= n) aa.push_back(-i);
    }
}
void solve(){
    for(int i = 1; i <= cnt; ++ i){
        dfs(rt[i]);
    }
    // tot = 0;
    // memset(ch, 0, sizeof(ch));
    for(auto i : aa){
        int p = 0;
        if(i <= n){
            for(int j : op[abs(i)]){
                // printf("%d ", j);
                if(!ch[p][j]){
                    ch[p][j] = ++ tot;
                }
                p = ch[p][j];
            }
            if(i > 0){
                ++ ok[p];
            // printf("ad %d", p);
            } else {
            // printf("de");
                -- ok[p];
            }
            // puts("");
        } else {
            int rs = ok[p];
            // printf("%d\n", rs);
            // printf("qr");
            for(int j : qr[i-n]){
                // printf("|%d ", j);
                if(!ch[p][j]){
                    break;
                }
                p = ch[p][j];
                // printf("[%d %d\n", p, ok[p]);
                rs += ok[p];
            }
            // puts("");
            ans[i-n] = rs;
        }
    }
}

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++ i){
        string x, y;
        cin >> x >> y;
        int len = x.size();
        int l = len, r = 0;
        for(int j = 0, c; j < len; ++ j){
            if(x[j] != y[j]){
                l = min(l, j);
                r = max(r, j);
            }
        }
        ull pp = 0, qq = 0;
        for(int j = l; j <= r; ++ j){
            pp = (pp * C + (x[j] - 'a') * 26 + y[j]) % A;
            qq = (qq * D + (x[j] - 'a') * 26 + y[j]) % B;
        }
        if(!mp[make_pair(pp, qq)]){
            mp[make_pair(pp, qq)] = ++ cnt;
        }
        int nw = mp[make_pair(pp, qq)];
        if(!rt[nw]){
            rt[nw] = ++ tot;
        }
        int p = rt[nw];
        for(int j = l-1; j >= 0; -- j){
            if(!ch[p][x[j]-'a']){
                ch[p][x[j]-'a'] = ++ tot;
            }
            p = ch[p][x[j]-'a'];
        }
        ed[p].push_back(i);
        for(int j = r+1; j < len; ++ j){
            op[i].push_back(x[j] - 'a');
        }
        // printf("%llu %llu %d %d %d\n", pp, qq, l, r, p);
    }
    for(int i = 1; i <= q; ++ i){
        string x, y;
        cin >> x >> y;
        if(x.size() != y.size()){
            ban[i] = 1;
            continue;
        }
        int len = x.size();
        int l = len, r = 0;
        for(int j = 0, c; j < len; ++ j){
            if(x[j] != y[j]){
                l = min(l, j);
                r = max(r, j);
            }
        }
        ull pp = 0, qq = 0;
        for(int j = l; j <= r; ++ j){
            pp = (pp * C + (x[j] - 'a') * 26 + y[j]) % A;
            qq = (qq * D + (x[j] - 'a') * 26 + y[j]) % B;
        }
        if(!mp[make_pair(pp, qq)]){
            ban[i] = 1;
            continue;
        }
        int nw = mp[make_pair(pp, qq)];
        if(!rt[nw]){
            rt[nw] = ++ tot;
        }
        int p = rt[nw];
        for(int j = l-1; j >= 0; -- j){
            if(!ch[p][x[j]-'a']){
                break;
            }
            p = ch[p][x[j]-'a'];
        }
        // if(ban[i]) continue;
        ed[p].push_back(n + i);
        for(int j = r+1; j < len; ++ j){
            qr[i].push_back(x[j] - 'a');
        }
        // printf("-- %llu %llu %d %d %d\n", pp, qq, l, r, p);
    }
    solve();
    for(int i = 1; i <= q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}
