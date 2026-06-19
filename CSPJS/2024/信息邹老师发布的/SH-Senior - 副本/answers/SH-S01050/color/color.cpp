#include<bits/stdc++.h>
using namespace std;
int T,n,A[205000],maxA,g[205000];
long long f[1050000],maxt=0ll,tmpnxt=0ll;
//g[i]=A[i]*(A[i]==A[i-1])
//dp[i,j]:last different color from A[i] is A[j]
//dp[i,j]=dp[i-1,j]+g[i]
//dp[i,A[i-1]]=max(dp[i-1,k],dp[i-1,A[i]]+A[i])
//f[i,j]=dp[i,j]-{k,1,i}g[k]:
//f[i,j]=f[i-1,j]
//f[i,A[i-1]]=max(f[i-1,k]-g[i],f[i-1,A[i]]+A[i]-g[i])
int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&A[i]);
        A[0]=0;maxA=0;
        for (int i=1;i<=n;i++) {
            if (A[i]==A[i-1]) g[i]=A[i];
            else g[i]=0;
            maxA=max(maxA,A[i]);
        }
        for (int i=0;i<=maxA;i++) f[i]=-1234567890123456ll;
        f[0]=0ll;maxt=0ll;
        for (int i=2;i<=n;i++) {
            tmpnxt=max(maxt-g[i],f[A[i]]+1ll*A[i]-1ll*g[i]);
            assert(tmpnxt>=f[A[i-1]]);
            f[A[i-1]]=tmpnxt;
            maxt=max(maxt,tmpnxt);
        }
        for (int i=1;i<=n;i++) maxt+=1ll*g[i];
        printf("%lld\n",maxt);
    }
    return 0;
}
