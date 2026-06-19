#include<bits/stdc++.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define ll long long
#define mod 998244353
int read(){
    int x=0;
    bool neg=0;
    char ch=gc();
    while(ch<'0'||ch>'9')
        neg|=(ch=='-'),
        ch=gc();
    while(ch>='0'&&ch<='9')
        x=x*10+(ch^48),
        ch=gc();
    return neg?-x:x; //             -2147483648 bug
}
const int LMT=505;
int dp[2][LMT][LMT],fct[LMT];
int n,m,nw;
bool s[LMT];
int cnt[LMT];
void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read();m=read();
    char ch=gc();
    while(ch<'0'||ch>'1')ch=gc();
    for(int i=1;i<=n;i++){
        s[i]=ch-'0';
        ch=gc();
    }
    fct[0]=1;
    for(int i=1;i<=n;i++)
        fct[i]=fct[i-1]*(1ll*i)%mod;
    for(int i=1;i<=n;i++)
        cnt[read()]++;
    for(int i=n-m+2;i<=n;i++)
        cnt[n-m+1]+=cnt[i];
    nw=1;
    for(int i=m;i<=n;i++)
        dp[nw][i][cnt[n-m+1]]=1;
    for(int i=n-1;i>=0;i--){
        nw^=1;
        memset(dp[nw],0,sizeof(dp[nw]));
        for(int j=0;j<=m;j++)
            for(int k=0;k<=n;k++){
                if(s[i+1]&&j&&k)
                    add(dp[nw][j-1][k-1],dp[nw^1][j][k]*1ll*k%mod);
                add(dp[nw][j][k+cnt[i-j+1]],dp[nw^1][j][k]);
            }
    }
    ll ans=0;
    for(int i=0;i<=n;i++)
        ans+=dp[nw][0][i]*fct[i]%mod;
    printf("%lld\n",ans%mod);
    return 0;
}