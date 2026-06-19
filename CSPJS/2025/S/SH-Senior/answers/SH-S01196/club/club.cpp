#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
char buf[1048577],*p1,*p2;
#define gc() p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p2==p1)?EOF:*p1++
void rd(int &x){
    x=0; char c=gc();
    while(!isdigit(c)) c=gc();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=gc();
}
const int N=1e5+9;
int n,a[N][3],b[N];
int d[N];
void solve(){
    rd(n);
    int c[3]={0,0,0};
    LL res=0;
    for(int i=1;i<=n;i++){
        rd(a[i][0]),rd(a[i][1]),rd(a[i][2]);
        b[i]=max_element(a[i],a[i]+3)-a[i];
        c[b[i]]++;
        res+=a[i][b[i]];
    }
    // printf("b: "); for(int i=1;i<=n;i++) printf("%d",b[i]); puts("");
    int mx=max_element(c,c+3)-c;
    if(c[mx]<=n/2) return printf("%lld\n",res),void();
    int m=0;
    for(int i=1;i<=n;i++) if(b[i]==mx){
        if(!mx) d[++m]=a[i][0]-max(a[i][1],a[i][2]);
        else if(mx==1) d[++m]=a[i][1]-max(a[i][0],a[i][2]);
        else d[++m]=a[i][2]-max(a[i][0],a[i][1]);
    }
    // printf("d: "); for(int i=1;i<=m;i++) printf("%d ",d[i]); puts("");
    int tmp=c[mx]-n/2;
    sort(d+1,d+1+m);
    for(int i=1;i<=tmp;i++) res-=d[i];
    printf("%lld\n",res);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; rd(T);
    while(T--) solve();
    return 0;
}