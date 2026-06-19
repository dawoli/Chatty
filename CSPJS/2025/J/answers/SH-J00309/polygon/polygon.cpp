#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar_unlocked();
    int f=0;
    while(!isdigit(c))c=getchar_unlocked();
    while(isdigit(c))f=f*10+c-'0',c=getchar_unlocked();
    return f;
}
const int mod=998244353;
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int a[5005];
long long dp[10005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n=read();
    int totmaxn=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        totmaxn=max(totmaxn,a[i]);
    }
    if(n<=20){
        int lim=1<<n;
        int ans=0;
        for(int i=0;i<lim;i++){
            if(__builtin_popcount(i)<3)continue;
            int tmp=i;
            int maxn=0;
            int sum=0;
            for(int i=1;i<=n;i++){
                if(tmp&1){
                    maxn=max(maxn,a[i]);
                    sum+=a[i];
                }
                tmp>>=1;
            }
            if(sum>2*maxn)ans++;
        }
        printf("%d\n",ans);
    }/*
    else if(totmaxn<=1){
        long long ans=0;
        ans=qpow(2,n)-n*(n-1)/2-n-1;
        ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }*/
    else{
        long long ans=0;
        sort(a+1,a+n+1);
        //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=5001;j>=0;j--){
                if(j>a[i])ans=(ans+dp[j])%mod;
                if(j+a[i]>5000)dp[5001]=(dp[5001]+dp[j])%mod;
                else dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
            }
        }
        /*dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1000;j>=0;j--){
                if(j+a[i]>2*a[i])ans+=dp[j];
                dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
            }
        }
        for(int i=1;i<=1000;i++)cout<<i<<" "<<dp[i]<<endl;*/
        printf("%lld\n",ans);
    }
    return 0;
}
//g++ -O2 -std=c++14 -static -Wall polygon.cpp -o polygon
//g++ -O2 -std=c++14 -static -Wall polygon.cpp -o polygon && ./polygon