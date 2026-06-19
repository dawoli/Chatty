#include<bits/stdc++.h>
using namespace std;
const int N=510,M=25,K=2.7e5+10,Mod=998244353; char s[N]; int c[N],dp[K][M];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int n,m; cin>>n>>m>>(s+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=18) {
        dp[0][0]=1;
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<=__builtin_popcount(i);j++)
                for(int k=1;k<=n;k++) {
                    if((i>>(k-1))&1) continue;
                    if(j>=c[k]||s[__builtin_popcount(i)+1]=='0') (dp[i|(1<<(k-1))][j+1]+=dp[i][j])%=Mod;
                    else (dp[i|(1<<(k-1))][j]+=dp[i][j])%=Mod;
                }
        int ans=0;
        for(int i=0;i<=n-m;i++) (ans+=dp[(1<<n)-1][i])%=Mod;
        cout<<ans;
        return 0;
    }
    long long ans=1;
    for(int i=1;i<=n;i++) ans=ans*i%Mod;
    cout<<ans;
    return 0;
}
