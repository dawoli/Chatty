#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1.4e5 + 10;
int n,m,K,T;
ll aa[N],c[N];
bool d[N][18];
ll x[4],a[N];
ll ans[N];
namespace SubA{
    int mxdep = 0;
    int dfs(int p,int dep,int L,int R){
        if(L == R)return L;
        int mid = (L + R) >> 1;
        int l = dfs(2*p-1,dep-1,L,mid), r = dfs(2*p,dep-1,mid+1,R);
        if(!d[p][dep] && a[l] >= dep)return l;
        else if(!d[p][dep]) return r;
        else if(d[p][dep] && a[r] >= dep)return r;
        else if(d[p][dep])return l;
        else return r;
    }
    int work(int x){
        mxdep = ceil(log2(x));
        return dfs(1,mxdep,1,1<<mxdep);
    }
}
namespace BF{
    bool pos[N];
    int mxdep = 0,b[N];
    int dfs(int p,int dep,int L,int R){
        if(L == R)return L;
        int mid = (L + R) >> 1;
        int l = dfs(2*p-1,dep-1,L,mid), r = dfs(2*p,dep-1,mid+1,R);
        if(!d[p][dep] && b[l] >= dep)return l;
        else if(!d[p][dep]) return r;
        else if(d[p][dep] && b[r] >= dep)return r;
        else if(d[p][dep])return l;
        else return r;
    }
    int tot = 0;
    void ddfs(int u){
        if(u == (1<<mxdep) + 1){
            int x = dfs(1,mxdep,1,1<<mxdep);
            if(pos[x])return;
            pos[x] = 1;
            tot += x;
            return;
        }
        for(int i = 0; i <= mxdep; ++ i){
            b[u] = i;
            ddfs(u+1);
        }
    }
    int work(int x){
        mxdep = ceil(log2(x));
        for(int i = 0; i <= (1<<mxdep); ++i)pos[i] = 0;
        tot = 0;
        for(int i = 1; i <= x; ++ i)b[i] = a[i];
        ddfs(x+1);
        return tot;
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n ; ++ i) cin >> aa[i];
    bool chA = 1;
    for(int i = 1; i <= m ; ++ i){
        cin >> c[i];
        if((c[i]&-c[i]) != c[i])chA = 0;
    }
    int p = ceil(log2(n));
    K = 1<<p;
    for(int i = 1; i <= p; ++ i){
        for(int j = 1; j <= (K >> i); ++ j){
            char ch;
            cin >> ch;
            d[j][i] = ch=='1';
        }
    }
    cin >> T;
    while(T--){
        for(int i = 0; i < 4; ++ i)cin >> x[i];
        for(int i = 1; i <= n; ++ i) a[i] = aa[i] ^ (x[i%4]);
        if(chA){
            for(int i = 1; i <= m ; ++ i)ans[c[i]] = 0;
            long long cans = 0;
            for(int i = 1; i <= m ; ++ i){
                if(ans[c[i]])continue;
                ans[c[i]] = SubA::work(c[i]);
            }
            for(int i = 1; i <= m ; ++ i){
                cans ^= (1ll * i * ans[c[i]]);
            }
            cout << cans << "\n";
        }else{
            for(int i = 1; i <= m ; ++ i)ans[c[i]] = 0;
            long long cans = 0;
            for(int i = 1; i <= m ; ++ i){
                if(ans[c[i]])continue;
                ans[c[i]] = BF::work(c[i]);
            }
            for(int i = 1; i <= m ; ++ i){
                cans ^= (1ll * i * ans[c[i]]);
            }
            cout << cans << "\n";
        }
    }
    return 0;
}