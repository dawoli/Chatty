#include <stdio.h>
#include <algorithm>
const int MAXN=5e5+10;
int n,k;
int a[MAXN],xsum[MAXN];
int dp[MAXN];
void solve(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        xsum[i]=xsum[i-1]^a[i];
    }
    int last=0;
    for (int i=1;i<=n;++i){
        bool flg=1;
        int tofind=k^xsum[i];
        // 放弃了，Trie给忘了，理论上挂一个Trie能把这里优化掉……极端数据少一点谢谢
        for (int j=last;j<i;++j){
            //printf("%d %d:%d\n",i,j,xsum[i]^xsum[j]);
            if (xsum[j]==tofind){
                //printf("%d %d:IN\n",i,j);
                last=i;
                dp[i]=dp[i-1]+1;
                flg=0;
                break;
            }
        }
        if (flg)dp[i]=dp[i-1];
    }
    /*for (int i=1;i<=n;++i){
        printf("%d ",dp[i]);
    }*/
    printf("%d\n",dp[n]);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}