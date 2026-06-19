#include<bits/stdc++.h>
using namespace std;
const int N=509;
long long n,m,p,ans,a[N],b[N],c[N][N],d[N],e[N],g[N];
int f[N][N][N];
char s[N];
const long long mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    c[0][0]=1;
    g[0]=1;
    for(int i=1;i<=n;i++){
        g[i]=g[i-1]*i%mod;
        c[i][i]=c[i][0]=1;
        for(int j=1;j<i;j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    scanf("%s",s+1);
    p=n-m;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        b[a[i]]++;
        if(s[i]=='0')d[i]=d[i-1]+1;
        else d[i]=d[i-1];
    }
    e[0]=b[0];
    for(int i=1;i<=n;i++){
        e[i]=e[i-1]+b[i];
    }
    f[0][0][b[0]]=1;
    for(int i=0;i<n;i++){
        if(s[i+1]=='0'){
            for(int j=0;j+d[i]<=i;j++){
                for(int k=0;k<=e[j+d[i]];k++){
                    if(!f[i][j][k])continue;
                    for(int l=0;l<=b[j+d[i]+1];l++){
                        f[i+1][j][k+b[j+d[i]+1]-l]=((long long)f[i+1][j][k+b[j+d[i]+1]-l]+f[i][j][k]*c[i+k+1-e[j+d[i]]][l]%mod*c[k+b[j+d[i]+1]-l][k])%mod;
                        if(k)f[i+1][j][k+b[j+d[i]+1]-l-1]=((long long)f[i+1][j][k+b[j+d[i]+1]-l-1]+f[i][j][k]*c[i+k-e[j+d[i]]][l]%mod*c[k+b[j+d[i]+1]-l-1][k-1])%mod;
                    }
                }
            }
        }
        else{
            for(int j=0;j+d[i]<=i;j++){
                for(int k=0;k<=e[j+d[i]];k++){
                    if(!f[i][j][k])continue;
                    f[i][j][k]%=mod;
                    f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k])%mod;
                    if(k){
                        for(int l=0;l<=b[j+d[i]+1];l++){
                            f[i+1][j+1][k+b[j+d[i]+1]-l-1]=((long long)f[i+1][j+1][k+b[j+d[i]+1]-l-1]+f[i][j][k]*c[i+k-e[j+d[i]]][l]%mod*c[k+b[j+d[i]+1]-l-1][k-1])%mod;
                        }
                    }
                }
            }
        }
    }
    for(int j=0;j+d[n]<=p;j++){
        long long tt=f[n][j][0]%mod,mm=n-e[j+d[n]];
        for(int k=j+d[n]+1;k<=n;k++){
            tt=tt*c[mm][b[k]]%mod;
            mm-=b[k];
        }
        ans+=tt;
    }
    ans%=mod;
    for(int i=0;i<=n;i++)ans=ans*g[b[i]]%mod;
    printf("%lld\n",ans);
    return 0;
}
