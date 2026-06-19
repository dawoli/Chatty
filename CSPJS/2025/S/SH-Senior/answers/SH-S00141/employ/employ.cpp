#include <bits/stdc++.h>
using namespace std;

bool be_M;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
template<typename T>
void read(T &a){
    a=0;char c;int f=1;
    while(!isdigit(c=getchar()))if(c=='-')f=-1;
    do a=a*10+c-'0';
    while(isdigit(c=getchar()));
    a*=f;
}
template<typename T>
void write(T a){
    if(a<0)putchar('-'),a=-a;
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
typedef long long ll;
namespace GSK{
int n,m;
const int MAXN=510;
const int P=998244353;
char s[MAXN];
int c[MAXN];
ll dp[(1<<18)+20][20];
void madd(ll &x,ll y){x=(x+y)%P;}
void main(){
    read(n),read(m);
    scanf("%s",s+1);
    for(int i=0;i<n;++i)read(c[i]);
    dp[0][0]=1;
    for(int i=1;i<1<<n;++i){
        int sz=__builtin_popcount(i);
        for(int k=0;k<n;++k)if(i>>k&1){
            int ii=i^(1<<k);
            for(int j=0;j<=sz;++j){
                int fail=s[sz]=='0'||j>=c[k];
                madd(dp[i][j+fail],dp[ii][j]);
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n-m;++i)ans=(ans+dp[(1<<n)-1][i])%P;
    printf("%lld\n",ans);
}
}
bool ed_M;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)GSK::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&be_M)/1024.0/1024.0<<" MB"<<endl;
    return 0;
}