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
const int N=140000,M=1e6,U=(1<<20)-1;
int n,m,A[N],X[4],a[N],qu[N],K,T;
vector<int> info[20]; int pos[20]; char s[M];
int loggg[N];
namespace SJQ{
    int tr[N<<2],res[N];
    int get(int l,int r,int R){
        if(l==r) return r;
        int mid=l+r>>1;
        int x=get(l,mid,R+1),y=get(mid+1,r,R+1);
        int G=info[R][++pos[R]];
        if(G) swap(x,y);
        return a[x]>=R?x:y;
    }
    void solve(){
        for(int i=1;i<=n;i*=2){
            for(int j=0;j<20;j++) pos[j]=0;
            res[i]=get(1,i,1);
        }
        LL hsh=0;
        for(int i=1;i<=m;i++){
            int c=qu[i];
            hsh^=(LL)i*res[c];
        }
        printf("%lld\n",hsh);
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++) read(A[i]);
    while(1<<K<n) K++;
    for(int i=1;i<=131072;i*=2) loggg[i]=1;
    bool isA=1;
    for(int i=1;i<=m;i++) read(qu[i]),isA&=loggg[qu[i]];
    for(int R=1;R<=K;R++){
        int len=1<<K-R;
        info[R].resize(len+1);
        scanf("%s",s+1);
        for(int G=1;G<=len;G++) info[R][G]=s[G];
    }
    read(T);
    while(T--){
        for(int R=1;R<=K;R++) pos[R]=0;
        for(int i=0;i<4;i++) read(X[i]);
        for(int i=1;i<=n;i++) a[i]=A[i]^X[i&3];
        if(isA) SJQ::solve(); 
    }
    return 0;
}