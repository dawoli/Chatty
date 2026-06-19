#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;

int n, m, K, a[N], ap[N], c[N], X[5];
int son[N*4], prt[N*4];
struct Pnt { int ans; } p[N*4];

int T;
char s[N*4];

void dfs (int u)
{
    p[u].ans=0;
    if (u>(1<<K)-1) { return; }
    dfs(u*2); dfs(u*2+1);
}
void add (int u, int lv)
{
    if (u<1) { return; }
    if (u<=(1<<K)-1) {
        int cur=u*2+son[u];
        if (p[cur].ans==0) { p[u].ans=0; }
        else { p[u].ans=(a[p[cur].ans]>=lv ? p[cur].ans : p[u*2+(son[u]^1)].ans); }
    }
    else {
        p[u].ans=u-(1<<K)+1;
    }
    add(u/2, lv+1);
}

int main ()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) { scanf("%d", &ap[i]); }
    for (int i=1; i<=m; i++) { scanf("%d", &c[i]); }

    for (int k=0; k<=20; k++) if ((1<<k)>=n) { K=k; break; }
    for (int i=K-1; i>=0; i--) {
        scanf("%s", s+1);
        for (int j=(1<<i); j<(1<<(i+1)); j++) {
            son[j]=(s[j-(1<<i)+1]=='1');
        }
    }

    scanf("%d", &T);

    while (T--) {
        for (int i=0; i<4; i++) { scanf("%d", &X[i]); }
        for (int i=1; i<=n; i++) { a[i]=(ap[i]^X[i%4]); }

        dfs(1);

        for (int t=1; t<=n; t++) {
            int cur=0;
            for (int k=0; k<=20; k++) if ((1<<k)>=t) { cur=k; break; }
            int id=(1<<K)-1+(1<<cur);
            while (id!=1 && (id&1)) { id--; id>>=1; }

            add(t+(1<<K)-1, 0);

            // for (int i=1; i<(1<<(K+1)); i++) { cout<<p[i].ans<<" "; } cout<<endl;

            ll res=0;

            for (int i=1; i<=(1<<cur); i++) {
                int fa=((i+(1<<K)-1)/2), u=(i+(1<<K)-1);
                int lv=1;
                bool ok=1;
                while (fa>=id) {
                    if (p[fa].ans!=0 && p[fa].ans!=i) { ok=0; break; }
                    if (fa*2+son[fa]==u && i<=t && a[i]<lv) { ok=0; break; }

                    fa/=2; u/=2; lv++;
                }
                if (ok) { res+=i; }
            }

            prt[t]=res;
        }

        ll sum=0;
        for (int i=1; i<=m; i++) { sum^=((ll)i*(ll)prt[c[i]]); }

        printf("%lld\n", sum);
    }

    return 0;
}