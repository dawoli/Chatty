#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
ll n,m,c[510];
char s[510];

void solve1(){
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            cout<<0<<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0){
            cout<<0<<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++)
        ans=(ans*i)%MOD;
    cout<<ans<<endl;
}

ll dp[300010][25];

void solve2(){
    dp[0][0]=1;
    ll ans=0;
    for(int i=0;i<(1<<n);i++){
        ll dt=__builtin_popcount(i)+1;
        for(int cnt=0;cnt<=n;cnt++){
            for(int j=1;j<=n;j++){
                if(((i>>(j-1))&1)==0){
                    ll nxtmsk=i^(1<<(j-1));
                    if(cnt>=c[j]||s[dt]=='0')
                        dp[nxtmsk][cnt+1]=(dp[nxtmsk][cnt+1]+dp[i][cnt])%MOD;
                    else dp[nxtmsk][cnt]=(dp[nxtmsk][cnt]+dp[i][cnt])%MOD;
                }
            }
        }
    }
    for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i]);
    cout<<ans<<endl;
}

void solve(){
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    if(m==n) solve1();
    else solve2();
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll T;T=1;while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
