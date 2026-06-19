//color
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int T, n, a[N];
typedef long long ll;
ll t[N*4], tag[N*4];

void psd(int p){
    t[p<<1] += tag[p];
    t[p<<1|1] += tag[p];
    tag[p<<1] += tag[p];
    tag[p<<1|1] += tag[p];
    tag[p] = 0;
}
void mdf(int p, int l, int r, int x, ll v){
    if(l == r){
        t[p] = max(t[p], v);
        tag[p] = 0;
    } else {
        int mid = l + r >> 1;
        psd(p);
        if(x <= mid){
            mdf(p<<1, l, mid, x, v);
        } else {
            mdf(p<<1|1, mid+1, r, x, v);
        }
        t[p] = max(t[p<<1], t[p<<1|1]);
    }
}
ll qry(int p, int l, int r, int x){
    if(l == r){
        return t[p];
    } else {
        int mid = l + r >> 1;
        psd(p);
        if(x <= mid){
            return qry(p<<1, l, mid, x);
        } else {
            return qry(p<<1|1, mid+1, r, x);
        }
    }
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int mx = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            mx = max(mx, a[i]);
        }
        memset(t, 0xcf, sizeof(t));
        memset(tag, 0, sizeof(tag));
        mdf(1, 0, mx, 0, 0);
        for(int i = 2; i <= n; ++ i){
            ll val = t[1], qr = qry(1, 0, mx, a[i]);
            if(a[i] == a[i-1]){
                tag[1] += a[i];
            }
            mdf(1, 0, mx, a[i-1], max(val, qr + a[i]));
        }
        printf("%lld\n", t[1]);
    }
    return 0;
}