#include <bits/stdc++.h>
#define N 100005
#define M 100005
using namespace std;
typedef long long ll;

int T, n, m, L;
ll V;
struct Pnt { int d, v, a; } q[N];
ll p[M];
struct Qry
{
    int l, r;
    bool operator< (const Qry &x) const { return l<x.l || (l==x.l && r>x.r); }
} vec[N], vec2[N];

int main ()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %lld", &n, &m, &L, &V);
        for (int i=1; i<=n; i++) {
            int d, v, a; scanf("%d %d %d", &d, &v, &a);
            q[i]=(Pnt){ d, v, a };
        }
        for (int i=1; i<=m; i++) { scanf("%lld", &p[i]); }

        int tot=0, cnt=0;

        for (int i=1; i<=n; i++) {
            ll d=q[i].d, v=q[i].v, a=q[i].a;
            if (v<=V && a<=0) { continue; }
            if (v>V && a>=0) {
                int pos=lower_bound(p+1, p+m+1, d)-p;
                if (pos==m+1) { continue; }
                else { cnt++; vec[++tot]=(Qry){ pos, m }; continue; }
            }

            ll cur=V*V-v*v+2*a*d;
            
            if (a>0) {
                int l=1, r=m, res=m+1;
                while (l<=r) {
                    int md=(l+r)>>1;
                    if (2*a*p[md]>cur) { res=md; r=md-1; }
                    else { l=md+1; }
                }
                if (res!=m+1) {
                    cnt++;
                    vec[++tot]=(Qry){ res, m };
                }
            }
            else {
                int pos=lower_bound(p+1, p+m+1, d)-p;

                int l=1, r=m, res=0;
                while (l<=r) {
                    int md=(l+r)>>1;
                    if (2*a*p[md]>cur) { res=md; l=md+1; }
                    else { r=md-1; }
                }
                if (res!=0 && pos<=res) {
                    cnt++;
                    vec[++tot]=(Qry){ pos, res };
                }
            }
        }

        // for (int i=1; i<=tot; i++) {
        //     cout<<vec[i].l<<" "<<vec[i].r<<endl;
        // }

        sort(vec+1, vec+tot+1);
        int tot2=0, mnr=m+1;
        for (int i=tot; i>=1; i--) {
            if (vec[i].r>=mnr) { continue; }
            vec2[++tot2]=vec[i]; mnr=vec[i].r;
        }
        int ans=m, cur=0;
        for (int i=tot2; i>=1; i--) {
            if (i==tot2 || vec2[i].l>cur) { ans--; cur=vec2[i].r; }
        }
        printf("%d %d\n", cnt, ans);
    }

    return 0;
}