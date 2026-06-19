#include <stdio.h>
#include <algorithm>
#include <vector>
const int MAXN=5e5+10;
const int mod=998244353;
int n;
int a[MAXN];
int dp[MAXN];
int ans[MAXN];
void solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    std::sort(a+1,a+n+1);
    std::vector<int> sum;
    sum.push_back(a[1]);
    dp[1]=0;
    for (int i=2;i<=n;++i){
        // a[i]-a[i-1]
        int il=0;
        for (int j=0;j<sum.size();++j){
            if (sum[j]<=a[i]) ++il;
            sum[j]+=a[i];
        }
        sum.push_back(a[i]);
        dp[i]=dp[i-1]+il;
        ans[i]=((1<<(i-1))-dp[i]-1+mod)%mod;
    }
    int anns=0;
    for (int i=1;i<=n;++i){
        anns+=ans[i];
        printf("%d ",dp[i]);
        anns%=mod;
    }
    printf("%d",anns);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
