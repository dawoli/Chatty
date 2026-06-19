#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10,M = 2e6 + 10;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,k;
pair<int,pii > edgs[M];
int c[N],a[13][N];
pair<int,pii> cedgs[M];
int fa[N];
inline int find(int x){
    if(x!=fa[x])fa[x] = find(fa[x]);
    return fa[x];
}
ll kruskal(int mnum){
    for(int i = 1; i <= n + k ; ++ i)fa[i] = i;
    for(int i = 1; i <= m ; ++ i)cedgs[i] = edgs[i];
    if(mnum > m){
        sort(cedgs+m+1,cedgs+mnum+1);
        inplace_merge(cedgs+1,cedgs+m+1,cedgs+mnum+1);
    }
    ll tot = 0,cnt = 0;
    for(int i = 1; i < mnum; ++ i)assert(cedgs[i].first <= cedgs[i+1].first);
    for(int i = 1; i <= mnum ; ++ i){
        int u = cedgs[i].second.first, v = cedgs[i].second.second;
        assert(u != v);
        assert(u >= 1 && u <= n + k);
        assert(v >= 1 && v <= n + k);
        u = find(u),v = find(v);
        assert(u >= 1 && u <= n + k);
        assert(v >= 1 && v <= n + k);
        if(u == v)continue;
        fa[u] = v;
        tot += cedgs[i].first;
        ++cnt;
    }
    return tot;
}
namespace BF{
    ll res;
    void work(){
        sort(edgs+1,edgs+m+1);
        for(int i = 1; i <= m ; ++ i)cedgs[i] = edgs[i];
        res = kruskal(m);
        for(int i = 1; i < (1<<k) ; ++ i){
            int cnt = m;
            ll cost = 0;
            for(int p = 0; p < k ; ++ p){
                if(!((i>>p)&1))continue;
                cost += c[p+1];
                for(int j = 1; j <= n ; ++ j){
                    cedgs[++cnt] = {a[p+1][j],{p+1 + n,j}};
                }
            }
            ll u = kruskal(cnt);
            res = min(res,u + cost);
        }
        cout << res << "\n";
    }
}
namespace SubA{
    ll res;
    void work(){
        sort(edgs+1,edgs+m+1);
        for(int i = 1; i <= m ; ++ i)cedgs[i] = edgs[i];
        res = kruskal(m);
        for(int i = (1<<k) - 1; i < (1<<k) ; ++ i){
            int cnt = m;
            ll cost = 0;
            for(int p = 0; p < k ; ++ p){
                if(!((i>>p)&1))continue;
                cost += c[p+1];
                for(int j = 1; j <= n ; ++ j)cedgs[++cnt] = {a[p+1][j],{p+1 + n,j}};
            }
            ll u = kruskal(cnt);
            res = min(res,u + cost);
        }
        cout << res << "\n";
    }
}
namespace STD{
    int fa[N],tot = 0;
    pair<int,pii> nedgs[M],pedgs[M];
    pair<int,int> pr[13][N];
    int find(int x){
        if(x != fa[x])fa[x] = find(fa[x]);
        return fa[x];
    }
    ll dkruk(int mnum){
        for(int i = 1; i <= n + k ; ++ i)fa[i] = i;
        for(int i = 1; i <= tot ; ++ i)nedgs[i] = pedgs[i];
        inplace_merge(nedgs+1,nedgs+tot+1,nedgs+mnum+1);
        ll s = 0;
        for(int i = 1; i <= mnum ; ++ i){
            int u = nedgs[i].second.first, v = nedgs[i].second.second;
            u = find(u),v = find(v);
            if(u == v)continue;
            fa[u] = v;
            s += nedgs[i].first;
        }
        return s;
    }
    void work(){
        for(int i = 1; i <= k ; ++ i){
            for(int j = 1; j <= n ; ++ j)pr[i][j] = {a[i][j],j};
            sort(pr[i]+1,pr[i]+n+1);
        }
        for(int i = 1; i <= n + k ; ++ i)fa[i] = i;
        for(int i = 1; i <= m ; ++ i)cedgs[i] = edgs[i];
        sort(cedgs+1,cedgs+m+1);
        ll res = 0;
        tot = 0;
        for(int i = 1; i <= m ; ++ i){
            int u = cedgs[i].second.first,v = cedgs[i].second.second;
            u = find(u),v = find(v);
            if(u == v)continue;
            fa[u] = v;
            nedgs[++tot] = cedgs[i];
            res += cedgs[i].first;
        }
        sort(nedgs+1,nedgs+tot+1);
        for(int i = 1 ; i <= tot ; ++ i)pedgs[i] = nedgs[i];
        for(int i = 1; i < (1<<k) ; ++ i){
            int cnt = tot;
            ll cost = 0;
            for(int p = 0; p < k ; ++ p){
                if(!((i>>p)&1))continue;
                int t = (p + 1);
                cost += c[t];
                int lst = cnt;
                for(int j = 1; j <= n ; ++ j){
                    nedgs[++cnt] = {pr[t][j].first,{n+t,pr[t][j].second}};
                }
                inplace_merge(nedgs+tot+1,nedgs+lst+1,nedgs+cnt+1);
            }
            ll u = dkruk(cnt);
            res = min(res,u + cost);
        }
        cout << res << "\n";
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1,u,v,w; i <= m ; ++ i)cin >> u >> v >> w,edgs[i] = {w,{u,v}};
    bool subA = 1;
    for(int i = 1; i <= k ; ++ i){
        cin >> c[i];
        subA &= (c[i] == 0);
        bool ok = 0;
        for(int j = 1; j <= n ; ++ j){
            cin >> a[i][j];
            if(a[i][j] == 0)ok = 1;
        }
        subA &= ok;
    }
    if(n >= 1000 && subA)SubA::work();
    else STD::work();
    return 0;
}