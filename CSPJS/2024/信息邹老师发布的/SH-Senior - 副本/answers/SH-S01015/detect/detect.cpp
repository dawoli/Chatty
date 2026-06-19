#include <bits/stdc++.h>
#define l(x) (x).first
#define r(x) (x).second
using namespace std;

typedef long long ll;
ll T, n, m, l, v, nUsed, nDeal;
pair<ll,ll> a[100009];
struct carr{ll id; pair<ll,ll> r;} b[100009];
struct car{ll d, v, a;} x[100009];
ll p[100009];
// typedef unsigned long long ull;
// const ull B1 = 131, B2 = 443, B3 = 998244353, B4 = 3499211612;
// ull p1[100009], p2[100009], p3[100009], p4[100009];
// struct tag{ll p, op;ull tg1, tg2, tg3, tg4;};
struct tag{ll p, op;};
// 1 = add, 0 = query, -1 = remove;

bool cmp_tag(const tag& a, const tag& b) {
    return a.p<b.p || (a.p == b.p && a.op > b.op);
}

bool cmp_b(const carr& a, const carr& b) {
    return l(a.r)<l(b.r) || (l(a.r)==l(b.r)&&r(a.r)<r(b.r));
}

pair<ll,ll> detec_range(const car& c) {
    if(c.v <= v && c.a <= 0) return make_pair(-1, -1);
    if(c.v > v && c.a >= 0) return make_pair(c.d, l);
    // c.v<=v, c.a>0 OR c.v>v, c.a<0
    if(c.v <= v && c.a > 0) {
        // we start speeding at some point, and then we get off at the end
        ll speednum = v*v-c.v*c.v, speedden = 2*c.a;
        ll speed = c.d+speednum/speedden+1;
        ll remove = l;
        if(speed > remove) return make_pair(-1, -1);
        return make_pair(speed, remove);
    }
    if(c.v > v && c.a < 0) {
        // we speed at the very time we enter, and then our speed gets below the limit at some point
        ll speed = c.d;
        ll removenum = -v*v+c.v*c.v, removeden = -2*c.a;
        ll remove = c.d+removenum/removeden;
        if(removenum%removeden == 0) remove--;
        if(remove > l) remove = l;
        if(speed > remove) return make_pair(-1, -1);
        return make_pair(speed, remove);
    }
    return make_pair(-1, -1);
}

ll getOK(ll* p, ll m) {
    ll nDeal = 0;
    for(ll i = 1; i <= nUsed; i++) {
        ll lb = lower_bound(p+1, p+m+1, l(a[i]))-p;
        ll ub = upper_bound(p+1, p+m+1, r(a[i]))-p-1;
        if(lb <= ub) nDeal++;
    }
    return nDeal;
}

namespace Sub1_2 {
    ll mp, pp[100009];
    void solve() {
        ll maxrmv = 0;
        for(ll j = 0; j <= (1<<m)-1; j++) {
            mp = 0;
            for(ll i = 1; i <= m; i++) if((j>>(i-1))&1) pp[++mp] = p[i];
            if(getOK(pp, mp) == nDeal) maxrmv = max(maxrmv, m-mp);
        }
        cout << maxrmv << endl;
    }
}

namespace Subbrute {
    set<ll> contain[3009], all;
    void solve() {
        for(ll i = 1; i <= nDeal; i++) all.insert(i);
        for(ll i = 1; i <= nDeal; i++) {
            for(ll j = 1; j <= m; j++) {
                if(l(b[i].r) <= j && r(b[i].r) >= j) contain[j].insert(i);
            }
        }
        ll use = 0;
        while(!all.empty()) {
            ll mx = 0, mxid = 0;
            for(ll i = 1; i <= m; i++) if(contain[i].size() > mx) mx = contain[i].size(), mxid = i;
            for(ll i:contain[mxid]) {
                all.erase(i);
                for(ll j = 1; j <= m; j++) if(j != mxid) if(contain[j].find(i) != contain[j].end()) contain[j].erase(i);
            }
            contain[mxid].clear();
            use++;
        }
        cout << m-use << endl;
    }
}

namespace Solution {
    set<ll> contain[100009], all;
    void solve() {
        for(ll i = 1; i <= nDeal; i++) all.insert(i);
        for(ll i = 1; i <= nDeal; i++) {
            for(ll j = 1; j <= m; j++) {
                if(l(b[i].r) <= j && r(b[i].r) >= j) contain[j].insert(i);
            }
        }
        ll use = 0;
        while(!all.empty()) {
            ll mx = 0, mxid = 0;
            for(ll i = 1; i <= m; i++) if(contain[i].size() > mx) mx = contain[i].size(), mxid = i;
            for(ll i:contain[mxid]) {
                all.erase(i);
                for(ll j = 1; j <= m; j++) if(j != mxid) if(contain[j].find(i) != contain[j].end()) contain[j].erase(i);
            }
            contain[mxid].clear();
            use++;
        }
        cout << m-use << endl;
    }
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    // p1[0] = p2[0] = p3[0] = p4[0] = 1;
    // for(ll i = 1; i < 100009; i++) {
    //     p1[i] = p1[i-1]*B1;
    //     p2[i] = p2[i-1]*B2;
    //     p3[i] = p3[i-1]*B3;
    //     p4[i] = p4[i-1]*B4;
    // }
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> m >> l >> v;
        nUsed = 0;
        for(ll i = 1; i <= n; i++) cin >> x[i].d >> x[i].v >> x[i].a;
        for(ll i = 1; i <= n; i++) {
            pair<ll,ll> pr = detec_range(x[i]);
            if(l(pr) != -1) a[++nUsed] = pr;
        }
        for(ll i = 1; i <= m; i++) cin >> p[i];
        sort(p+1, p+m+1);
        nDeal = 0;
        for(ll i = 1; i <= nUsed; i++) {
            ll lb = lower_bound(p+1, p+m+1, l(a[i]))-p;
            ll ub = upper_bound(p+1, p+m+1, r(a[i]))-p-1;
            if(lb <= ub) b[++nDeal] = (carr){nDeal, make_pair(lb, ub)};
        }
        cout << nDeal << ' ';
        if(m <= 20) Sub1_2::solve();
        else {
            sort(b+1, b+nDeal+1, cmp_b);
            bool allaccel = true;
            for(ll i = 1; i <= nDeal; i++) allaccel &= (r(b[i].r) == m);
            if(allaccel) cout << m-1 << endl; // Sub3_6
            else {
                if(m <= 3000) Subbrute::solve();
                else Solution::solve();
            }
        }
        // vector<tag> tags;
        // for(ll i = 1; i <= nDeal; i++) {
        //     tags.push_back((tag){l(b[i].r), 1});
        //     tags.push_back((tag){r(b[i].r)+1, -1});
        //     // tags.push_back((tag){l(b[i].r), 1, h1[b[i].id], h2[b[i].id], h3[b[i].id], h4[b[i].id]});
        //     // tags.push_back((tag){r(b[i].r), -1, h1[b[i].id], h2[b[i].id], h3[b[i].id], h4[b[i].id]});
        // }
        // for(ll i = 1; i <= m; i++) {
        //     tags.push_back((tag){i, -2});
        // }
        // sort(tags.begin(), tags.end(), cmp_tag);
        // ll ctg = 0, canrmv = 0, nAsc = 0, nDec = 0;
        // ll sincelast = 0;
        // bool ascending = true, descending = false;
        // ll prevadd = 0, prevsub = 0;
        // for(ll i = 0; i < tags.size(); i++) {
        //     tag tg = tags[i];
        //     if(tg.op == -2) {
        //         // if(ctg == 0) {
        //         //     canrmv++;
        //         //     continue;
        //         // }
        //         if(prevadd > 0 && prevsub > 0) {
        //             canrmv += sincelast-1;
        //             ascending = true;
        //             descending = false;
        //             sincelast = 0;
        //         }
        //         else if(prevsub > 0 && ascending) {
        //             canrmv += sincelast-1;
        //             ascending = false;
        //             descending = true;
        //             sincelast = 0;
        //         }
        //         sincelast++;
        //         if(prevadd > 0 && descending) {
        //             canrmv += sincelast-1;
        //             ascending = true;
        //             descending = false;
        //             sincelast = 0;
        //         }
        //         prevadd = prevsub = 0;
        //     }
        //     ctg += tg.op;
        //     if(tg.op == 1) {
        //         prevadd++;
        //         // if(descending) {
        //         //     descending = false;
        //         //     ascending = true;
        //         //     cout << tg.p << ' ' << sincelast << endl;
        //         //     canrmv += sincelast-1;
        //         //     sincelast = 0;
        //         // }
        //     }
        //     if(tg.op == -1) {
        //         prevsub++;
        //         // if(ascending) {
        //         //     ascending = false;
        //         //     descending = true;
        //         //     cout << tg.p << ' ' << sincelast << endl;
        //         //     canrmv += sincelast-1;
        //         //     sincelast = 0;
        //         // }
        //     }
        // }
        // cout << canrmv << endl;
    }
    return 0;
}