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
int n;
const int MAXN=100010;
int a[MAXN],b[MAXN];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    read(n);
    for(int i=1;i<=n;++i)read(a[i]),b[a[i]]++;
    int ans=0;
    for(int i=1;i<=100000;++i){
        ans=max(0,ans-b[i]);
        ans+=b[i];
    }
    printf("%d\n",ans);
    // cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}