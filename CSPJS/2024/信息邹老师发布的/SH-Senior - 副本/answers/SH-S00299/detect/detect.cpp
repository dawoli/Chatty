//detect
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;
int T, n, m, L, V;
int d[N], v[N], a[N], p[N];
int le[N], ri[N];
int prp[M], mx[M], f[M], qr[M];

bool hav(pair<int, int> seq){
    return prp[seq.second] != prp[seq.first - 1];
}
bool calsp(int vv, int ad, int dis){
    return 1ll * vv * vv + 2ll * ad * dis > 1ll * V * V;
}
pair<int, int> cala(int st, int vv, int ad){
    int l = st, r = L + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(calsp(vv, ad, mid-st)){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return make_pair(l, L);
}
pair<int, int> calb(int st, int vv, int ad){
    if(vv <= V) return make_pair(L+1, L);
    int l = st, r = L;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(calsp(vv, ad, mid-st)){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return make_pair(st, l);
}

int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        memset(prp, 0, sizeof(prp));
        memset(mx, 0, sizeof(mx));
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &p[i]);
            ++ prp[p[i]];
        }
        for(int i = 1; i <= L; ++ i){
            prp[i] += prp[i-1];
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            pair<int, int> tmp;
            if(a[i] > 0){
                tmp = cala(d[i], v[i], a[i]);
            } else if(a[i] < 0){
                tmp = calb(d[i], v[i], a[i]);
            } else {
                tmp = make_pair(L+1, L);
                if(v[i] > V){
                    tmp.first = d[i];
                }
            }
            if(tmp.first <= tmp.second && hav(tmp)){
                ++ cnt;
                le[cnt] = tmp.first;
                ri[cnt] = tmp.second;
                mx[ri[cnt]] = max(mx[ri[cnt]], le[cnt]);
            }
        }
        printf("%d ", cnt);
        int tmx = 0;
        int l = 1, r = 1;
        qr[1] = 0;
        for(int i = 1; i <= L + 1; ++ i){
            tmx = max(tmx, mx[i-1]);
            if(prp[i] == prp[i-1] && i != L + 1) continue;
            while(l <= r && qr[l] < tmx) ++ l;
            f[i] = f[qr[l]] + 1;
            while(l <= r && f[qr[r]] > f[i]) -- r;
            qr[++r] = i;
        }
        printf("%d", m - f[L+1] + 1);
        puts("");
    }
    return 0;
}