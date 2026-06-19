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
int n,m;
const int MAXN=100010;
int _a[MAXN],a[MAXN],c[MAXN];
int d[20][3010];
int lg[MAXN];
int num[MAXN<<2];
typedef long long ll;
namespace REIMU{
int ans[MAXN];
int dep_n(int n){
    n--;
    int k=0;
    while(n)n>>=1,k++;
    return k+1;
}
int dep;
int f[MAXN<<2];
ll g[MAXN<<2];
void pushup(int p){
    int rd=dep+1-(lg[p]+1)+1-1;
//    printf("%d %d %d\n",p,rd,d[p]);
    if(f[p<<1]==-1&&f[p<<1|1]==-1){
        // puts("1");
        f[p]=-1;
        g[p]=g[p<<1]+g[p<<1|1];
    }else if(f[p<<1]!=-1&&f[p<<1|1]!=-1){
        // puts("2");
        if(d[rd][num[p]]==0){
            if(f[p<<1]>=rd)f[p]=f[p<<1],g[p]=g[p<<1];
            else f[p]=f[p<<1|1],g[p]=g[p<<1|1];
        }else{
            if(f[p<<1|1]>=rd)f[p]=f[p<<1|1],g[p]=g[p<<1|1];
            else f[p]=f[p<<1],g[p]=g[p<<1];
        }
    }else if(f[p<<1]!=-1&&f[p<<1|1]==-1){
    //     puts("3");
        // if(d[p]==0){
        //     if(f[p<<1]>=rd)f[p]=f[p<<1],g[p]=g[p<<1];
        //     else f[p]=f[p<<1|1],g[p]=g[p<<1|1];
        // }else{

        // }
    }else{
        // puts("4");
        // if(d[p]==0){
        // }else{
        //     if(f[p<<1|1]>=rd)f[p]=f[p<<1|1],g[p]=g[p<<1|1];
        //     else f[p]=f[p<<1],g[p]=g[p<<1];
        // }
    }
}
void main(){
    int x[4];
    for(int i=0;i<4;++i)read(x[i]);
    for(int i=1;i<=n;++i)a[i]=_a[i]^x[i&3];
//    puts("dep");
    for(int i=1;i<=n;++i){
        dep=lg[i-1]+1;
    if(__builtin_popcount(i)>1)continue;
        for(int j=1<<dep;j<(1<<dep+1);++j){
            f[j]=j-(1<<dep)+1<=i?a[j-(1<<dep)+1]:-1;
            assert(j-(1<<dep)+1<=i);
            g[j]=j-(1<<dep)+1;
        }
        for(int i=(1<<dep)-1;i>=1;--i)pushup(i);
//    for(int i=1;i<(1<<dep+1);++i)printf("%d(%d,%d) ",f[i],g[i],dep+1-(lg[i]+1)+1-1);puts("");
        ans[i]=g[1];
    }
//    puts("ans");
//    for(int i=1;i<=n;++i)printf("%d ",ans[i]);
//    puts("");
    ll Ans=0;
    for(int i=1;i<=m;++i)Ans^=(ll)i*ans[c[i]];
    printf("%lld\n",Ans);
}
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    lg[0]=-1;lg[1]=0;for(int i=2;i<=100000;++i)lg[i]=lg[i>>1]+1;
    for(int i=1;i<=10;++i)printf("%d ",lg[i]);puts("");
    cin>>n>>m;
    for(int i=1;i<=n;++i)read(_a[i]);
    for(int i=1;i<=m;++i)read(c[i]);
    int dep=lg[n-1]+1;
    for(int i=dep;i>=1;--i){
        char ch;
        for(int j=1;j<=1<<i;++j){
            while(!isdigit(ch=getchar()));
            d[i][j]=ch-'0';
        }
        for(int j=1<<i-1;j<1<<i;++j){
            num[j]=(j-(1<<i-1)+1);
        }
    }
    // puts("fasd");
//    for(int i=1;i<1<<dep;++i)printf("%d",d[i]);puts("");
    // puts("fasd");
    int T;cin>>T;
    while(T--)REIMU::main();
    return 0;
}
