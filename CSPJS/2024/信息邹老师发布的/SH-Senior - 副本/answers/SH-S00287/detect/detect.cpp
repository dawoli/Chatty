#include <bits/stdc++.h>
#define eps 1e-6
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll T,n,m,L;
ll V;
struct Car{
    ll d,v,a;
    ll l,r;
    bool sp;
}c[N];
int p[N];
pair<int,int> rng[N];
int t[N];
void add(int x,int c){
    for(; x <= m ; x += (x&-x))t[x] += c;
}
int query(int x){
    int res = 0;
    for(;x;x-=(x&-x))res += t[x];
    return res;
}
int query(int l,int r){
    return query(r) - query(l-1);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n ; ++ i){
            cin >> c[i].d >> c[i].v >> c[i].a;
            if(c[i].a == 0 && c[i].v > V){
                c[i].l = c[i].d, c[i].r = L;
                c[i].sp = 1;
            }else if(c[i].a < 0 && c[i].v > V){
                c[i].sp = 1;
                ll diff = (c[i].v * c[i].v - V * V);
                double l = c[i].d, r = c[i].d - (c[i].v * c[i].v - V * V) / (2.0 * c[i].a);
                c[i].l = int(l);
                if((diff % (-2*c[i].a) == 0)){
                    c[i].r = c[i].d - diff/(2ll*c[i].a) - 1;
                }else c[i].r = floor(r);
                if(c[i].r >= L)c[i].r = L;
            }else if(c[i].a > 0){
                if(c[i].v > V){
                    c[i].l = c[i].d;
                    c[i].r = L;
                    c[i].sp = 1;
                }else if(c[i].v == V){
                    if(c[i].d == L)continue;
                    c[i].l = c[i].d + 1;
                    c[i].r = L;
                    c[i].sp = 1;
                }else{
                    ll diff = (V * V - c[i].v * c[i].v);
                    double r = c[i].d + diff / (2.0 * c[i].a);
                    if(diff % (2 * c[i].a) == 0){
                        ll rr = c[i].d + diff / (2ll* c[i].a);
                        if(rr >= L){
                            c[i].sp = 0;
                        }else{
                            c[i].l = rr+1;
                            c[i].r = L;
                            c[i].sp = 1;
                        }
                    }else{
                        if(r >= L){
                            c[i].sp = 0;
                        }else{
                            c[i].l = floor(r) + 1;
                            c[i].r = L;
                            c[i].sp = 1;
                        }
                    }
                }

            }else c[i].sp = 0;
        }
        for(int i = 1; i <= m ; ++ i){
            cin >> p[i];
        }
        int cnt = 0;
        for(int i = 1; i <= n ; ++ i){
            if(c[i].sp){
                int x = *lower_bound(p + 1,p + m + 1, c[i].l);;
                if(x >= c[i].l && x <= c[i].r){
                    int ll = lower_bound(p + 1, p + m + 1, c[i].l) - p;
                    int rr = upper_bound(p + 1, p + m + 1, c[i].r) - p - 1;
                    rng[++cnt] = make_pair(rr,ll);

                }
            }
        }
        sort(rng+1,rng+cnt+1);
        int ans = 0;
        for(int i = 1; i <= cnt ; ++ i){
            int l = rng[i].second , r = rng[i].first;
            if(query(l,r) > 0)continue;
            add(r,1);
            ++ans;
        }
        cout << cnt << " " << m - ans << "\n";
        for(int i = 0; i <= m ; ++ i)t[i] = 0;
    }
    return 0;
}