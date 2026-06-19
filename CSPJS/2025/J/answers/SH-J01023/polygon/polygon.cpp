#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int MAXM=5005;
const int mod=998244353;
int n;
int a[MAXN];
long long ans=0;
long long dp[MAXM];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int hi=a[n]+1;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=hi;j>=0;j--){
            if(j>a[i]){
                ans=(ans+dp[j])%mod;
            }
            int nj=min(hi,j+a[i]);
            dp[nj]=(dp[nj]+dp[j])%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}
