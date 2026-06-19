#include <bits/stdc++.h>
using namespace std;
int n,m,x,c[510],f[110][110][110],g[110][110][110],cb[110][110],icb[110][110],h[110][110][110],ans;
bool s[510];
char t;
const int mod=998244353;
int qp(int a,int b) {
    int ans=1;
    while (b) {
        if (b&1) ans=1ll*a*ans%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
void chmod(int &x,int y) {
    x+=y;
    if (x>=mod) x-=mod;
}
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) cin>>t,s[i]=t^48;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x) ++c[x-1];
    }
    for (int i=n;~i;--i) c[i]+=c[i+1];
    if (n<=100) {
        for (int i=0;i<=n;++i) {
            cb[i][0]=1;
            icb[i][0]=1;
            for (int j=1;j<=i;++j) {
                cb[i][j]=cb[i-1][j]+cb[i-1][j-1];
                if (cb[i][j]>=mod) cb[i][j]-=mod;
                icb[i][j]=qp(cb[i][j],mod-2);
            }
        }
        for (int i=0;i<n;++i) for (int j=0;j<=n;++j) for (int k=0;k<=j;++k) h[i][j][k]=1ll*cb[c[i+1]][k]*cb[c[i]-c[i+1]][j-k]%mod*icb[c[i]][j]%mod;
        f[0][0][c[0]]=1;
        for (int i=1;i<=n;++i) {
            for (int j=0;j<i;++j) {
                for (int k=0;k<=n-i+1;++k) if (s[i]==0) {
                    g[i][j+1][k]=(g[i][j+1][k]+f[i-1][j][k]*(n-i+1ll-k))%mod;
                    if (k) g[i][j+1][k-1]=(g[i][j+1][k-1]+1ll*f[i-1][j][k]*k)%mod;
                }
                else {
                    g[i][j+1][k]=(g[i][j+1][k]+f[i-1][j][k]*(n-i+1ll-k))%mod;
                    if (k) f[i][j][k-1]=(f[i][j][k-1]+1ll*f[i-1][j][k]*k)%mod;
                }
            }
            for (int j=1;j<=i;++j) for (int k=0;k<=n-i+1;++k) for (int l=0;l<=k;++l) f[i][j][l]=(f[i][j][l]+1ll*g[i][j][k]*h[j-1][k][l])%mod;
            //for (int j=0;j<=i;++j) for (int l=0;l<=n-i;++l) cout<<i<<' '<<j<<' '<<l<<' '<<f[i][j][l]<<endl;
        }
        for (int i=0;i<=n-m;++i) chmod(ans,f[n][i][0]);
        cout<<ans<<endl;
    }
    else if (m==n) {
        for (int i=1;i<=n;++i) if (s[i]==0) {
            cout<<"0\n";
            return 0;
        }
        if (c[0]<n) {
            cout<<"0\n";
            return 0;
        }
        ans=1;
        for (int i=1;i<=n;++i) ans=1ll*i*ans%mod;
        cout<<ans<<endl;
    }
}