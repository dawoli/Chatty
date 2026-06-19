#include<iostream>
#include<map>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int dp[MAXN];
map<int,int> mp;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
    }
    dp[0]=0;
    mp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        if(mp.count(a[i]^k)){
            dp[i]=dp[mp[a[i]^k]]+1;
        }
        dp[i]=max(dp[i],dp[i-1]);
        mp[a[i]]=i;
    }
    printf("%d",dp[n]);
    return 0;
}
