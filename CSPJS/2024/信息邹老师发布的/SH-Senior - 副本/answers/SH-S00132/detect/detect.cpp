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
int T;
namespace SANAE{
int n,m,L,V;
const int MAXN=100010,MAXL=1000010;
typedef long double ld;
struct Car{
    int d,v,a;
}a[MAXN];
int sp[MAXL],p[MAXN];
int spdL,spdR;//超速区间
void calc(int d,int v,int a){
    if(a==0){
        if(v>V){
            spdL=d;
            spdR=L;
        }else{
            spdL=1;
            spdR=0;
        }
    }else if(a>0){
        if(v>V){
            spdL=d;
            spdR=L;
        }else{
            spdL=d+((ll)V*V-(ll)v*v)/(2ll*a)+1;//左开
            spdR=L;
        }
    }else{
        if(v<=V){
            spdL=1;
            spdR=0;
        }else{
            spdL=d;
            // printf("%.26lf %.26lf\n",d+((ld)V*V-(ld)v*v)/a/2,d+((ld)V*V-(ld)v*v)/a/2-EPS);
            if(L*(-2ll*a)<=d*(-2ll*a)+((ll)v*v-(ll)V*V)){
                spdR=L;
            }else if(((ll)v*v-(ll)V*V)%(-2ll*a)==0){
                spdR=d+((ll)v*v-(ll)V*V)/(-2ll*a)-1;//右开
            }else{
                spdR=d+((ll)v*v-(ll)V*V)/(-2ll*a);//右开
            }
        }
    }
}
bool chao[MAXN];//被记录的可能
struct Interval{
    int l,r;
    bool operator < (Interval B){
        if(l!=B.l)return l<B.l;
        return r<B.r;
    }
}b[MAXN];int cnt;
void main(){
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;++i){
        read(a[i].d);
        read(a[i].v);
        read(a[i].a);
    }
    for(int i=0;i<=L;++i)sp[i]=0;
    for(int i=1;i<=m;++i){
        read(p[i]);
        sp[p[i]]++;
    }
    for(int i=1;i<=L;++i)sp[i]+=sp[i-1];
    int ans1=0,ans2=0;
    cnt=0;
    for(int i=1;i<=n;++i){
        calc(a[i].d,a[i].v,a[i].a);
        int L=spdL,R=spdR;
        // printf("? %d %d\n",L,R);
        chao[i]=L<=R&&sp[R]-(L-1<0?0:sp[L-1])>0;
        ans1+=chao[i];
        if(chao[i]){
            ++cnt;
            assert(L>=0&&R>=0);
            b[cnt].l=spdL;
            b[cnt].r=spdR;
        }
    }
    sort(b+1,b+cnt+1);
    int ptr=1;//pointer of interval
    int mnr=2000000;
    for(int i=1;i<=m;++i){
        while(ptr<=cnt&&b[ptr].l<=p[i]){
            mnr=min(mnr,b[ptr].r);
            ptr++;
        }
        if(mnr==2000000){
            ans2++;
            continue;
        }
        if(i<m&&p[i+1]<=mnr){
            ans2++;
            continue;
        }
        mnr=2000000;
    }
    printf("%d %d\n",ans1,ans2);
}
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)SANAE::main();
    // cerr<<(double)clock()/CLOCKS_PER_SEC;
    return 0;
}