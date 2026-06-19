#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b)for(ll i=(a);i<=(b);i++)
#define rrep(i, a, b) for(ll i=(a);i>=(b);i--)
const ll N=1e5+9;
ll T;
ll d[N], v[N], a[N];    
ll n, m, L, V;
struct segment{
    ll l, r;
    bool operator <(const segment &b)const{
        return r<b.r||(r==b.r&&l<b.l);
    }
    bool operator ==(const segment &b)const{
        return r==b.r&&l==b.l;
    }
};
segment seg[N], danger[N];
ll nS, nD;
ll p[N];
ll rightest=-1;
segment physics(ll d, ll v, ll a){
    if(a==0){
        if(v>V){
            return (segment){d, L};
        }else{
            return (segment){0, 0};
        }
    }else if(a>0){
        if(v>V)return (segment){d, L};
        ll fenzi=(2*v*V-2*v*v+(V-v)*(V-v));
        ll st=0;
        st=fenzi/(2*a)+1+d;
        if(st>L)return (segment){0, 0};
        else return (segment){st, L};
    }else if(a<0){
        if(v<=V)return (segment){0, 0};
        else{
            ll fenzi=(2*v*V-2*v*v+(V-v)*(V-v));
            ll st=0;
            if(fenzi%(2*a)==0){
                st=fenzi/(2*a)-1;
            }else{
                st=fenzi/(2*a);
            }
            st+=d;
            st=min(st, L);
            st=max(st, d);
            return (segment){d, st};
        }
    }
    return (segment){0, 0};
}
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    //这道题真简单啊
    cin >> T;
    while(T--){
        cin >> n >> m >> L >> V;
        nS=0;nD=0;
        rep(i, 1, n){
            cin >> d[i] >> v[i] >> a[i];
            segment s=physics(d[i], v[i], a[i]);
            if(s==(segment){0, 0}){
                continue;
            }
            // if(s.l<0||s.l>s.r||s.r>L){
            //     cout << "error";
            // }
            // cout << i << ' ' << s.l << ' ' << s.r << endl;
            seg[++nS]=s;
        }
        rep(i, 1, m){
            cin >> p[i];
        }
        sort(p+1, p+m+1);
        ll cnt=0;
        rep(i, 1, nS){
            ll pos=p[upper_bound(p+1, p+m+1, seg[i].r)-p-1];
            if(pos>=seg[i].l){
                cnt++;
                danger[++nD]=seg[i];
            }
        }
        cout << cnt << ' ';
        sort(danger+1, danger+nD+1);
        rightest=-1;
        ll cntmust=0;
        rep(i, 1, nD){
            // cout << "danger" << ' ' << danger[i].l << ' ' << danger[i].r << endl;
            if(rightest>=danger[i].l)continue;
            cntmust++;
            ll pos=p[upper_bound(p+1, p+m+1, danger[i].r)-p-1];
            // cout << "选择" << pos << endl;
            rightest=pos;
        }
        cout << m-cntmust << endl;
    }
    return 0;
}