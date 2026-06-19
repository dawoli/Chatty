#include<bits/stdc++.h>
using namespace std;
int n,m,K,c[205000],d[18][205000],val[18][205000],T;
int aa[205000],a[205000],X[4];
char st[205000];
int kmin[205000];
int main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    kmin[0]=kmin[1]=0;
    for (int i=2;i<=200000;i++) {
        if ((1<<kmin[i-1])<i) kmin[i]=kmin[i-1]+1;
        else kmin[i]=kmin[i-1];
    }
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&aa[i]);
    }
    for (int i=1;i<=m;i++) {
        scanf("%d",&c[i]);
    }
    K=kmin[n];
    for (int i=1;i<=K;i++) {
        scanf("%s",st);
        assert(strlen(st)==(1<<(K-i)));
        for (int j=0;j<(1<<(K-i));j++) {
            if (st[j]=='0') d[i][j]=0;
            else d[i][j]=1;
        }
    }
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d",&X[0],&X[1],&X[2],&X[3]);
        for (int i=1;i<=n;i++) {
            a[i-1]=aa[i]^X[i%4];
        }
        for (int j=0;j<(1<<K);j++) val[0][j]=j;
        for (int i=1;i<=K;i++) {
            for (int j=0;j<(1<<(K-i));j++) {
                if (d[i][j]) {
                    if (a[val[i-1][(j<<1)+1]]>=i) {
                        val[i][j]=val[i-1][(j<<1)+1];
                    } else {
                        val[i][j]=val[i-1][(j<<1)];
                    }
                } else {
                    if (a[val[i-1][(j<<1)]]>=i) {
                        val[i][j]=val[i-1][(j<<1)];
                    } else {
                        val[i][j]=val[i-1][(j<<1)+1];
                    }
                }
            }
        }
        long long ans=0;
        for (int i=1;i<=m;i++) {
            ans^=(1ll*i*(val[kmin[c[i]]][0]+1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
