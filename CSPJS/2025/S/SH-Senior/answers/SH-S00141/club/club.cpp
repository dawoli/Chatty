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
ll n;
const int MAXN=100010;
ll a[MAXN][3];
ll b[MAXN];
void main(){
    read(n);
    ll ans=0;
    ll cnt[3]={0,0,0};
    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j)
            read(a[i][j]);
        pair<ll,ll> tmp={a[i][0],0};
        tmp=max(tmp,{a[i][1],1});
        tmp=max(tmp,{a[i][2],2});
        ans+=tmp.first;
        cnt[b[i]=tmp.second]++;
    }
    int p=-1;
    for(int i=0;i<3;++i)
        if(cnt[i]>n/2)
            p=i;
    if(p!=-1){
        vector<ll> v;
        for(int i=1;i<=n;++i)
            if(b[i]==p){
                int mn=min(a[i][p]-a[i][(p+1)%3],a[i][p]-a[i][(p+2)%3]);
                v.emplace_back(mn);
            }
        sort(v.begin(),v.end());
        for(int i=0;i<cnt[p]-n/2;++i)
            ans-=v[i];
    }
    printf("%lld\n",ans);
}
}
bool ed_M;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=1;cin>>T;
    while(T--)GSK::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    // cerr<<(&ed_M-&be_M)/1024.0/1024.0<<" MB"<<endl;
    return 0;
}