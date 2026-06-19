#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[100010],aa[100010],k,c[100010],t,x[4],w[20][100010],f[100010][20],num,kk;
long long ans,cnt;
bool d[20][70000];
char C;
int main() {
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>aa[i],w[0][i]=i;
    for (int i=1;i<=m;i++) cin>>c[i];
    k=ceil(log2(n));
    for (int i=1;i<=k;i++) for (int j=1;j<=(1<<k-i);j++) cin>>C,d[i][j]=C-48;
    for (int i=1;i<=n;i++) for (int j=1,l=i;j<=k;j++,l=(l+1)/2) if ((d[j][(l+1)/2]+l)&1) f[i][j]=max(f[i][j-1],j);
    cin>>t;
    while (t--) {
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for (int i=1;i<=n;i++) a[i]=aa[i]^x[i%4];
        for (int i=1,l=n>>1;i<=k;i++,l>>=1) for (int j=1;j<=l;j++) w[i][j]=(a[w[i-1][j*2+d[i][j]-1]]>=i?w[i-1][j*2+d[i][j]-1]:w[i-1][j*2-d[i][j]]);
        ans=0;
        for (int i=1;i<=m;i++) {
            num=c[i];
            cnt=0;
            kk=ceil(log2(c[i]));
            for (int l=c[i],i=1;i<=kk;i++,l>>=1) {
                if ((l&1)&&a[w[i-1][l]]>=i&&d[i][l/2+1]==0) num=(l/2+1)*(1<<i),cnt=0;
                if ((l&1)&&a[w[i-1][l]]>=f[w[i-1][l]][kk]) cnt+=w[i-1][l]; 
            }
            ans^=i*(cnt+1ll*((1<<kk)+num+1)*((1<<kk)-num)/2);
            if (c[i]==(1<<kk)) ans^=1ll*i*w[int(log2(c[i]))][1];
        }
        cout<<ans<<endl;
    }
}