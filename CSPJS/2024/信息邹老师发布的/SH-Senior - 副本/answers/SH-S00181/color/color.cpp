#include <bits/stdc++.h>
#define INF 1000000000000000000ll
#define N 200005
#define M 1000006
#define ls(u) tr[u].ls
#define rs(u) tr[u].rs
using namespace std;
typedef long long ll;

int T, n, m, a[N];

struct Seg { int ls, rs; ll tg, mx; } tr[M*2];
int rt, tot;

void buildST (int &u, int l, int r)
{
    if (!u) { u=++tot; }
    if (l==r) { tr[u].mx=(l==0 ? 0 : -INF); return; }
    int md=(l+r)>>1;
    buildST(ls(u), l, md);
    buildST(rs(u), md+1, r);
    tr[u].mx=max(tr[ls(u)].mx, tr[rs(u)].mx);
}
void pushdown (int u)
{
    if (tr[u].tg==0) { return; }
    ll tg=tr[u].tg; tr[u].tg=0;
    tr[ls(u)].tg+=tg; tr[ls(u)].mx+=tg;
    tr[rs(u)].tg+=tg; tr[rs(u)].mx+=tg;
}
ll qry (int u, int l, int r, int id)
{
    if (l==r) { return tr[u].mx; }
    pushdown(u);
    int md=(l+r)>>1;
    if (id<=md) { return qry(ls(u), l, md, id); }
    else { return qry(rs(u), md+1, r, id); }
}
void upd (int u, int l, int r, int id, ll num)
{
    if (l==r) { tr[u].mx=max(tr[u].mx, num); return; }
    pushdown(u);
    int md=(l+r)>>1;
    if (id<=md) { upd(ls(u), l, md, id, num); }
    else { upd(rs(u), md+1, r, id, num); }
    tr[u].mx=max(tr[ls(u)].mx, tr[rs(u)].mx);
}

void clr ()
{
    for (int i=1; i<=tot; i++) { tr[i]=(Seg){ 0, 0, 0, 0 }; }
    m=0; tot=0, rt=0;
}

int main ()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i=1; i<=n; i++) { scanf("%d", &a[i]); m=max(m, a[i]); }
        
        buildST(rt, 0, m);
        for (int i=2; i<=n; i++) {
            ll tmp=max(tr[rt].mx, qry(rt, 0, m, a[i])+a[i]);
            if (a[i]==a[i-1]) { tr[rt].tg+=a[i]; tr[rt].mx+=a[i]; }
            upd(rt, 0, m, a[i-1], tmp);
        }
        printf("%lld\n", tr[rt].mx);

        clr();
    }

    return 0;
}