#include<bits/stdc++.h>
#define mkp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
constexpr int N=(1<<18)+10;
constexpr int mod=998244353;
char s[N];
int n,m,c[N];
int dp[N][19];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n>18){
        int ans=1;
        for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
        for(int i=1;i<=n;i++) if(s[i]=='0'||c[i]==0) ans=0;
        cout<<ans<<"\n";
        return 0;
    }
    int lmt=(1<<n);
    dp[0][0]=1;
    for(int i=1;i<lmt;i++){
        for(int j=1;j<=n;j++){
            if(!(i>>(j-1)&1)) continue;
            int lst=i^(1<<(j-1));
            int popc=__builtin_popcount(lst);
            for(int k=0;k<=popc;k++){
                if(c[j]<=k||s[popc+1]=='0'){
                    (dp[i][k+1]+=dp[lst][k])%=mod;
                }
                else{
                    (dp[i][k]+=dp[lst][k])%=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n-m;i++) (ans+=dp[lmt-1][i])%=mod;
    cout<<ans<<"\n";
    return 0;
}