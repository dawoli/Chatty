#include<bits/stdc++.h>
using namespace std;

template<typename T>
void read(T &a){
    char c;a=0;int f=1;
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
namespace MARISA{
int n;
const int MAXN=200010;
int a[MAXN];
int b[MAXN];
ll c[MAXN];
int lsh[MAXN],l_cnt;
int w(int i,int j){
    return c[j]-c[i];
}
int f(int a,int b){
    return a==b?a:0;
}
ll dp[MAXN];
ll dat[MAXN<<2];
const ll INF=2000000000000000000;
// void build(int p,int L,int R){
//     dat[p]=-INF;
//     if(L==R)return;
//     int mid=L+R>>1;
//     build(p<<1,L,mid);
//     build(p<<1|1,mid+1,R);
// }
// void upd(int p,int L,int R,int x,ll v){
//     dat[p]=max(dat[p],v);
//     if(L==R){
//         return;
//     }
//     int mid=L+R>>1;
//     if(x<=mid)upd(p<<1,L,mid,x,v);
//     else upd(p<<1|1,mid+1,R,x,v);
// }
// ll qry(int p,int L,int R,int l,int r){
//     if(l>r)return -INF;
//     if(l<=L&&R<=r)
//         return dat[p];
//     int mid=L+R>>1;
//     ll ans=-INF;
//     if(l<=mid)ans=max(ans,qry(p<<1,L,mid,l,r));
//     if(r>mid)ans=max(ans,qry(p<<1|1,mid+1,R,l,r));
//     return ans;
// }

void main(){
    read(n);
    for(int i=1;i<=n;++i){
        read(a[i]);lsh[i]=a[i];
        if(i>1)b[i]=a[i-1]==a[i]?a[i]:0;
        c[i]=c[i-1]+b[i];
    }
    l_cnt=n;sort(lsh+1,lsh+l_cnt+1);
    l_cnt=unique(lsh+1,lsh+l_cnt+1)-lsh-1;
    for(int i=1;i<=n;++i)a[i]=lower_bound(lsh+1,lsh+l_cnt+1,a[i])-lsh;
    a[0]=a[n+1]=0;
    dp[0]=0;
    // build(1,0,l_cnt);
    for(int i=0;i<=l_cnt;++i)dat[i]=-INF;
    dat[0]=dp[0]-c[0+1];
    ll mxdat=dat[0];
    for(int i=1;i<=n;++i){
        dp[i]=max(mxdat,dat[a[i+1]]+lsh[a[i+1]]);
        dp[i]+=c[i];
        dat[a[i]]=dp[i]-c[i+1];
        mxdat=max(mxdat,dat[a[i]]);
    }
    printf("%lld\n",dp[n]);
}
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;read(T);
    while(T--)MARISA::main();
    return 0;
}