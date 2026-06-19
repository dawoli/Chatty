#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f

const ll maxn=2e5+5;

ll a[maxn], dp[maxn];

ll read() {
    char c=getchar();
    while(!('0'<=c&&c<='9')) c=getchar();
    ll ans=0;
    while('0'<=c&&c<='9') {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans;
}

void print(ll x) {
    if(!x) {
        putchar('0'); putchar('\n');
        return ;
    }
    char buf[100];
    ll tot=0;
    while(x) {
        buf[++tot]=x%10+'0';
        x/=10;
    }
    for(ll i=tot;i>=1;i--)putchar(buf[i]);
    putchar('\n');
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll T;
    T=read();
    ll n;
    while(T--) {
        n=read();
        memset(dp,-inf,sizeof(dp));
        for(ll i=1;i<=n;i++) a[i]=read();
        ll t;
        ll mx=0;
        dp[0]=(a[1]==a[2]) ? a[1] : 0;
        dp[1]=0;
        for(ll i=3;i<=n;i++) {
            t=(a[i]==a[i-1]) ? a[i] : 0;
            for(ll j=1;j<=i-2;j++) {
                dp[i-1]=max(dp[i-1], dp[j]+ ( (a[i]==a[j])?a[i]:0) );
                dp[j]=dp[j]+t;
            }
        }
        for(int i=0;i<=n;i++) mx=max(mx, dp[i]);
        print(mx);
    }
    return 0;
}