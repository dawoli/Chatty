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
const int N=2e5+9,M=1e6+9;
int n,a[N],las[N],pos[M];
LL f[N],sw[N];
void solve(){
    read(n);
    for(int i=1;i<=1000000;i++) pos[i]=0;
    LL mx=-1e18;
    for(int i=1;i<=n;i++){
        read(a[i]),sw[i]=sw[i-1]+(a[i]==a[i-1]?a[i]:0);
        las[i]=pos[a[i]],pos[a[i]]=i;
        f[i]=max(0LL,mx+sw[i-1]);
        if(las[i]&&las[i]<i-1) f[i]=max(f[i],f[las[i]+1]+max(0LL,sw[i-1]-sw[las[i]])+a[i]);
        // printf("%d %d %lld %lld %lld %lld\n",i,las[i],f[i],mx,sw[i],f[las[i]]+max(0LL,sw[i-1]-sw[las[i]+1])+a[i]);
        mx=max(mx,f[i]-sw[i]);
    }
    LL res=0;
    for(int i=0;i<=n;i++) res=max(res,f[i]+max(0LL,sw[n]-sw[i]));
    printf("%lld\n",res);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int SJQ; read(SJQ);
    while(SJQ--) solve();
    // cerr<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    return 0;
}