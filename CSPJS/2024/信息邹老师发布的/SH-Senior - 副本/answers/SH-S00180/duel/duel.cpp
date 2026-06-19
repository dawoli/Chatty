#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)
using namespace std;
bool Mbe;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch))x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
void write(ll x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const ll N=1e6+9;
ll n,a[N],vis[N];
bool Med;
int main(){
    cerr<<fabs(&Med-&Mbe)/1048576.0<<"MB\n";
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    n=read();
    rep(i,1,n)a[i]=read();
    sort(a+1,a+n+1,greater<ll>());
    ll ans=n,ptr=1;
    rep(i,1,n){
        while(ptr<=n&&a[ptr]>=a[i])ptr++;
        if(ptr<=n)ans--,ptr++;
    }
    write(ans);
    cerr<<"\n"<<clock()*1000./CLOCKS_PER_SEC<<"ms\n";
    return 0;
}