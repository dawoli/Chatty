#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar_unlocked();
    int f=0;
    while(!isdigit(c))c=getchar_unlocked();
    while(isdigit(c))f=f*10+c-'0',c=getchar_unlocked();
    return f;
}
int a[500005];
int prexor[500005];
int prexork[500005];
set<int>s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        prexor[i]=prexor[i-1]^a[i];
        prexork[i]=prexor[i]^k;
    }
    //for(int i=1;i<=n;i++)cout<<prexor[i]<<" ";
    //cout<<endl;
    //for(int i=1;i<=n;i++)cout<<prexork[i]<<" ";
    int ans=0;
    for(int i=n;i>=0;i--){
        if(s.count(prexor[i])!=0){
            ans++;
            s.clear();
        }
        s.insert(prexork[i]);
    }
    printf("%d\n",ans);
    return 0;
}
//g++ -O2 -std=c++14 -static -Wall xor.cpp -o xor