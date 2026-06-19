#include<ctime>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
void read(int &x){
    x=0; char c=getchar(); bool f=0;
    while(!isdigit(c)){if(c=='-') f=1;c=getchar();}
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
const int N=1e5+9,M=1e6+9;
int n,m,L,V,l[N],r[N],p[N];
int k;
struct Seg{
    int l,r;
    bool operator<(const Seg &W)const{
        return l<W.l;
    }
}seg[N];
void solve(){
    read(n),read(m),read(L),read(V);
    for(int i=1,d,v,a;i<=n;i++){
        l[i]=0,r[i]=-1;
        read(d),read(v),read(a);
        if(!a){
            if(v>V) l[i]=d,r[i]=L;
        }
        else if(a>0){
            if(v>V) l[i]=d,r[i]=L;
            else{
                l[i]=d+(V*V-v*v)/(2*a)+1,r[i]=L;
            }
        }
        else{
            if(v>V){
                a=-a;
                // printf("--%d %d\n",v*v-V*V+2*a-1,(v*v-V*V+2*a-1)/(2*a));
                l[i]=d,r[i]=d+(v*v-V*V+2*a-1)/(2*a)-1;
            }
        }
        // printf("%d %d\n",l[i],r[i]);
    }
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    k=0;
    for(int i=1;i<=n;i++) if(l[i]<=r[i]){
        int a=lower_bound(p+1,p+1+m,l[i])-p,b=upper_bound(p+1,p+1+m,r[i])-p-1;
        if(a<=b) seg[++k]={a,b};
    }
    sort(seg+1,seg+1+k);
    int res=0,las=-1;
    for(int i=1;i<=k;i++){
        if(las<seg[i].l) res++,las=seg[i].r;
        else las=min(las,seg[i].r);
    }
    printf("%d %d\n",k,m-res);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int SJQ; read(SJQ);
    while(SJQ--) solve();
    // cerr<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    return 0;
}